# Herança

- Através de herança, uma classe(chamada subclasse ou classe filha) herda os atributos e métodos de outra classe (chamada superclasse ou classe pai) e inclui os seus próprios atributos e métodos.
- Por exemplo, considere uma aplicação de controle de pessoal em uma universidade na qual sejam criadas classes para representar alunos, funcionários e professores. Toda e qualquer classe que represente uma pessoa terá atributos para CPF, nome e endereço, por exemplo.
- Repetir atributos iguais em classes diferentes que façam parte do mesmo sistema, além de aumentar a quantidade de código a ser implementado, permite que o mesmo atributo seja representado de diferentes maneiras por programadores diferentes. Por exemplo, o atributo CPF pode ser declarado como um valor númerico ou uma string, e essa diferença vai dificultar o trabalho de programadores que precisem manipular o CPF de todas as pessoas cadastradas no sistema da universidade(para fazer relatórios, por exemplo).
- Uma boa solução para esse caso é criar uma classe Pessoa, na qual todos os atributos comuns a uma pessoa sejam definidos, e criar classes derivadas que contenham os atributos que não sejam comuns a todas as pessoas cadastradas no sistema.
- Uma relação de herença é diferente de uma relação de composição, pois uma classe não contém a outra. Tem-se uma relação de extensçao, caracterizada pela frase **é um tipo de**, ou seja, se a classe A estende a classe B, a frase **A é um tipo de B** deve fazer sentido.
- Por exemplo, considere a seguinte classe para representar uma pessoa.

```java
public class Pessoa {
	private String nome;
	private String cpf;

	public Pessoa(String nome, String cpf){
		this.nome = nome;
		this.cpf = cpf;
	}
	
	public String getNome(){
		return nome;
	}
}
```

- Um **funcionário é um tipo de pessoa**, então pode-se criar a classe Funcionario estendendo a classe Pessoa(usando a palavra reservada *extends*) e incluindo o atributo salario, que é exclusivo de funcionário. É importante lembrar que a classe Pessoa pode ser estendida por classes que não possuam o atributo salario, como a classe Aluno, por exemplo.
- O construtor da classe Funcionario deve incluir a palavra reservada super, que é responsável por executar o construtor da classe Pessoa, e deve receber como parâmetros os valores dos atributos da superclasse também.

```java
public class Funcionario extends Pessoa {
	private double salario;

	public Funcionario(String nome, String cpf, double salario){
		super(nome, cpf);	// Executa o construtor de Pessoa
		this.salario = salario;
	}

	public double getSalario(){
		return this.salario;
	}

	public double bonificar() {
		return this.salario * 0.10; // Retorna valor da bonificação
	}
}
```

- Tudo que dor público é herdado diretamente e pode ser acessado a partir da subclasse. Por exemplo, método getNome(), que está denifido na classe Pessoa, mas pe acessado via um objeto da classe Funcionario.

```java
public class Principal {

	public static void main(String[] args){
		Funcionario f = new Funcionario("Fulano", "123.456.789-00", 100);
		System.out.println("O nome é " + f.getNome());

	}
}
```

- Atributos privados, embora sejam teoricamente herdados, não podem ser acessados diretamente, e devem ser acessados através de métodos set e get. Uma alternativa com prós e contras é definir o atributo como protegido(protected), conceito que será estudado adiante.

- No sistema exemplo deste texto, todo funcionário tem direito a uma bonificação, a qual é calculada pelo método bonificar(). Esse valor pode variar, e na versão atual do sistema é de 10% sobre o valor do salário. Suponha que seja criado uma classe Chefe, que estenda Funcionario (afinal, chefe é um tipo de funcionário). Chefes têm bonificação de 20%, e portanto não podem usar o método bonificar() definido na superclasse.

- O método bonificar() pode ser redefinido na subclasse, processo que é chamado de sobreposição (*override*) em POO. Não confunda esse conceito com sobrecarga (*overload*), que significa criar métodos com mesmo nome e diferentes assinaturas na mesma classe.

```java
public class Chefe extends Funcionario {
	private String cargo;

	public Chefe(String nome, String cpf, double salario, String cargo){
		super(nome, cpf, salario);	// Executar o construtor de Pessoa 
		this.cargo = cargo;
	}

	public double bonificar(){		// Método sobreposto
		return getSalario()*0.20;	// O Atributo salario é privado em Funcionario
	}
}
```

- É importante lembrar que o atributo salario é privado em Funcionario, e deve ser acessado através do método getSalario().
- Suponha que a bonificação do chefe seja R$100,00 a mais do que a bonificação do funcionário, de maneira que seja necessário executar o método sobreposto. Para isso, basta incluir a palavra reservada super para diferenciar os métodos bonificar() da superclasse e da subclasse.

```java
public double bonificar(){
	return super.bonificar() + 100; // Executa método sobreposto
}
```
