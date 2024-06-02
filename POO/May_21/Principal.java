public class Principal {
  public static void main(String[] args) {
    try {
      Carro c = new Carro();
      c.setPotencia(1);
      c.setModelo("V8");
      System.out.println(c);
    } catch (MinhaExcecao e) {
      System.out.println("Erro: "+ e.getMessage());
    }
  }  
}
