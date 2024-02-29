public class Principal {
  public static void main(String[] args) {
    ContaCorrente conta1, conta2, conta3;

    conta1 = new ContaCorrente("Fulano", 123, (short) 456, 1000, 500);
    conta2 = new ContaCorrente("Ciclano", 789, (short) 1011, 2000);
    conta3 = new ContaCorrente("Beltrano", 1213, (short) 1415);

    System.out.println("Conta 1:");
    conta1.imprimir();
    System.out.println("\nConta 2:");
    conta2.imprimir();
    System.out.println("\nConta 3:");
    conta3.imprimir();
    conta2.atualizar(20, 10);
    conta3.atualizar("João", 1312, (short) 1416);
    System.out.println("\nConta 1:");
    conta1.sacar(3000);
    conta1.depositar(-1);
    conta1.imprimir();
    System.out.println("\nConta 2:");
    conta2.imprimir();
    System.out.println("\nConta 3:");
    conta3.depositar(100);
    conta3.imprimir();
  }
}
