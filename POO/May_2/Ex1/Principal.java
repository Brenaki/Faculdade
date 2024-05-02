import javax.swing.JOptionPane;

public class Principal{
	public static void main(String[] args){
		int choose = JOptionPane.showConfirmDialog(null, "Deseja saber o dobro de algum valor?");
		if(choose != 0) return;
		String value = JOptionPane.showInputDialog(null, "Digite um valor inteiro:");
		if(value == null || value.equals("")) return;
		int number = Integer.parseInt(value);
		JOptionPane.showMessageDialog(null, "O dobro do valor lido é "+ number*2);
	}
}
