public class Retangulo extends Paralelogramo{
	
	public Retangulo(double lado1, double lado2){
		super(lado1, lado2);
	}

	public String toString(){
		String temp;
		temp = "\nÁrea: "+calcularArea()+"m²\nPerímetro: "+calcularPerimetro()+"m\n";
		return temp;
	}
}
