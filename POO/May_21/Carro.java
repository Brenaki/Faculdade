public class Carro {
	private String modelo;
 	private int potencia;

	public void setPotencia(int potencia) throws MinhaExcecao {
		if (potencia<=0) throw new MinhaExcecao("Valor de potência errado!");
 		else this.potencia = potencia;
 	}

 	public void setModelo(String modelo) throws MinhaExcecao {
 		if(modelo.isEmpty()) throw new MinhaExcecao("Modelo nulo!");
 		else this.modelo=modelo;
 	}

 	public String toString(){
 		return "Modelo: "+modelo+"Potência: "+potencia;
	}
}
