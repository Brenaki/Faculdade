public class Aluno extends Pessoa{
	private String ra;
	
	public Aluno(String nome, String telefone, Data nascimento, String ra) {
		super(nome, telefone, nascimento);
		this.ra = ra;
	}

	public Aluno(String nome, Data nascimento, String ra){
		super(nome, nascimento);
		this.ra = ra;
	}

	public void setRA(String ra){
		if(ra.equals("")) System.out.println("RA não pode ser vazio");
		else this.ra = ra;
	}

	public String getRA(){
		return this.ra;
	}

	public String toString(){
		String temp;
		temp = super.toString() + "\nRA: " + this.ra;
		return temp;
	}
}
