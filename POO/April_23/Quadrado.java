public class Quadrado implements ObjGeo{
	private double tam;

	public Quadrado(double tam){
		this.tam = tam;
	}

	public double calcularArea(){	// Métod Obrigatório
		return tam * tam;
	}
}
