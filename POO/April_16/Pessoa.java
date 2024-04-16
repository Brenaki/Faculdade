public abstract class Pessoa{	// Classe abstrata Pessoa
	private String nome;
	private String cpf;

	public Pessoa(String nome, String cpf){
		this.nome = nome;
		this.cpf = cpf;
	}

	public abstract String getRegistro();	// Subclasses devem implementar

	public String getNome(){
		return this.nome;
	}
}
