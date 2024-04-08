public class Conta{
	private String nome;
	private double saldo;

	public Conta(String nome, double saldo){
		this.nome = nome;
		this.saldo = saldo;
	}
	
	public void setNome(String nome){
		if(nome.equals("")) System.out.println("Nome não pode ser vazio");
		else this.nome = nome;
	}
	
	public String getNome(){
		return this.nome;
	}

	public void setSaldo(double valor){
		if(valor > 0) this.saldo -= valor;
		else System.out.println("Saldo não pode ser negativo");

	}

	public double getSaldo(){
		return this.saldo;
	}

	public void depositar(double valor){
		if(valor > 0) this.saldo += valor;
		else System.out.println("O Valor não pode ser negativo");
	}

	public void sacar(double valor){
		return;
	}
	
	public String toString(){
		String temp;
		temp = "\nNome: " +this.nome + "\nSaldo: " +this.saldo;
		return temp;
	}
}
