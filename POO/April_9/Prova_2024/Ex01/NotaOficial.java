public class NotaOficial extends Nota{
	private String cpf;

	public NotaOficial(String nome, int valor, String cpf){
		super(nome, valor);
		this.cpf = cpf;
	}

	public void setCpf(String cpf){
		if(cpf.equals("")) System.out.println("CPF não pode ser vazio!");
		else this.cpf = cpf;
	}

	public String getCpf(){
		return this.cpf;
	}

	public void descontaImposto(){
		setValor(getValor()*0.9);
	}
}
