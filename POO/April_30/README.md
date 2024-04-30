# Pacotes

- Pacotes são coleções de classes agrupadas, possibilitando uma melhor organização quando existe uma grande quantidade de classes disponíveis. Além disso, classes que serão disponibilizadas para uso de terceiros (ou seja, serão importadas) geralmente são incluídas em pacotes.
- Para criar uma classe que será distribuída, deve-se seguir os seguintes passos:

1. Declarar a classe pública
2. Incluir a declaração *package* com o nome do pacote

- Para evitar que haja confitos com nome de pacotes e classes criados por outros programadores, geralmente se usa o domímio de internet (escrito ao contrário) da instituição na qual foi implementada a aplicação. É importante ressaltar que nomes de domínio são únicos no mundo, então não há possibilidade de criar pacotes com nomes iguais.
- Por exemplo, uma classe criada por um programador do Deinfo, cujo domínio é *deinfo.uepg.br*, seria incluída no pacote *br.uepg.deinfo*.

```Java
package br.uepg.deinfo

public class Produto{
	...
}
```

- Para que essa classe seja importada, deve-se usar o comando *import*. Por exemplo:

```Java
import br.uepg.deinfo.Produto;	// Importa apenas a classe Produto
//	ou
import br.uepg.deinfo.*		// Importa todas as classes do pacote
```

- Se não for usado o comando *import*, para instanciar a classe deve-se incluir o nome do pacote antes. É importante perceber que uma classe incluída em um pacote deve sempre ser refeciada em conjunto com o pacote. Por exemplo:

- Usando o comando *import* (abordagem mais comum):

```Java
import br.uepg.deinfo.Produto

public class Principal{
	public static void main(String[] args){
		Produto p = new Produto();
	}
}
```

- Sem usar o comando *import*:

```Java
public class Principal{
	public static void main(String[] args){
		Produto p = new br.uepg.deinfo.Produto();
	}
}
```

> Toda aplicação *java* importa implicitamente o pacote *java.lang*, o qual inclui as classes String, System, Math, entre outras.

## Modificandor de acesso protected

- Métodos, contrutores e atributos definidos como `protected` (protegido) podem apenas ser acessados por classes incluídas no mesmo pacote e por classes geradas por herança. É importante perceber que, quando se utiliza métodos e atributos protegidos em conjunto com herança, automaticamente esses componentes serão também acessados por outras classes que estejam no mesmo pacote.
- Por exemplo, considere um pacote (*br.uepg.deinfo*) que possua duas classes:

1. Classe `Criança`: possui um construtor protegido, um atributo privado e um métod protegido.
2. Classe `Adulto`: possui um construtor público,um atributo protegido e um método público.

```Java
package br.uepg.deinfo

public class Crianca {
	private int idade;

	protected Crianca(int idade){
		this.idade = idade;
	}

	protected int getIdade(){
		return this.idade;
	}
}
```

```Java
package br.uepg.deinfo

public class Adulto {
	protected int idade;

	public Adulto(int idade){
		this.idade = idade;
	}

	public int getIdade(){
		return this.idade;
	}
}
```

- Se a classe *Principal* for declarada dentro do mesmo pacote, tem-se:

```Java
package br.uepg.deinfo

public class Principal{
	public static void main(String[] args){
		Crianca c = new Crianca(5);
		c.idade = 7;	// Não funciona!!!!
		System.out.println("Idade da criança é de "+c.getIdade()+" anos");
		Adulto a = new Adulto(30);
		a.idade = 35;
		System.out.println("Idade do adulto é de "+a.getIdade()+" anos");
	}
}
```

- Apenas o comando `c.idade = 7`, na linha 6, não vai funcionar, pois o atributo é privado e só pode ser acessado dentro da classe.
- Se a classe *Principal* apenas importar as classes `Adulto` e `Crianca`, ou seja, não fizer parte do pacote, tem-se:

```Java
import br.uepg.deinfo.Crianca;	// Importa as classes
import br.uepg.deinfo.Adulto;

public class Principal{
	public static void main(String[] args){
		Crianca c = new Crianca(5); 	// Não funciona!!!!
		c.idade = 7;	// Não funciona!!!!
		System.out.println("Idade da criança é de "+c.getIdade()+" anos");
		Adulto a = new Adulto(30);	// Não funciona!!!!
		a.idade = 35;	// Não funciona!!!!
		System.out.println("Idade do adulto é de "+a.getIdade()+" anos");
	}
}
```

- As linhas 6, 7 e 8 não vão funcionar, pois a classe *Crianca* possui atributo private e métodos (construtor e método *get*) protegidos, e a classe Principal não faz parte do pacote.
- Em relação à classe *Adulto*, será possível criar o objeto e executar o método *get* pois ambos são públicos, mas não será possível modificar o atributo (linha 10), pois ele é potegido.
- Quando não é definido explicitamente nenhum pacote, *java* cria um pacote padrão e considera que todas as classes que estiverem na mesma pasta farão parte desse pacote. Ou seja, sempre existerá um pacote, mesmo que o programador não crie.
- Atributos e métodos que não possuam modificador são considerados protegidos por *java*. Por isso é essencial que sempre sejam usados modificadores de acesso, pois mesmo que não sejam citados eles serão implicitamente definidos como `protected`.
