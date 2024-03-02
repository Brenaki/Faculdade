public class Principal {
  public static void main(String[] args) {
    ContaCorrente conta1, conta2, conta3;

    conta1 = new ContaCorrente("Fulano", 123, 456, 1000, 500);
    conta2 = new ContaCorrente("Ciclano", 789, 1011, 2000);
    conta3 = new ContaCorrente("Beltrano", 1213, 1415);
   
    // Imprime Conta 1
    System.out.println("Conta 1:");
    conta1.imprimir();
    
    // Imprime Conta 2
    System.out.println("\nConta 2:");
    conta2.imprimir();
    
    // Imprime Conta 3
    System.out.println("\nConta 3:");
    conta3.imprimir();
    
    System.out.println("\nDados atualizados e Error:");
    
    // Altera o saldo e o limite
    conta2.atualizar(20, 10);
    
    // Altera o nome, agencia e numero
    conta3.atualizar("João", 1312, 1416);
    
    // Imprime Conta 1
    System.out.println("\nConta 1:");
    // Fracassa em sacar R$ 3000
    conta1.sacar(3000);
    // Fracassa em depositar um valor negativo
    conta1.depositar(-1);
    conta1.imprimir();
    
    // Imprime Conta 2 com o saldo e o limite alterados
    System.out.println("\nConta 2:");
    conta2.imprimir();
    
    // Imprime Conta 3 com o nome, agencia e numero alterados
    System.out.println("\nConta 3:");
    // Deposita R$ 100 reais
    conta3.depositar(100);
    conta3.imprimir();
  }
}