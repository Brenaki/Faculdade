public interface ItemDeBiblioteca {
  void empresta() throws MinhaExcecao;
  void devolve() throws MinhaExcecao;
  boolean estaEmprestado();
}
