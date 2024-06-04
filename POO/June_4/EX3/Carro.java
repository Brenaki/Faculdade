public class Carro extends Veiculo{
  private int numeroDePortas;

  public Carro(String marca, int numeroDePortas){
    super(marca);
    this.numeroDePortas = numeroDePortas;
  }
  
  public void setNumeroDePortas(int numeroDePortas) {
    if(numeroDePortas > 0) this.numeroDePortas = numeroDePortas;
    else System.out.println("Número de portas não pode ser menor que zero!");
  }

  public int getNumeroDePortas() {
    return this.numeroDePortas;
  }

  public void imprimirTipo(){
    System.out.println("Eu sou um carro");
  }

  public String toString() {
    String temp;
    temp = "\nMarca: "+getMarca()+"\nNúmero de Portas: "+getNumeroDePortas();
    return temp;
  }
}
