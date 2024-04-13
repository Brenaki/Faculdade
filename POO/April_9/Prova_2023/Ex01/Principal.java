public class Principal{
	
	public static void main(String[] args){
		Conta vetor[] = new Conta[2];

		vetor[0] = new ContaCorrente("Victor", 0.0);
		vetor[1] = new ContaPoupanca("João", 100.0);

		System.out.println(vetor[0]);
		System.out.println(vetor[1]);

		vetor[0].depositar(50.0);
		vetor[1].depositar(50.0);

		System.out.println(vetor[0]);
		System.out.println(vetor[1]);

		vetor[0].sacar(49.0);
		vetor[1].sacar(49.0);

		System.out.println(vetor[0]);
		System.out.println(vetor[1]);

	}
	
}
