public class ContaCorrente {
    public String nome;
    public int numero;
    public short agencia;
    private double saldo;
    
    
    public void depositar(double valor){
      if(valor>=0) {
         saldo += valor;
      }
      else System.out.println("Valor que voce gostaria de inserir e invalido!");
    }
    public void sacar(double valor){
      if(valor>0 && valor <= saldo){
         saldo -= valor;
      }  else System.out.println("Saldo Insuficiente!");
      
    }
    public void imprimir(){
      System.out.println("\nNome do titular da conta: " + nome);
      System.out.println("Numero da conta: " + numero);
      System.out.println("Agencia: " + agencia);
      System.out.println("Saldo atual: " + saldo);
    }
}