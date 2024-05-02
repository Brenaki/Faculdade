package br.uepg.deinfo.segundo;
import br.uepg.deinfo.primeiro.Vetor;
import javax.swing.JOptionPane;

public class Principal{
	public static void main(String[] args){
		Vetor v = new Vetor();
		String tam_t = JOptionPane.showInputDialog(null, "Quantas pessoas deseja inserir(1-3):");
		if(tam_t == null || tam_t.equals("")) return;
		int tam = Integer.parseInt(tam_t);
		for(int i=0;i<tam;i++){
			v.incluir();
		}
		v.imprimir();
		v.Jimprimir();
	}
}
