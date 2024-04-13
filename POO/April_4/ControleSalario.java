public class ControleSalario{
	private double salarioBase;
	private double salarioBonificados;

	public void somarSalarios(Funcionario func){
		this.salarioBase += func.getSalario();
		this.salarioBonificados += func.getSalarioComBonificacao();
	}

	public void setSalarioBase(double valor){
		if(valor > 0) this.salarioBase = valor;
		else System.out.println("O valor não pode ser negativo!");
	}

	public void setSalarioBase(){
		this.salarioBase = 0;
	}

	public void setSalarioBonificado(double valor){
		if(valor > 0) this.salarioBonificados = valor;
		else System.out.println("O valor não pode ser negativo!");
	}

	public void setSalarioBonificado(){
		this.salarioBonificados = 0;
	}

	public double getTotalSalarioBase(){
		return this.salarioBase;
	}

	public double getTotalSalarioBonificado(){
		return this.salarioBonificados;
	}
}
