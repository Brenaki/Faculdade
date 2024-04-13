# Polimorfismo

- Polimorfismo é a capacidade de um objeto ser refenciado de maneiras diferentes. Por exemplo, considere uma classe que soma as bonificações de funcionários.

```java
public class ControlaBonificacoes {
	private double totalBonificacoes;
	
	public void somar(Funcionario func) {
		totalBonificacoes = totalBonificacoes + func.bonificar();
	}

	public double getTotalBonificacoes(){
		return totalBonificacoes;
	}
}
```

- O seguinte trecho de código é válido:

```java
public class Principal {
	public static void main(String[] args){
		Funcionario f = new Funcionario("Fulano", "123.456.789-00", 100);
		Chefe c = new Chefe("Sicrano", "098.765.432-10", 100, "RH");
		ControlaBonificacoes controle = new ControleBonificacoes();
		controle.somar(f);
		controle.somar(c);
		System.out.println(controle.getTotalBonificacoes());
	}
}
```

- Embora o parâmetro do método somar da classe *ControleBonificações* seja um objeto da classe *Funcionario*, foi possível executar esse método passado como parâmetro um objeto da classe *Chefe*, como pode ser visto na linha 8 da classe *Principal*. Isso pe possível porque um *Chefe* é um tipo de *Funcionario*, e é possível referenciá-lo como um *Funcionario*.

- É importante perceber que um chefe pode ser referenciado como um funcionário ou como uma pessoa, afinal de contas, ele é essas duas coisas. Polimorfismo nesse exemplo é a capacidade que um objeto tem de ser referenciado como um objeto de classes das quais ele foi criado por herança.

- Mas o objeto em si continua sendo um objeto da classe *Chefe*, apenas a referência é feita de maneira diferente. Um objeto carrega consigo todos os seus métodos, e esses serão executados independente da referência. Por exemplo, mesmo que no método *somar()* o objeto da classe *Chefe* seja referenciado como um *Funcionario*, o método bonificar() (linha 5 da classe *ControleBonificacoes*) executado será o definido na classe *Chefe*.

- É possível também usar o conceito de polimorfismo na criação de um vetor. Por exemplo, um objeto da classe *Chefe* pode ser inserido dentro de um vetor de objetos da classe *Funcionario*.

- O código abaixo mostra uma modificação da classe *Principal* para incluir um vetor do tipo *Funcionario*.

```java
public class Principal {
	public static void main(String[] args){
		Funcionario vetor[] = new Funcionario[2];
		vetor[0] = new Funcionario("Fulano", "123.456.789-00", 100);
		vetor[1] = new Chefe("Sicrano", "098.765.432-10", 100, "RH");
		ControleBonificacoes controle = new ControleBonificacoes();
		for(int i=0; i<vetor.lenght; i++){
			controle.somar(vetor[i]);
		}
		System.out.println(controle.getTotalBonificacoes());
	}
}
```

- Alguns autores condenam o uso excessivo de herança, pois aumenta o grau de dependência entre classes. Por exemplo, uma modificação na classe *Pessoa* poderia acarretar uma mudança em todas as suas herdeiras.

- Polimorfismo, por outro lado, é uma prática muito recomendada, e é possível consegui-lo através do uso de interfaces, as quais serão discutidas em uma aula futura.
