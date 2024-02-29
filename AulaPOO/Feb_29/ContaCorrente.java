public class ContaCorrente {
  private String nome;
  private int numero;
  private short agencia;
  private double saldo;
  private double limite;

  public ContaCorrente(String nome, int numero, short agencia, double saldo, double limite) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
    this.saldo = saldo;
    this.limite = limite;
  }

  public ContaCorrente(String nome, int numero, short agencia, double saldo) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
    this.saldo = saldo;
  }

  public ContaCorrente(String nome, int numero, short agencia) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
  }

  public void atualizar(double saldo, double limite) {
    this.saldo = saldo;
    this.limite = limite;
  }

  public void atualizar(String nome, int numero, short agencia) {
    this.nome = nome;
    this.numero = numero;
    this.agencia = agencia;
  }

  public void depositar(double valor) {
    if (valor <= 0) {
      System.out.println("Valor inválido!");
      return;
    }
    this.saldo += valor;
  }

  public void sacar(double valor) {
    if (valor > this.saldo + this.limite) {
      System.out.println("Saldo insuficiente!");
      return;
    }
    this.saldo -= valor;
  }

  public void imprimir() {
    System.out.println("Nome: " + this.nome);
    System.out.println("Número: " + this.numero);
    System.out.println("Agência: " + this.agencia);
    System.out.println("Saldo: " + this.saldo);
    System.out.println("Limite: " + this.limite);
  }
}