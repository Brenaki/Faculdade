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
