import java.util.Scanner;

public class Leitura {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int x;
    System.out.printf("Digite um número inteiro: ");
    x = scanner.nextInt();
    System.out.println("Número digitado: " + x);
  }
}
