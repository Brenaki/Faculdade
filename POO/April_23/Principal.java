public class Principal{
	public static void main(String[] args){
		ObjGeo vetor[] = new ObjGeo[2];
		Circulo temp;

		vetor[0] = new Circulo(2);
		vetor[1] = new Quadrado(3);
		for(int i=0;i<2;i++){
			System.out.printf("\nMinha área é %.2fm²\n", vetor[i].calcularArea());
		}
		temp = (Circulo) vetor[0];	// downcasting
		temp.descreve();
	}
}
