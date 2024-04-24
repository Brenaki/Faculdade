import java.text.DecimalFormat;

public class Circulo implements FiguraGeometrica, FiguraEscalavel{
	private double raio;

	public Circulo(double raio){
		this.raio = raio;
	}

	public double calcularArea(){
		return Math.PI * raio * raio;
	}

	public double calcularPerimetro(){
		return 2 * Math.PI * raio;
	}

	public void diminuirObjeto(double valor){
		if(valor>0 && (this.raio-valor)>0) this.raio -= valor;
		else if(this.raio-valor<=0) System.out.println("O valor digitado é maior que o tamanho do raio atual");
		else System.out.println("O valor deve ser maior que zero!");
	}

	public void aumentarObjeto(double valor){
		if(valor>0) this.raio += valor;
	}

	public String toString(){
		String temp;
		DecimalFormat formato = new DecimalFormat();
		formato.setMaximumFractionDigits(2);
		temp = "\nRaio: "+this.raio+"m\nÁrea: "+formato.format(calcularArea())+"m²\nPerímetro: "+formato.format(calcularPerimetro())+"m\n";
		return temp;
	}
}
