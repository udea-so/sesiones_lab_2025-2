public class Ejemplo5 {

    // Método que recibe una referencia a un objeto Persona
    public static void imprimir(Persona p) {
        // Se accede a los atributos con el operador punto "."
        System.out.printf("%s tiene %d años\n", p.nombre, p.edad);
    }

    public static void main(String[] args) {
        Persona p1 = new Persona();
        p1.nombre = "Carlos";
        p1.edad = 28;

        // Se pasa la referencia del objeto al método
        imprimir(p1);
    }
}