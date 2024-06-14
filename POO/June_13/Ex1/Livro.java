import javax.swing.JOptionPane;

public abstract class Livro {
  private String nomeLivro;
  private String nomeAutor;
  private int anoEdicao;
  private int avaliacao;

  public Livro(String nomeLivro, String nomeAutor, int anoEdicao, int avaliacao) {
    this.nomeLivro = nomeLivro;
    this.nomeAutor = nomeAutor;
    this.anoEdicao = anoEdicao;
    this.avaliacao = avaliacao;
  }

  public Livro(String nomeLivro, String nomeAutor, int anoEdicao) {
    this.nomeLivro = nomeLivro;
    this.nomeAutor = nomeAutor;
    this.anoEdicao = anoEdicao;
  }

  public void setNomeLivro(String nome) throws MinhaExcecao {
    if(!nome.matches("[A-Za-z ]*")) throw new MinhaExcecao("Nome do livro inválido!"); 
    if(nome.isEmpty()) throw new MinhaExcecao("Nome do livro não pode ser vazio!");
    if(nome.matches("[ ]*")) throw new MinhaExcecao("Nome do livro não pode ser um espaço vazio!");
    else {
      this.nomeLivro = nome;
    }
  }

  public String getNomeLivro() {
    return this.nomeLivro;
  }

  public void setNomeAutor(String nome) throws MinhaExcecao {
    if(!nome.matches("[A-Za-z ]*")) throw new MinhaExcecao("Nome do autor inválido!"); 
    if(nome.isEmpty()) throw new MinhaExcecao("Nome do autor não pode ser vazio!");
    if(nome.matches("[ ]*")) throw new MinhaExcecao("Nome do autor não pode ser um espaço vazio!");
    else {
      this.nomeAutor = nome;
    }
  }

  public String getNomeAutor() {
    return this.nomeAutor;
  }

  public void setAnoEdicao(int anoEdicao) {
    this.anoEdicao = anoEdicao;
  }

  public int getAnoEdicao() {
    return this.anoEdicao;
  }

  public void setAvaliacao(int avaliacao) throws MinhaExcecao {
    if (avaliacao < 0 || avaliacao > 10)
      throw new MinhaExcecao("Avaliação inválida! A nota deve ser entre 0 e 10.");
    else this.avaliacao = avaliacao;
  }

  public int getAvaliacao() {
    return this.avaliacao;
  }

  public void avaliar() throws MinhaExcecao {
    String avaliacao = JOptionPane.showInputDialog("Digite a avaliação do livro:");
    if(avaliacao == null) return;
    setAvaliacao(Integer.parseInt(avaliacao));
    JOptionPane.showMessageDialog(null, "Livro avaliado com sucesso!", "Avaliação", JOptionPane.INFORMATION_MESSAGE);
  }

  public abstract void informar();

  public String toString() {
    String temp;
    if(this.avaliacao == 0) {
      temp = "Nome do livro: " + this.nomeLivro + "\nNome do autor: " + this.nomeAutor + "\nAno de edição: " + this.anoEdicao + "\nAvaliação: Não avaliado!";
    } else {
      temp = "Nome do livro: " + this.nomeLivro + "\nNome do autor: " + this.nomeAutor + "\nAno de edição: " + this.anoEdicao + "\nAvaliação: "+ this.avaliacao;
    }
    return temp;
  }
}
