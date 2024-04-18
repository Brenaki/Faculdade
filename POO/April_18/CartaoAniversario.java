public class CartaoAniversario extends Cartao{
	
	public CartaoAniversario (String dest, String remet, Endereco end, Data data){
		super(dest, remet, end, data);
	}
	
	public CartaoAniversario (String dest, String remet, Data data){
		super(dest, remet, data);
	}

	public String mensagem(){
		return "Feliz Aniversário "+ getRemetente()+"!";
	}
}
