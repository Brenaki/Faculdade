public class Casa {
	private Porta frente;
	private Porta fundos;

	public Casa(Porta frente, Porta fundos){
		this.frente = frente;
		this.fundos = fundos;
	}
	
	public void abrirPortaFrente(){
		frente.abrir();
	}
	
	public void abrirPortaFundos(){
		fundos.abrir();
	}

	public void fecharPortaFrente(){
		frente.abrir();
	}

	public void fecharPortaFundos(){
		fundos.fechar();
	}

	public String toString(){
		String retorno;
		retorno = "Sou uma casa e tenho uma " + frente + " e uma " + fundos;
		return retorno;
	}

}
