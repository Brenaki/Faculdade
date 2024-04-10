public class UCP{
	private float frequencia;

	public void setFrequencia(float freq){
		if(freq > 0) this.frequencia = freq;
		else System.out.println("A frequência tem que ser maior que zero!");
	}

	public float getFrequencia(){
		return this.frequencia;
	}
}
