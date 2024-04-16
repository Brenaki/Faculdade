public class Funcionario extends Pessoa{	// Trecho da classe Funcionario
	private int rf;

	public Funcionario(String nome, String cpf, int rf){
		super(nome, cpf);
		this.rf = rf;
	}

	public String getRegistro(){	// Implementação obrigatŕia
		return Integer.toString(rf);
	}
}
