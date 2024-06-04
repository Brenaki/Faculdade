public abstract class Veiculo {
  private String marca;

  public Veiculo(String marca){
    this.marca = marca;
  }

  public void setMarca(String marca) {
    if(marca.equals("")) System.out.println("O nome da marca não pode ser vazio!");
    else this.marca = marca;
  }

  public String getMarca(){
    return this.marca;
  }

  public abstract void imprimirTipo();
}
