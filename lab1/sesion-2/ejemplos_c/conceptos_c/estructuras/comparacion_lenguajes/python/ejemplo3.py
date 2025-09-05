class Persona:
    # El constructor ahora acepta argumentos para inicializar los atributos
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

if __name__ == "__main__":
    # Se inicializan los objetos pasando los valores al crearlos
    p1 = Persona("Luis Gomez", 30)
    p2 = Persona("Marta Peralta", 30)

    print(f"{p1.nombre} tiene {p1.edad} años")
    print(f"{p2.nombre} tiene {p2.edad} años")