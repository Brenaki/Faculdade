public class ContaCorrente {
	private int numero;
	private double saldo;
	private String nome;

	// Construtor com 3 parâmetros
	public ContaCorrente(int numero, double saldo, String nome) {
		this.numero = numero;
		this.saldo = saldo;
		this.nome = nome;
	}

	// Construtor com 2 parâmetros
	public ContaCorrente(int numero, String nome) {
		if (numero > 0) {
			this.numero = numero;
			this.saldo = 0;
			this.nome = nome;
		} else
			System.out.println("Número negativo!");
	}

	// Atribui valor aos atributos
	public void setNumero(int numero) {
		if (numero > 0)
			this.numero = numero;
		else
			System.out.println("Valor negativo!");
	}

	public int getNumero() {
		return this.numero;
	}

	public void setNome(String nome) {
		if (nome == "")
			System.out.println("Nome não pode ser vazio!");
		else
			this.nome = nome;
	}

	public String getNome() {
		return this.nome;
	}

	public double getSaldo() {
		return this.saldo;
	}

	// Funções do Banco
	public void sacar(double valor) {
		if (valor <= saldo)
			this.saldo -= valor;
		else
			System.out.println("Saldo insufuciente");
	}

	public void depositar(double valor) {
		this.saldo += valor;
	}

	public void imprimir() {
		System.out.println("Numero da conta: " + this.numero);
		System.out.println("Nome do titular da conta: " + this.nome);
		System.out.println("Saldo atual: " + this.saldo);
	}

}
