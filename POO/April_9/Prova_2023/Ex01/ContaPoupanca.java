public class ContaPoupanca extends Conta{
	
	public ContaPoupanca(String nome, double saldo){
		super(nome, saldo);
	}
	
	public void sacar(double valor){
		if(getSaldo() > 0 && valor < getSaldo()){
			super.sacar(valor);
		} else
			System.out.println("Saldo insuficiente");
	}
}

