public class Aluno extends Pessoa{
	private String ra;
	private int disciplinas;
	private boolean matricula;

	public Aluno(String nome, String telefone, Data nascimento, String ra) {
		super(nome, telefone, nascimento);
		this.ra = ra;
		matricula = false;
	}

	public Aluno(String nome, Data nascimento, String ra){
		super(nome, nascimento);
		this.ra = ra;
		matricula = false;
	}

	public void setRA(String ra){
		if(ra.equals("")) System.out.println("RA não pode ser vazio");
		else this.ra = ra;
	}

	public String getRA(){
		return this.ra;
	}

	public void setDisciplinas(int disciplinas){
		if(disciplinas > 0) this.disciplinas = disciplinas;
		else System.out.println("O aluno não pode possuir disciplinas negativas!");
	}

	public int getDisciplinas(){
		return this.disciplinas;
	}

	public void matricular(int disciplinas){
		if(disciplinas > 0){
			this.disciplinas = disciplinas;
			this.matricula = true;
		}
		else System.out.println("O aluno não pode possuir disciplinas negativas!");
	}

	public double getCargaSemanal(){
		return this.disciplinas * 4;
	}

	public String toString(){
		String temp;
		temp = super.toString() + "\nRA: " + this.ra;
		if(this.matricula == true){
			temp = temp + "\nAluno está matriculado\nDisciplinas: "+this.disciplinas + "Carga Horaria Semanal: "+getCargaSemanal();
		} else {
			temp = temp + "\nAluno não está matriculado";
		}
		return temp;
	}
}
