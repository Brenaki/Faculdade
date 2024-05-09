package br.brenaki;

public class Aluno{
	private String nome;
	private int media;

	public void setNome(String nome){
		if(nome.equals("")) System.out.println("O nome não pode ser vazio!");
		else this.nome = nome;
	}

	public void setMedia(int media){
		if(media>=0) this.media = media;
		else System.out.println("A média não pode ser menor que zero!");
	}

	public String toString(){
		String temp;
		temp = "\nNome: "+this.nome+"\nMédia: "+this.media;
		return temp;
	}

}
