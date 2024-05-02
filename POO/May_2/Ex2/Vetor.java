package br.uepg.deinfo.primeiro;
import javax.swing.JOptionPane;


public class Vetor{
	private Pessoa vet[] = new Pessoa[3];
	private int posicao = 0;

	public void incluir(){
		String cod_t, nome, salario_t;
		cod_t = JOptionPane.showInputDialog(null, "Qual o código dessa pessoa:");
		if(cod_t == null || cod_t.equals("")) return;
		nome = JOptionPane.showInputDialog(null, "Qual o nome dessa pessoa:");
		if(nome == null || nome.equals("")) return;
		salario_t = JOptionPane.showInputDialog(null, "Qual o salário dessa pessoa:");
		if(salario_t == null || salario_t.equals("")) return;
		int cod = Integer.parseInt(cod_t);
		double salario = Double.parseDouble(salario_t);
		vet[posicao] = new Pessoa(cod, nome);
		vet[posicao].salario = salario;
		posicao++;
	}

	public void imprimir(){
		for(int i=0;i<posicao;i++){
			System.out.println(vet[i]);
		}
	}

	public void Jimprimir(){
		for(int i=0;i<posicao;i++){
			JOptionPane.showMessageDialog(null, "Código: "+vet[i].getCodigo()+"\nNome: "+vet[i].getNome()+"\nSalário: "+vet[i].salario);
		}
	}
}
