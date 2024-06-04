public class Moto extends Veiculo{

  public Moto(String marca){
    super(marca);
  }

  public void imprimirTipo(){
    System.out.println("Eu sou uma moto");
  }

  public String toString() {
    String temp;
    temp = "\nMarca: "+getMarca();
    return temp;
  }
}
