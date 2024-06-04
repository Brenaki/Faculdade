package br.deinfo.uepg;

public class ContaCorrente {
  protected String nome;
  private int num; 
  
  protected ContaCorrente(String nome, int num){
    this.nome = nome;
    this.num = num;
  }

  public String getNome() {
    return this.nome;
  }

  protected int getNumero() {
    return this.num;
  }

}
