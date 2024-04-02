# Métodos e atributos estáticos

- Métodos e atributos estáticos podem ser acessados sem que seja criado um objeto. Por essa razão, os componentes estáticos são referenciados pelo nome da classe.

- Por exemplo:

```java
public class Vetor {
	public static void somar(int vetor[]) {
		int soma = vetor[0]
		for(int i = 1; i<vetor.lenght; i++){
			soma += vetor[i];
		}
		System.out.println("Soma do vetor e "+ soma);
	}
}
```

- Nesse caso, para executar o método, não é necessário criar o objeto antes. Por exemplo:

```java
public class Principal {
	public static void main(String[] args){
		int vetor[] = {5, 10, 5};
		Vetor.somar(vetor);
	}
}
```

- Se um método estático acessa diretamente um método ou um atributo da mesma classe na qual ele está inserido, tudo deve ser estático. Por exemplo:

```java
public class Classe {
	private static int atributo;  // Obrigatoriamente estático

	public static void imprime(){ // Obrigatoriamente estático
		System.out.println("Valor de atributo e " +atributo);
	}

	public static void main(String[] args){ // Método estático
		atributo = 5;
		imprime();
	}
}
``` 

- O método *main()*, pelo qual se inicia a execução de um programa em java, deve ser obrigadoriamente estático pois quando o programa inicia não há nenhum objeto criado. Se durante a execução não for criado nenhum objeto, o programa permanecerá em um contexto estático, o que não é recomendável quando se trabalha com uma linguagem orientada a objetos como java.

- A partir do momento em que são criados objetos, o programa sai do contexto estático. Por essa razão é importante sempre criar objetos e os métodos estáticos devem ser usados apenas para métodos genéricos que são usados para auxiliar a execução do programa, como por exemplo, uma biblioteca de funções estatísticas.

- Existem diversas classes em Java que possuem métodos estáticos, como *String*, *Arrays*, etc. Por exemplo, para transformar um número intero em uma *string*, pode ser usado o método *valueOf*, que é estático, e por isso ele é referenciado a partir da classe *String*.

```java
int numero = 10;
String str;
str = String.valueOf(10);
```
