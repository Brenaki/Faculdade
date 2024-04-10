public class ContaCorrente extends Conta{

	public ContaCorrente(String nome, double saldo){
		super(nome, saldo);
	}

	public void sacar(double valor){
		if(getSaldo() > 0 && valor < getSaldo()){
			setSaldo(valor+1);
		}
	}
}
