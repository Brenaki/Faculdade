public class Chefe extends Funcionario {
	private String cargo;

	public Chefe(String nome, String telefone, Data nascimento, String registro, double salario, String cargo){
		super(nome, telefone, nascimento, registro, salario);
		this.cargo = cargo;
	}

	public Chefe(String nome, Data nascimento, String registro, double salario, String cargo){
		super(nome, nascimento, registro, salario);
		this.cargo = cargo;
	}

	public void setCargo(String cargo){
		if(cargo.equals("")) System.out.println("Cargo não pode ser vazio");
		else this.cargo = cargo;
	}

	public String getCargo(){
		return this.cargo;
	}

	public double bonificar(){
		return getSalario() * 0.20;
	}

	public String toString(){
		String temp;
		temp = super.toString() + "\nCargo: " + this.cargo;
		return temp;
	}
}
