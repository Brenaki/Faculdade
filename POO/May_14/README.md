# E/S em Java

- Um fluxo (*stream*) de E/S representa um caminho pelo qual uma aplicação java pode se comunicar para receber dados de uma fonte (fluxo de entrada) ou enviar dados para um destino (fluxo de saída). A fonte ou destino dos dados podem ser: arquivos, interfaces de redes, sensores e atuadores etc.
- Por um fluxo podem trafegar diversos tipos de dados, como tipos primitivos (números, caracteres, por exemplo) ou objetos. Cada tipo de fluxo é representado por uma classe.
- Existem dois tipos básicos de fluxos: de *bytes* ou de caracteres.

- **Fluxo de bytes**: nesse tipo de fluxo, os dados são transportados em conjuntos de 8 bits (1 byte). Um fluxo de bytes é representado por uma classe que seja herdeira da classe `InputStream`(entrada) ou `OutputStream`(saída). Exemplos: `AudioInputStream`, `FileInputStream`, `ObjectInputStream`, etc.
- A manipulação de fluxos geram exceções que devem ser obrigatoriamente tratadas através de comandos `try`..`catch`. Quando um fluxo é criado, ele fica aberto e é obrigação do programador fechar os fluxos após o uso. Java oferece um recurso de fechamento automático de fluxos embutido no próprio comando `try`. Para isso, a criação dos fluxos deve ser feita em um conjunto de comandos inseridos entre parênteses na frente do comando `try`. Quando os comandos dentro do bloco `try`..`catch` terminarem, os fluxos são automaticamente fechados, mesmo que ocorra uma exceção.

```Java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;


public class ByteStream{
	public static void main(String[] args){
		try (FileInputStream entrada = new FileInputStream("teste.txt");
		    FileOutputStream saida = new FileOutputStream("saida.txt")){
			int valor;

			while((valor = entrada.read()) != 1){
				saida.write(valor);
			}
		} catch(IOException err){
			System.out.println(err.getMessage());
		}
	}
}
```

- No código (1) são criados dois fluxos de bytes: um de entrada (ligado ao arquivo texto.txt) e um de saída (ligado ao arquivo saída.txt). Fluxos FileInputStream e FileOutputStream são usados para comunicação com arquivos armazenados em memória secundária.
- **Fluxo de caracteres**: nesse tipo de fluxo, os dados são transportados como caracteres em formato UTF-8 (Unicode). Um fluxo de caracteres é representado por uma classe que seja
herdeira da classe Reader (entrada) ou Writer (saída). Exemplos: FileReader, StringReader etc.
- No código (2) são criados dois fluxos de caracteres: um de entrada (ligado ao arquivo texto.txt) e um de saída (ligado ao arquivo saída.txt). Fluxos FileReader e FileWriter são usados para comunicação com arquivos armazenados em memória secundária.

```Java
import java.io.FileReader;
import java.io.FileWrite;
import java.io.IOException;


public class Reader{
	public static void main(String[] args){
		try (FileReader entrada = new FileReader("teste.txt");
		    FileWrite saida = new FileWrite("saida.txt")){
			int valor;

			while((valor = entrada.read()) != 1){
				saida.write(valor);
			}
		} catch(IOException err){
			System.out.println(err.getMessage());
		}
	}
}
```


- **E/S com buffers**: Java oferece variações de fluxos de bytes e caracteres que podem usar buffers, oferecendo uma possível melhor eficiência de leitura e escrita nos fluxos. Por exemplo: BufferedReader e BufferedOutputStream. O uso de buffers é opcional. No caso do exemplo mostrado no código (2), a criação dos fluxos seria feita conforme mostrado no código (3).

```Java
import java.io.BufferedReader;
import java.io.BufferedWrite;
import java.io.FileReader;
import java.io.FileWrite;
import java.io.IOException;

public class Buffer{
	public static void main(String[] args){
		try (BufferedReader entrada = new BufferedReader(new FileReader("teste.txt"));
		    BufferedWrite saida = BufferedWrite(new FileWrite("saida.txt"))){
			int valor;

			while((valor = entrada.read()) != 1){
				saida.write(valor);
			}
		} catch(IOException err){
			System.out.println(err.getMessage());
		}
	}
}
```

- Os exemplos mostrados neste texto envolvem apenas arquivos-texto e transmissão de caracteres, mas é possível transmitir qualquer tipo de informação por fluxos, bastando apenas mudar o tipo de fluxo. Exemplos:
	- `DataInputStream` e `DataOutputStream`: transmitem dados de tipos primitivos.
		- Exemplos: int, double, char, boolean, String etc.
	- `ObjectInputStream` e `ObjectOutputStream`: transmitem objetos. A única mudança em uma classe que gerará objetos que serão transmitidos por fluxos é que elas implementem a interface Serializable, pois um objeto passa por um processo de serialização antes de ser transmitido.

- As classes `Scanner` (leitura) e `PrintWriter` (escrita) podem ser usadas em conjunto com fluxos para fazer a leitura ou escrita formatada.
