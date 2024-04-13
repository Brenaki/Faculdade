public class Principal{
	
	public static void main(String[] args){
		UCP p = new UCP();
		p.setFrequencia(3);

		Computador PC = new Computador(p, "HP");
		System.out.println(PC);
	}
}
