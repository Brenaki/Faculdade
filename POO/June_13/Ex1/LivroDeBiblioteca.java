import javax.swing.JOptionPane;

public class LivroDeBiblioteca extends Livro implements ItemDeBiblioteca{
  private boolean emprestado; 
  
  public LivroDeBiblioteca(String nomeLivro, String nomeAutor, int anoEdicao, int avaliacao) {
     super(nomeLivro, nomeAutor, anoEdicao, avaliacao);
   }

  public LivroDeBiblioteca(String nomeLivro, String nomeAutor, int anoEdicao) {
    super(nomeLivro, nomeAutor, anoEdicao);
  }

  public void empresta() throws MinhaExcecao {
    if(estaEmprestado()) throw new MinhaExcecao("Livro já emprestado!");
    else { 
      this.emprestado = true;
      JOptionPane.showMessageDialog(null, "Livro emprestado com sucesso!"); 
    }
  }

  public void devolve() throws MinhaExcecao {
    if(!estaEmprestado()) throw new MinhaExcecao("Livro não está emprestado!");
    else {
      this.emprestado = false;
      JOptionPane.showMessageDialog(null, "Livro devolvido com sucesso!");
    }
  }

  public boolean estaEmprestado() {
    if(this.emprestado) return true;
    else return false;
  }

  public void informar() {
    JOptionPane.showMessageDialog(null, "Sou uma biblioteca!");
  }

  public String toString() {
    String temp;
    if(estaEmprestado()) temp = super.toString() + "\nSituação: Emprestado";
    else temp = super.toString() + "\nSituação: Dísponivel";
    return temp;
  }
}
