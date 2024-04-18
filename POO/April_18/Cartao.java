public abstract class Cartao{
	private String dest;
	private String remet;
	private Endereco end;
	private Data data;

	public Cartao(String dest, String remet, Endereco end, Data data){
		this.dest = dest;
		this.remet = remet;
		this.end = end;
		this.data = data;
	}

	public Cartao(String dest, String remet, Data data){
		this.dest = dest;
		this.remet = remet;
		this.data = data;
	}

	public void setDestinatario(String dest){
		if(dest.equals("")){
			System.out.println("O destinátario não pode vazio!");
			return;
		}
		this.dest = dest;
	}

	public String getDestinatario(){
		return this.dest;
	}
	
	public void setRemetente(String remet){
		if(remet.equals("")){
			System.out.println("O destinátario não pode vazio!");
			return;
		}
		this.remet = remet;
	}

	public String getRemetente(){
		return this.remet;
	}

	public void mostrarMensagem(){
		System.out.println(mensagem());
	}

	public abstract String mensagem();

	public String toString(){
		String temp;
		temp = "\n\n"+this.data+"\nDestinatário: "+getDestinatario()+"\n"+this.end+"\n"+mensagem()+"\nRemetente: "+getRemetente()+"\n\n";
		return temp;

	}
}
