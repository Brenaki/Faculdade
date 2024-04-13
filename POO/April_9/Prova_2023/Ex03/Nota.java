public class Nota{
	
	public static void avaliarAluno(int vetor[]){
		int soma = 0;
		for(int i=0;i<vetor.length;i++){
			soma += vetor[i];
		}

		if(soma >= 28) System.out.println("Aluno passou!");
		else System.out.println("Aluno reprovou!");
	}
}
