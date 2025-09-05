public class Ejemplo4 {
    public static void main(String[] args) {
        // p1 es una referencia al nuevo objeto Persona
        Persona p1 = new Persona();
        p1.nombre = "Marta";
        p1.edad = 25;
        
        // ptr es otra referencia que apunta al MISMO objeto que p1
        Persona ptr = p1;

        // Se accede a los datos a través de la referencia con el operador "."
        System.out.println("Nombre: " + ptr.nombre);
        System.out.println("Edad: " + ptr.edad);
    }
}