public class ContaCorrente {
  private String nome;
  private int numero;
  private int agencia;
  private double saldo;
  private double limite;
   
  public ContaCorrente(String nome, int numero, int agencia, double saldo, double limite) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
    this.saldo = saldo;
    this.limite = limite;
  }
  
  public ContaCorrente(String nome, int numero, int agencia, double saldo) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
    this.saldo = saldo;
  }
   
  public ContaCorrente(String nome, int numero, int agencia) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
  }

  public ContaCorrente(){
    System.out.println("Objeto Criado!");
  }
  
  public void setSaldo(double saldo) throws MinhaExcecao{
    if(saldo>0){
      this.saldo = saldo;
    } else {
      throw new MinhaExcecao("Saldo inválido!");
    }
  }
  
  public void getSaldo(){
    System.out.println(this.saldo);
  } 
  
  public void setNome(String nome) throws MinhaExcecao{
    if(!nome.matches("[A-Za-z ]*")) throw new MinhaExcecao("Nome inválido!"); 
    if(nome.isEmpty()) throw new MinhaExcecao("Nome não pode ser vazio!");
    if(nome.matches("[ ]*")) throw new MinhaExcecao("Nome não pode ser um espaço vazio!");
    else {
      this.nome = nome;
    }
  }
  
  public void getNome(){
    System.out.println(this.nome);
  }
  
  public void setNumero(int numero) throws MinhaExcecao{
    if(numero>0){
      this.numero = numero;
    } else {
      throw new MinhaExcecao("Número da conta inválido!");
    }
  }
  
  public void getNumero(){
    System.out.println(this.numero);
  }
  
  public void setAgecia(int agencia) throws MinhaExcecao{
    if(agencia>0){
      this.agencia = agencia;
    } else {
      throw new MinhaExcecao("Número da agência inválido!");
    }
  }
  
  public void getAgencia(){
    System.out.println(this.agencia);
  }
  
  public void setLimite(double limite) throws MinhaExcecao{
    if(limite>0){
      this.limite = limite;
    } else {
      throw new MinhaExcecao("Valor do limite da conta inválido!");
    }
  }
  
  public void getLimite(){
    System.out.println(this.limite);
  }
   
  public void atualizar(double saldo, double limite) {
    this.saldo = saldo;
    this.limite = limite;
  }
  
  public void atualizar(String nome, int numero, int agencia) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
  }
  
  public void depositar(double valor) throws MinhaExcecao{
    if (valor < 0) throw new MinhaExcecao("Você tentou depositar um número negativo!");
    if (valor == 0) throw new MinhaExcecao("Você tentou depositar o valor de zero!");
    this.saldo += valor;
  }

  public void sacar(double valor) throws MinhaExcecao{
    if (valor > this.saldo + this.limite) throw new MinhaExcecao("Saldo insuficiente!");
    if(valor == 0) throw new MinhaExcecao("Não pode sacar o valor de zero!");
    if(valor < 0) throw new MinhaExcecao("Não pode sacar um valor negativo!");

    this.saldo -= valor;
  }
   
  public String toString() {
    String temp;
    temp = "\nNome: " + this.nome+"\nNúmero: " + this.numero+"\nAgência: " + this.agencia+"\nSaldo: " + this.saldo+"\nLimite: " + this.limite;
    return temp;
  }
}
