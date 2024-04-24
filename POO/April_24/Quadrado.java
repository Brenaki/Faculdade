public class Quadrado extends Paralelogramo{
	
	public Quadrado(double lado){
		super(lado, lado);
	}

	public String toString(){
		String temp;
		temp = "\nÁrea: "+calcularArea()+"m²\nPerímetro: "+calcularPerimetro()+"m\n";
		return temp;
	}
}
