public class Nota{
	private String nome;
	private double valor;

	public Nota(String nome, int valor){
		this.nome = nome;
		this.valor = valor;
	}

	public void setNome(String nome){
		if(nome.equals("")) System.out.println("Nome não pode ser vazio!");
		else this.nome = nome;
	}
	
	public String getNome(){
		return this.nome;
	}

	public void setValor(double valor){
		if(valor > 0) this.valor = valor;
		else System.out.println("Valor tem que ser maior que zero!");
	}

	public double getValor(){
		return this.valor;
	}

	public void descontaImposto(){
		setValor(getValor());
	}
}
