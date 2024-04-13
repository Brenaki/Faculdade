public class Professor extends Funcionario{
	private int horasAula;
	
	public Professor(String nome, String telefone, Data nascimento, String registro, double salario, int horas){
		super(nome, telefone, nascimento, registro, salario);
		this.horasAula = horas;
	}

	public Professor(String nome, Data nascimento, String registro, double salario, int horas){
		super(nome, nascimento, registro, salario);
		this.horasAula = horas;
	}

	public void setHorasAula(int horas){
		if(horas > 0) this.horasAula = horas;
		else System.out.println("As horas aulas não pode ser um número negativo!");
	}

	public int getHorasAula(){
		return this.horasAula;
	}

	public double bonificar(){
		return getSalario() + (this.horasAula * 10);
	}

	public double getSalarioComBonificacao(){
		return getSalario() + bonificar();
	}

	public String toString(){
		String temp;
		temp = super.toString() + "\nHoras aula: " + this.horasAula;
		return temp;
	}
}
