public class Principal {
	
	public static void main(String args[]){
		Porta frente, fundo;
		
		Casa casa;
		
		frente = new Porta("Marrom");
		fundo = new Porta("Branca");
		casa = new Casa(frente, fundo);

		casa.abrirPortaFrente();
		System.out.println(casa);
	}

}
