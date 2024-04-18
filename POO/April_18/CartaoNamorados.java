public class CartaoNamorados extends Cartao{
	
	public CartaoNamorados(String dest, String remet, Endereco end, Data data){
		super(dest, remet, end, data);
	}
	
	public CartaoNamorados(String dest, String remet, Data data){
		super(dest, remet, data);
	}

	public String mensagem(){
		return "Feliz Dia dos Namorados!";
	}
}
