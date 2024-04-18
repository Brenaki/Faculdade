public class Endereco{
	private String rua;
	private int num;
	private String cidade;

	public Endereco(String rua, int num, String cidade){
		this.rua = rua;
		this.num = num;
		this.cidade = cidade;
	}

	public Endereco(String rua, int num){
		this.rua = rua;
		this.num = num;
	}

	public void setRua(String rua){
		if(rua.equals("")){
			System.out.println("Rua não pode ser vazio!");
			return;
		}
		this.rua = rua;
	}

	public String getRua(){
		return this.rua;
	}

	public void setNumero(int num){
		if(num<0){
			System.out.println("Número inválido");
			return;
		}
		this.num = num;
	}

	public int getNumero(){
		return this.num;
	}

	public void setCidade(String cidade){
		if(cidade.equals("")){
			System.out.println("Cidade não pode ser vazio!");
			return;
		}
		this.cidade = cidade;
	}

	public String getCidade(){
		return this.cidade;
	}

	public String toString(){
		String temp;
		temp = getRua() +", "+ getNumero() + " - "+ getCidade();
		return temp;
	}
}
