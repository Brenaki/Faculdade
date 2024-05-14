import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Reader{
	public static void main(String[] args){
		try (FileReader entrada = new FileReader("teste.txt");
		    FileWriter saida = new FileWriter("saida.txt")){
			int valor;

			while((valor = entrada.read()) != 1){
				saida.write(valor);
			}
		} catch(IOException err){
			System.out.println(err.getMessage());
		}
	}
}
