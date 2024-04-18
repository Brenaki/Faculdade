public class Data{
	private int dia;
	private int mes;
	private int ano;

	public Data(int dia, int mes, int ano){
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}

	public Data(int dia, int mes){
		this.dia = dia;
		this.mes = mes;
	}

	public void setDia(int dia){
		if(dia>31 && dia<0){
			System.out.println("Dia inválido!");
			return;
		}
		this.dia = dia;
	}

	public int getDia(){
		return this.dia;
	}
	
	public void setMes(int mes){
		if(mes>12 && mes<0){
			System.out.println("Mês inválido!");
			return;
		}
		this.mes = mes;
	}

	public int getMes(){
		return this.mes;
	}	

	public void setAno(int ano){
		if(ano<2024){
			System.out.println("Ano inválido!");
			return;
		}
		this.ano = ano;
	}

	public int getAno(){
		return this.ano;
	}

	public String toString(){
		String temp;
		if(getAno() == 0){
			temp = getDia()+"/"+getMes();
		}
		else temp = getDia()+"/"+getMes()+"/"+getAno();
		return temp;
	}
}
