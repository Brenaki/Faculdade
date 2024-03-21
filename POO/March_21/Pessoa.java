public class Pessoa {
	private String nome;
	private String telefone;
	private Data nascimento;

	public Pessoa(String nome, String telefone, Data nascimento){
		this.nome = nome;
		this.telefone = telefone;
		this.nascimento = nascimento;
	}

	public Pessoa(String nome, Data nascimento){
		this.nome = nome;
		this.telefone = "";
		this.nascimento = nascimento;
	}

	public void setNome(String nome){
		if(nome.equals("")) System.out.println("Nome não pode ser vazio");
		else this.nome = nome;
	}

	public String getNome(){
		return this.nome;
	}

	public void setTelefone(String telefone){
		if(telefone.equals("")) System.out.println("Telefone não pode ser vazio!");
		else this.telefone = telefone;
	}

	public String getTelefone(){
		return this.telefone;
	}

	public void setNascimento(Data nascimento){
		this.nascimento = nascimento;
	}

	public Data getNascimento(){
		return this.nascimento;
	}

	public String toString(){
		String temp;
		temp = "\nNome: "+ this.nome + "\nTelefone: " + this.telefone + "\nData de nascimento: " + this.nascimento;
		return temp;
	}
}
