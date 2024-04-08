public class Motor{
	private int potencia;

	public void setPotencia(int pot){
		if(pot>0) this.potencia = pot;
		else System.out.println("A potência tem que ser maior que 0");
	}

	public int getPotencia(){
		return this.potencia;
	}
}
