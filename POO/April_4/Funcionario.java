public class Funcionario extends Pessoa{
	private String registro;
	private double salario;

	public Funcionario(String nome, String telefone, Data nascimento, String registro, double salario){
		super(nome, telefone, nascimento);
		this.registro = registro;
		this.salario = salario;
	}

	public Funcionario(String nome, Data nascimento, String registro, double salario){
		super(nome, nascimento);
		this.registro = registro;
		this.salario = salario;
	}

	public void setRegistro(String registro){
		if(registro.equals("")) System.out.println("Registro não pode ser vazio");
		else this.registro = registro;
	}

	public String getRegistro(){
		return this.registro;
	}

	public void setSalario(double salario) {
		if(salario <= 0) System.out.println("Salario não pode ser menor que 0");
		else this.salario = salario;
	}

	public final double getSalario(){
		return this.salario;
	}

	public double bonificar(){
		return this.salario * 0.1;
	}

	public double getSalarioComBonificacao(){
		return bonificar() + this.salario;
	}

	public String toString(){
		String temp;
		temp = super.toString() + "\nRegistro: " + this.registro + "\nSalario: " + this.salario + "\nBonificação: "
				+ bonificar() + "\nSalario com bonificação: " + getSalarioComBonificacao();
		return temp;
	}
}
