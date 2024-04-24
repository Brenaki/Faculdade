public abstract class Paralelogramo implements FiguraGeometrica, FiguraEscalavel{
	private double lado1;
	private double lado2;

	public Paralelogramo(double lado1, double lado2){
		this.lado1 = lado1;
		this.lado2 = lado2;
	}

	public double calcularArea(){
		return this.lado1 * this.lado2;
	}

	public double calcularPerimetro(){
		return this.lado1*2 + this.lado2*2;
	}

	public void diminuirObjeto(double valor){
		if(valor>0 && (this.lado1 - valor>0) && (this.lado2 - valor>0)) {
			this.lado1 -= valor;
			this.lado2 -= valor;
		}
		else if(this.lado1-valor<=0 || this.lado2-valor<=0) System.out.println("Não dá para diminuir essa quantidade");
		else System.out.println("Valor deve ser maior que zero!");
	}

	public void aumentarObjeto(double valor){
		if(valor>0){
			this.lado1 += valor;
			this.lado2 += valor;
		}
		else System.out.println("Valor deve ser maior que zero!");
	}
}
