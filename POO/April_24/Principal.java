public class Principal{
	public static void main(String[] args){
		// Paralelogramo's
		FiguraGeometrica vetor[] = new FiguraGeometrica[3];
		vetor[0] = new Quadrado(3);
		vetor[1] = new Retangulo(3,2);
		vetor[2] = new Circulo(2);

		FiguraEscalavel temp;
		for(int i=0;i<3;i++){
			System.out.println("**Padrão**");
			System.out.println(vetor[i]);
			temp = (FiguraEscalavel) vetor[i];

			System.out.println("**Diminuindo valor**");
			temp.diminuirObjeto(1);
			System.out.println(vetor[i]);

			System.out.println("**Aumentando valor**");
			temp.aumentarObjeto(2);
			System.out.println(vetor[i]);
		}	
	}
}
