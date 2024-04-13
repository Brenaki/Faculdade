public class NotaNaoOficial extends Nota{
	
	public NotaNaoOficial(String nome, int valor){
		super(nome, valor);
	}

	public void descontaImposto(){
		setValor(getValor() * 0.99);
	}
}
