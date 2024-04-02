public class Classe{
	private static int atributo;	// Obrigatoriamente estático

	public static void imprime(){	// Obrigatoriamente estático
		System.out.println("Valor de atributo é " +atributo);
	}

	public static void main(String[] args){		// Método estático
		atributo = 5;
		imprime();
	}
}
