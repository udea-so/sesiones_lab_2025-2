class Persona:
    def __init__(self):
        self.nombre = ""
        self.edad = 0

if __name__ == "__main__":
    p1 = Persona()

    p1.nombre = "Ana"
    p1.edad = 22

    print(f"Nombre: {p1.nombre}")
    print(f"Edad: {p1.edad}")