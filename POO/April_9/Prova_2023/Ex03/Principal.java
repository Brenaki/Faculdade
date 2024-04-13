public class Principal{
	
	public static void main(String[] args){
		int vet[] = new int[4];
		
		vet[0] = 7;
		vet[1] = 7;
		vet[2] = 7;
		vet[3] = 7;

		Nota sistema = new Nota();
		sistema.avaliarAluno(vet);

		vet[0] = 4;
		vet[1] = 4;
		vet[2] = 7;
		vet[3] = 7;

		sistema.avaliarAluno(vet);
	}
}
