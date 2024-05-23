import javax.swing.JOptionPane;

public class Principal {
  public static void main(String[] args) {
    try {
      ContaCorrente c = new ContaCorrente();
      
      String nome = JOptionPane.showInputDialog(null, "Digite seu nome:");
      if(nome == null) return;
      c.setNome(nome);
      
      String numero = JOptionPane.showInputDialog(null, "Digite o número da conta:");
      if(numero == null) return;
      c.setNumero(Integer.parseInt(numero));

     String dep = JOptionPane.showInputDialog(null, "Digite o valor que deseja depositar:");
     if(dep == null) return;
     c.depositar(Double.parseDouble(dep));
     
     JOptionPane.showMessageDialog(null, c.toString());
     System.out.println(c);

     String sac = JOptionPane.showInputDialog(null, "Digite o valor que desejar sacar:");
     if(sac == null) return;
     c.sacar(Double.parseDouble(sac));
      
     JOptionPane.showMessageDialog(null, c.toString());
     System.out.println(c);

      // Testes com código na mão:

      // c.setNome(""); OUTPUT: Erro: Nome não pode ser vazio!
      // c.setNome(" "); OUTPUT: Erro: Nome não pode ser um espaço vazio!
      
      
      // c.setSaldo(-1); OUTPUT: Erro: Saldo inválido!
      
      // c.sacar(0); OUTPUT: Erro: Não pode sacar o valor de zero!
      // c.sacar(-1); OUTPUT: Erro: Não pode sacar um valor negativo!
      // c.sacar(100); OUTPUT: Erro: Saldo insuficiente!

      // c.depositar(-1); OUTPUT: Erro: Você tentou depositar um número negativo!

    } catch(MinhaExcecao e) {
      JOptionPane.showMessageDialog(null, e.getMessage());
      System.out.println("Erro: "+e.getMessage());
    } catch(NumberFormatException e){
      JOptionPane.showMessageDialog(null, e.getMessage());
      System.out.println("Erro: "+e.getMessage());
    }
  }
}
