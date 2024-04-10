public class Computador{
	private UCP processador;
	private String modelo;

	public Computador(UCP processador, String modelo){
		this.processador = processador;
		this.modelo = modelo;
	}

	public String toString(){
		String temp;
		temp = "Processador:\nModelo: "+this.modelo +"\nFrequência: "+this.processador.getFrequencia();
		return temp;
	}

}
