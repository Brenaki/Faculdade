public class Automovel{
	private Motor motor;
	private String cor;

	public Automovel(Motor motor, String cor){
		this.motor = motor;
		this.cor = cor;
	}

	public void setCor(String cor){
		if(cor.equals("")) System.out.println("A cor não pode ser vazia");
		else this.cor = cor;
	}

	public String getCor(){
		return this.cor;
	}

	public String toString(){
		String temp;	
		temp = "\nPotência do Motor: "+this.motor.getPotencia() + "\nCor do automóvel: "+this.cor;
		return temp;
	}
}
