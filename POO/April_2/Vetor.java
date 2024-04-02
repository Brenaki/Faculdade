public class Vetor{
	public static void somar(int vetor[]){
		int soma = vetor[0];

		for(int i=1;i<vetor.length;i++){
			soma += vetor[i];
		}
		System.out.println("Soma do vetor e "+soma);
	}
}
