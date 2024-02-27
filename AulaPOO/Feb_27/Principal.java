public class Principal {
	public static void main(String args[]){
		ContaCorrente conta;

		conta = new ContaCorrente(13, "Victor");
		System.out.println("\n**Metodo GET**");
		System.out.println("Número da conta: " + conta.getNumero());
		System.out.println("Nome do cliente: " + conta.getNome());
		System.out.println("\n**Imprimir**");
		conta.imprimir();
	}
}
