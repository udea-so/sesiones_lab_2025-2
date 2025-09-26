#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char cmd[101]; // 100 [caracteres] + 1 [NULL] 
int pid;
char path[] = "/bin/";
char full_cmd[151]; 
int cmd_tam;
int main(int argc, char *argv[]) {   
    if (argc != 1) {
        printf("Modo bash\n");
        // To Do...
        exit(0);  // Exit OK
    }
    else {
        // Modo terminal
        while (1) {
            printf("wish> ");
            fgets(cmd, 101, stdin);
            cmd_tam = strlen(cmd);
            cmd[cmd_tam - 1] = '\0'; // Sobreescribir enter
            // printf("%s %d %d\n\n", cmd, cmd_tam, strcmp(cmd,"hola"));
            if(strcmp(cmd,"hola") == 0) {
                // Comando externo (ejecutable hecho por el estudiante)
                pid = fork();
                if (pid == 0) {
                    // Hijo ejecuta esto                    
                    execl("./hola", "hola", NULL);
                } 
                else {
                    // Padre ejecuta esto
                    wait(NULL); // Padre espera que el hijo acabe   
                }
            }
            else if(strcmp(cmd,"exit") == 0) {
                // Comando interno
                exit(0); // Exit OK         
            }
            else if(strcmp(cmd,"cd") == 0) {
                // Interno
                // cd -> chdir()
                printf("Uso del cd...\n");                                
            }
            else {
                // Comando externo (De los disponibles en linux - Puede ser el que sea)
                pid = fork();
                switch (pid) {
                case 0:
                    // Hijo
                    strcat(full_cmd, path);
                    strcat(full_cmd,cmd);
                    execl(full_cmd, cmd, NULL);    
                    break;
                default:
                    // Padre
                    wait(NULL); // Padre espera que el hijo acabe
                    break;
                }  
            }
            // Vaciar el búfer para evitar problemas con el siguiente fgets
            while (getchar() != '\n');
        }
    }
}