public class Aluno extends Pessoa{	// Trecho da classe Aluno
	private String ra;

	public Aluno(String nome, String cpf, String ra){
		super(nome, cpf);
		this.ra = ra;
	}

	public String getRegistro(){	// Implementação obrigatória
		return ra;
	}
}
