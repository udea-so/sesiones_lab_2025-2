# Definición de la clase
class Persona:
    def __init__(self):
        self.nombre = ""
        self.edad = 0

# Código principal
if __name__ == "__main__":
    # Declaración de una variable de tipo objeto
    p1 = Persona()

    # Asignación de valores
    p1.edad = 20
    print(f"Edad: {p1.edad}")