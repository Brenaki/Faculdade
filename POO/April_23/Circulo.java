public class Circulo implements ObjGeo{
	private double raio;

	public Circulo(double raio){
		this.raio = raio;
	}

	public double calcularArea(){	// Método Obrigatório
		return Math.PI * raio * raio;
	}

	public void descreve(){
		System.out.printf("\nEu sou um círculo\n");
	}
}
