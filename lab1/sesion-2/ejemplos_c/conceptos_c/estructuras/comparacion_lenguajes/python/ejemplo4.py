class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

if __name__ == "__main__":
    # p1 es una referencia al nuevo objeto Persona
    p1 = Persona("Marta", 25)
    
    # ptr es otra referencia que apunta al MISMO objeto que p1
    ptr = p1

    # Se accede a los datos a través de la referencia con el operador "."
    print(f"Nombre: {ptr.nombre}")
    print(f"Edad: {ptr.edad}")