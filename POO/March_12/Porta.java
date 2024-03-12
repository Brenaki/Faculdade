public class Porta {
	private String cor;

	public Porta(String cor){
		this.cor = cor;
	}

	public void abrir(){
		System.out.println("Sou " + cor + " e estou abrindo");
	}
	
	public void fechar(){
		System.out.println("Sou " + cor + " e estou fechado");
	}

	public String toString(){
		return "porta " + cor;
	}
	
}
