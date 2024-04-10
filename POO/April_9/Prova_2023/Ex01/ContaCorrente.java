public class ContaCorrente extends Conta{

	public ContaCorrente(String nome, double saldo){
		super(nome, saldo);
	}

	public void sacar(double valor){
		if(getSaldo() > 0 && valor < getSaldo()){
			super.sacar(valor + 1);
		}
		else
			System.out.println("Saldo insuficiente");
	}
}
