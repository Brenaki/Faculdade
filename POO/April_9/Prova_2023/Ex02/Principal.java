public class Principal{
	
	public static void main(String[] args){
		Motor motor = new Motor();
		motor.setPotencia(500);

		Automovel carro = new Automovel(motor, "Vermelho");
		System.out.println(carro);
	}
}
