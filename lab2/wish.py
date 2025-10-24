#!/usr/bin/env python3
# wish.py: A simple shell implementation in Python

"""
- No esta implementado el modo batch.
- No esta implementado el redireccionamiento.
- No esta implementada la ejecucion de comandos en paralelo.
"""

import os
import sys

internal_commands = ["exit", "cd", "path"]
path = ["/bin", "/usr/bin", "."]
command_exist = False
flag_background = False

def execute_command(command_list):
    global command_exist
    global flag_background

    # Handle case where '&' is attached to the last command
    if command_list[-1] != "&" and command_list[-1].endswith("&"):
        token = command_list[-1][:-1]
        if token:  # si no era solo '&'
            command_list[-1] = token
            command_list.append("&")
        else:
            command_list[-1] = "&"

    # Check for background execution
    if command_list and command_list[-1] == "&":
        flag_background = True
        command_list = command_list[:-1]  # Remove '&' from command list
    else:
        flag_background = False

    # Empty command do nothing
    if not command_list:
        return

    # Reset command_exist for each new command
    command_exist = False
    
    # Run internal or external commands       
    if command_list[0] in internal_commands:
        # Internal commands: exit, cd, path
        if command_list[0] == "exit":
            # exit command
            print("Exiting wish shell.")
            sys.exit(0)
        elif command_list[0] == "cd":
            # cd command
            if len(command_list) != 2:
                print("cd: Missing argument")
            else:
                os.chdir(command_list[1])            
        elif command_list[0] == "path":
            # path command
            path.clear()
            path.extend(command_list[1:])
            command_exist = False
            print(f"Updated path: {path}")
    else:
        # External commands        
        for dir in path:                    
            command_path = dir + "/" + command_list[0]                                    
            if os.access(command_path, os.X_OK):
                command_list[0] = command_path
                command_exist = True
                break
        if command_exist == False:
            print(f"{command_list[0]}: Command not found")
        else:
            # Fork and execute the command              
            pid = os.fork()                              
            if pid == 0:
                # Child process
                print(f"Executing command: {command_list}")
                os.execvp(command_list[0], command_list)            
            else:
                # Parent process
                if not flag_background:
                    # Wait for the child process to finish
                    os.wait()
        
def main():
    if len(sys.argv) > 2:
        print("Usage: wish [batch_file]")
        sys.exit(1) 
    elif len(sys.argv) == 2:
        # Batch mode
        print("Batch mode not implemented in this version.")
        sys.exit(1)
    else:
        # Interactive mode
        while True:
            command = input("wish> ")
            command_list = [param.strip() for param in command.split()]
            # print(f"Command List: {command_list}")
            execute_command(command_list)

if __name__ == "__main__":
    main()