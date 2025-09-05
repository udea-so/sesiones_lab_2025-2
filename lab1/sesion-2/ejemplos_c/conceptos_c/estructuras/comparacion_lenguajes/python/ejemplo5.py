class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

# La función recibe una referencia a un objeto Persona
def imprimir(p):
    # Se accede a los atributos con el operador punto "."
    print(f"{p.nombre} tiene {p.edad} años")


if __name__ == "__main__":
    p1 = Persona("Carlos", 28)

    # Se pasa la referencia del objeto a la función
    imprimir(p1)