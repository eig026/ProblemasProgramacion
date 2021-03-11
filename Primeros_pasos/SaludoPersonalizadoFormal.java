import java.util.Scanner;

public class SaludoPersonalizadoFormal
{
    public static void main(String[] args)
    {
        String nombre, apellido;

        Scanner teclado = new Scanner(System.in);
        nombre = teclado.nextLine();
        System.out.print("Introduzca su apellido: ");
        apellido = teclado.nextLine();
        System.out.println("¡Hola " + nombre +" "+ apellido +"!");
    }
}
