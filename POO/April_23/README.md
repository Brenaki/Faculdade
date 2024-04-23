# Interfaces

- Interfaces são classes abstratas que possuem apenas métodos abstratos. Numa interface, os métodos são implicitamente *abstract* e *public*. Não é comum colocar atributos numa interface, mas se existirem, serão estáticos e constantes (*final*).
- Uma classe pode implementar diversas interfaces, e é uma maneira possível de *java* simular o recurso de herança múltipla.
- Por exemplo, considere que se queira implementar um sistema para representar objetos geométricos. A pergunta importante é: o que nós entendemos por um objeto geométrico?
- Do ponto de visto do sistema, nós podemos criar uma interface na qual estarão definidos todos os métodos que devem ser ofertados por uma classe que queira ser enquadrada como um tipo de objeto geométrico (ou seja, define o comportamento de um objeto geométrico).
- Como um exemplo simples, considera-se que todo objeto geométrico deve oferecer uma maneira de calcular a sua área. Levando isso em consideração, é possível criar uma interface que representa um objeto geométrico.

```java
public interface ObjetoGeometrico{
	double calcularArea();
}
```

- Um programador, para criar uma classe que seja um tipo de objeto geométrico, deve obrigatoriamente implementar a interface (usando a palavra reservada implements) e implementar os métodos nela definidos.
- Por exemplo, para criar uma classe chamada **Círculo**:

```java
public class Circulo implements ObjetoGeometrico{
	private double raio;

	public Circulo(double raio){
		this.raio = raio;
	}

	public double calcular calcularArea(){	// Método Obrigatório
		return Math.PI * raio * raio;
	}

	public void descreve(){
		System.out.println("Eu sou um círculo");
	}
}
```

- Através do uso de interfaces (ou classes abstratas) é possível criar um vetor polimórfico que possua objetos geométricos. Por exemplo, suponha que tenha sido criada uma classe chamada Quadrado e que ela também implemente a interface Objeto Geométrico.

```java
public class Principal{
	public static void main(String args[]){
		
		ObjetoGeometrico vetor[] = new ObjetoGeometrico[2];
		vetor[0] = new Circulo(2);
		vetor[1] = new Quadrado(3);
		for(int i=0;i<2;i++){
			System.out.println("Minha area é: "+vetor[i].calcularArea());
		}
	}
}
```

- É importante perceber que a criação da interface permitiu definir de maneira clara o que um objeto geométricos sem necessitar saber como as classes são implementadas. Basta usar os métodos definidos na interface.
- Porém, a classe Círculo possui um método chamado descreve(), o qual não foi definido na interface. Não é possível executar esse método a patir do vetor, pois ele só consegue acessar métodos que estejam definidos na interface.
- É importante lembrar que, através de polimorfismo, conseguimos referenciar um objeto de diferentes maneiras. Quando acessado através do vetor, o objeto é considerado um objeto geométrico (o que ele é), mas para acessaro método descreve(), ele precisa ser referenciado como um Círculo (o que ele também é). Ou seja, ele é um objeto geométrico, mas também é um círculo. O que define os métodos que podem ser acessados é o contexto, ou a maneira que nós referenciamos o objeto.
- Para referenciá-lo como um círculo, é necessário criar um identificador de objeto da classe *Círculo*, e fazer um *downcasting*. Ele tem esse nome pois estamos referenciando o objeto como uma classe herdeira, e por isso estamos *descendo* na hierarquia de heranças. Por exemplo:

```java
public class Principal{
	public static void main(String args[]){
		ObjetoGeometrico vetor[] = new ObjetoGeometrico[2];
		Circulo temp;

		vetor[0] = new Circulo(2);
		vetor[1] = new Quadrado(3);
		for(int i=0;i<2;i++){
			System.out.println("Minha área é: "+ vetor[i].calcularArea());
		}
		temp = (Circulo) vetor[0];	// downcasting
		temp.descreve();
	}
}
```

- Nesse caso, *temp* e *vetor[0]* referenciam o mesmo objeto, mas de maneiras diferentes. É importante perceber que o objeto é único, apenas a maneira que ele é referenciado é que muda.
- Interfaces e polimorfismo são recursos muito usados em padrões de projeto, e são ferramentas muito poderosas para organizar projetos orientados a objetos.
