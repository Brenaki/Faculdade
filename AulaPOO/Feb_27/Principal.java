public class Principal {
   public static void main(String[] args){
      
      // Declara o tipo das variaveis
      ContaCorrente conta1, conta2;
      
      // Instancia a classe
      conta1 = new ContaCorrente();
      conta1.numero = 13;
      conta1.nome = "Victor";
      conta1.agencia = 1;
      
      // Instancia a classe
      conta2 = new ContaCorrente();
      conta2.numero = 20;
      conta2.nome = "Paulo";
      conta2.agencia = 1;
      
      // Depositar
      conta1.depositar(200);
      conta2.depositar(300);
      
      // Sacar
      conta1.sacar(29.9);
      conta2.sacar(50);
      
      // Imprimir
      conta1.imprimir();
      conta2.imprimir();
   }
}