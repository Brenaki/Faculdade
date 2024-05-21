public class Principal {
  public static void main(String[] args) {
    try {
      Carro c = new Carro();
      c.setPotencia(1);
      c.setModelo("");
    } catch (MinhaExcecao e) {
      System.out.println("Erro: "+ e.getMessage());
    }
  }  
}
