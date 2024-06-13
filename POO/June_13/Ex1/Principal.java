import javax.swing.JOptionPane;

public class Principal {
  public static void main(String[] args) {
    Livro vet[] = new Livro[2];
    
    vet[0] = new LivroDeBiblioteca("Java", "Deitel", 2000);
    vet[1] = new LivroDeLivraria("C++", "Deitel", 2000);
        
    LivroDeBiblioteca livro1 = (LivroDeBiblioteca) vet[0];
    LivroDeLivraria livro2 = (LivroDeLivraria) vet[1];

    do {
      try {
        Biblioteca(livro1);
        Livraria(livro2);
  
        // Mostrando os livros
        JOptionPane.showMessageDialog(null, livro1);
        JOptionPane.showMessageDialog(null, livro2);
  
        return;
      } catch(MinhaExcecao e) {
        JOptionPane.showMessageDialog(null, e.getMessage());
      } catch(ClassCastException e) {
        JOptionPane.showMessageDialog(null, "Erro de cast!");
      } catch(NumberFormatException e) {
        JOptionPane.showMessageDialog(null, "Erro de formato!");
      }
    } while (true);
  }

  public static void Biblioteca(LivroDeBiblioteca livro) throws MinhaExcecao{
    // Biblioteca
    livro.informar();
    JOptionPane.showMessageDialog(null, livro, "Livro", JOptionPane.INFORMATION_MESSAGE);
    livro.empresta();
    livro.avaliar();
    livro.devolve();
  }

  public static void Livraria(LivroDeLivraria livro) throws MinhaExcecao{
    // Livraria
    livro.informar();
    JOptionPane.showMessageDialog(null, livro, "Livro", JOptionPane.INFORMATION_MESSAGE);
    livro.setPreco(92.9);
    JOptionPane.showMessageDialog(null, "Preço: " + livro.getPreco(), "Valor do livro", JOptionPane.INFORMATION_MESSAGE);
    livro.avaliar();
  }
}
