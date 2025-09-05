public class Ejemplo2 {
    public static void main(String[] args) {
        Persona p1 = new Persona();

        // En Java, la asignación de strings es directa
        p1.nombre = "Ana";
        p1.edad = 22;

        System.out.println("Nombre: " + p1.nombre);
        System.out.println("Edad: " + p1.edad);
    }
}