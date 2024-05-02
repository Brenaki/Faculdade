package br.uepg.deinfo.primeiro;

public class Pessoa{
	protected double salario;
	private String nome;
	private int cod;

	protected Pessoa(int cod, String nome){
		this.cod = cod;
		this.nome = nome;
	}

//	protected void setCodigo(int cod){
//		if(cod>0) this.cod = cod;
//		else System.out.println("Código não pode ser valor menor que zero!");
//	}

	protected int getCodigo(){
		return this.cod;
	}

//	protected void setNome(String nome){
//		if(nome.equals("")) System.out.println("Nome não pode ser vazio!");
//		else this.nome = nome;
//	}

	protected String getNome(){
		return this.nome;
	}

	public String toString(){
		String temp = "\nCódigo: "+this.cod+"\nNome: "+this.nome+"\nSalário: "+this.salario;
		return temp;
	}
}
