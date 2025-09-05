public class Ejemplo3 {
    public static void main(String[] args) {
        // Se inicializan los objetos usando el constructor
        Persona p1 = new Persona("Luis Gomez", 30);
        Persona p2 = new Persona("Marta Peralta", 30);

        System.out.printf("%s tiene %d años\n", p1.nombre, p1.edad);
        System.out.printf("%s tiene %d años\n", p2.nombre, p2.edad);
    }
}