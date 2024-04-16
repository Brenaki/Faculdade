# Classes Abstratas

- Quando se trabalha com herança, são criadas diversas classes com o intuito de modelar o sistema computacional desenvolvido. Algumas dessas classes existem apenas para fins de modelagem, e nunca se transformam em objetos. Classes que nunca são instanciadas podem ser definidas como **classe abstratas**.

- Por exemplo, no sistema de controle de pessoal da Universidade, a classe *Pessoa* é usada apenas como superclasse de classes como *Funcionario*, *Aluno*, entre outras. Portanto, essa classe pode ser definida como abstrata.

- Dentro de classes abstratas podem existir **métodos abstratos**, que são métodos que são apenas declarados, e não sçao implementados, mas devem ser obrigatoriamente implementados nas subclasses.

- Por exemplo, considere que seja definido que toda pessoa que estiver cadastrada no sistema deve ter um registro. Porém, funcionários e alunos têm registros diferentes: RA para alunos (valor tipo string) e RF para funcionário (valor do tipo inteiro). E é necessário que o sistema possua um método que retorne o registro de todos que estiverem cadastrados no sistema.

- Uma solução é criar um método abstrato chamado *getRegistro()* e cada classe vai implementar sua própria versão do método. No caso de um funcionário, o valor inteiro deve ser transformado em uma string antes.

- A classe *Pessoa*, que nunca será instanciada, é mostrada abaixo:

```java
public abstract class Pessoa{
	private String nome;
	private String cpf;

	public Pessoa(String nome, String cpf){
		this.nome = nome;
		this.cpf = cpf;
	}

	public abstract String getRegistro();

	public String getNome(){
		return this.nome;
	}
}
```

- A partir da classe *Pessoa*, são criadas classes para funcionários e alunos. Nesse caso, as duas subclasses devem obrigatoriamente possuir um método chamado *getRegistro()*, conforme é mostrado nas duas classes abaixo.

```java
public class Aluno extends Pessoa{
	private String ra;

	public Aluno(String nome, String cpf, String ra){
		super(nome, cpf);
		this.ra = ra;
	}

	public String getRegistro(){ 	// Implemetação obrigatória
		return this.ra;
	}
}
```

```java
public class Funcionario extends Pessoa{
	private int rf;

	public Funcionario(String nome, String cpf, int rf){
		super(nome, cpf);
		this.rf = rf;
	}

	public String getRegistro(){	// Implementação obrigatória
		return Integer.toString(rf);
	}
}
```
