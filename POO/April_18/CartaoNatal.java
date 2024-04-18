public class CartaoNatal extends Cartao{
	
	public CartaoNatal(String dest, String remet, Endereco end, Data data){
		super(dest, remet, end, data);
	}
	
	public CartaoNatal(String dest, String remet, Data data){
		super(dest, remet, data);
	}

	public String mensagem(){
		return "Feliz Natal!";
	}
}
