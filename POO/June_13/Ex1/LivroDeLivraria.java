import javax.swing.JOptionPane;

public class LivroDeLivraria extends Livro{
  private double preco;

  public LivroDeLivraria(String nomeLivro, String nomeAutor, int anoEdicao, int avaliacao, double preco) {
    super(nomeLivro, nomeAutor, anoEdicao, avaliacao);
    this.preco = preco;
  }

  public LivroDeLivraria(String nomeLivro, String nomeAutor, int anoEdicao, int avaliacao) {
    super(nomeLivro, nomeAutor, anoEdicao, avaliacao);
  }

  public LivroDeLivraria(String nomeLivro, String nomeAutor, int anoEdicao, double preco) {
    super(nomeLivro, nomeAutor, anoEdicao);
    this.preco = preco;
  }

  public LivroDeLivraria(String nomeLivro, String nomeAutor, int anoEdicao) {
    super(nomeLivro, nomeAutor, anoEdicao);
  }

  public void setPreco(double preco) throws MinhaExcecao{
    if(preco < 0) throw new MinhaExcecao("Preço inválido!");
    else this.preco = preco;
  }

  public double getPreco() {
    return this.preco;
  }

  public void informar() {
    JOptionPane.showMessageDialog(null, "Sou uma livraria!");
  }

  public String toString() {
    if(this.preco != 0) return super.toString() + "\nPreço: " + this.preco;
    else return super.toString();
  }
}
