public class Principal{
	
	public static void main(String[] args){
		Nota vet[] = new Nota[2];

		vet[0] = new NotaOficial("Desenvolvimento", 1000, "012.345.678-90");
		vet[1] = new NotaNaoOficial("Desenvolvimento", 1000);

		vet[0].descontaImposto();
		vet[1].descontaImposto();

		System.out.println("Nota Oficial: "+vet[0].getValor() + "\nNota Não Oficial: "+vet[1].getValor());
	}
}
