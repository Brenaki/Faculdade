import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Buffer{
	public static void main(String[] args){
		try (BufferedReader entrada = new BufferedReader(new FileReader("teste.txt"));
		    BufferedWriter saida = new BufferedWriter(new FileWriter("saida.txt"))){
			int valor;

			while((valor = entrada.read()) != 1){
				saida.write(valor);
			}
		} catch(IOException err){
			System.out.println(err.getMessage());
		}
	}
}
