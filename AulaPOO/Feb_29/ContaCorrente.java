public class ContaCorrente {
  private String nome;
  private int numero;
  private int agencia;
  private double saldo;
  private double limite;
   
  // Ao criar o objeto necessita preecher todos os atributos
  public ContaCorrente(String nome, int numero, int agencia, double saldo, double limite) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
    this.saldo = saldo;
    this.limite = limite;
  }
  
  // Ao criar o objeto necessita preecher nome, numero, agencia e saldo
  public ContaCorrente(String nome, int numero, int agencia, double saldo) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
    this.saldo = saldo;
  }
   
  // Ao criar o objeto necessita preecher nome, numero e agencia
  public ContaCorrente(String nome, int numero, int agencia) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
  }
  
  // Adiciona/altera saldo a conta
  public void setSaldo(double saldo){
    if(saldo>0){
      this.saldo = saldo;
    } else {
      System.out.println("Valor inválido!");
    }
  }
  
  // Imprime o saldo da conta
  public void getSaldo(){
    System.out.println(this.saldo);
  }
  
  // Adiciona/altera nome da conta
  public void setNome(String nome){
    if(nome.equals("")){
      System.out.println("Nome não pode ser vazio");
    } else {
      this.nome = nome;
    }
  }
  
  // Imprime o nome do titular da conta
  public void getNome(){
    System.out.println(this.nome);
  }
  
  // Adiciona/altera numero da conta
  public void setNumero(int numero){
    if(numero>0){
      this.numero = numero;
    } else {
      System.out.println("Valor inválido!");
    }
  }
  
  // Imprime o numero da conta
  public void getNumero(){
    System.out.println(this.numero);
  }
  
  // Adiciona/altera agencia da conta
  public void setAgecia(int agencia){
    if(agencia>0){
      this.agencia = agencia;
    } else {
      System.out.println("Valor inválido!");
    }
  }
  
  // Imprime o agencia da conta
  public void getAgencia(){
    System.out.println(this.agencia);
  }
  
  // Adiciona/altera limite da conta
  public void setLimite(double limite){
    if(limite>0){
      this.limite = limite;
    } else {
      System.out.println("Valor inválido!");
    }
  }
  
  // Imprime o limite da conta
  public void getLimite(){
    System.out.println(this.limite);
  }
  
  
  // Atualiza saldo e o limite 
  public void atualizar(double saldo, double limite) {
    this.saldo = saldo;
    this.limite = limite;
  }
  
  // Atualiza o nome, numero e agencia
  public void atualizar(String nome, int numero, int agencia) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
  }
  
  // Deposita um valor positivo na conta do usuario
  public void depositar(double valor) {
    if (valor <= 0) {
      System.out.println("Valor inválido!");
      return;
    }
    this.saldo += valor;
  }

  // Saca um valor dentro do saldo e limite que o usuario possui
  public void sacar(double valor) {
    if (valor > this.saldo + this.limite) {
      System.out.println("Saldo insuficiente!");
      return;
    }
    this.saldo -= valor;
  }
   
  // Imprime todos os atributos para a vizualização do usuario
  public void imprimir() {
    System.out.println("Nome: " + this.nome);
    System.out.println("Número: " + this.numero);
    System.out.println("Agência: " + this.agencia);
    System.out.println("Saldo: " + this.saldo);
    System.out.println("Limite: " + this.limite);
  }
}