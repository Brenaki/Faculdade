public class Data {
	private int dia;
	private int mes;
	private int ano;
	
	public Data(int dia, int mes, int ano){
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}

	public void setDia(int dia){
		if(dia > 31 || dia < 0) System.out.println("Dia inválido");		
		else this.dia = dia;
	}
	
	public int getDia(){
		return this.dia;
	}

	public void setMes(int mes){
		if(mes > 12 || dia < 0) System.out.println("Mês inválido");		
		else this.mes = mes;
	}
	
	public int getMes(){
		return this.mes;
	}
	
	public void setAno(int ano){
		if(ano < 2024) System.out.println("Ano deve ser maior que 2024");		
		else this.ano = ano;
	}
	
	public int getAno(){
		return this.ano;
	}

	public String toString(){
		String temp;
		temp = this.dia + "/" + this.mes + "/" + this.ano;
		return temp;
	}
}
