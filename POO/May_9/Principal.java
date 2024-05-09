package br.brenaki.main;
import br.brenaki.Aluno;
import javax.swing.JOptionPane;

public class Principal {
	public static void main(String[] args){
		Aluno vet[] = new Aluno[2];
		vet[0] = new Aluno();
		vet[0].setNome("Victor");
		vet[0].setMedia(9);
		do{	
			try{
			String qAluT = JOptionPane.showInputDialog(null, "Quais dos alunos você gostaria de atualizar os dados:");
			if(qAluT == null) return;
				int qAlu = Integer.parseInt(qAluT) - 1;
				
				String nome = JOptionPane.showInputDialog(null, "Digite o nome do aluno:");
				if(nome == null) return;
				vet[qAlu].setNome(nome);
			
				String somaNotaT = JOptionPane.showInputDialog(null, "Digite a soma das notas desse aluno:");
				if(somaNotaT == null) return;
				int somaNota = Integer.parseInt(somaNotaT);

				String totalProvaT = JOptionPane.showInputDialog(null, "Digite a quantidade de provas:");
				if(totalProvaT == null) return;
				int totalProva = Integer.parseInt(totalProvaT);
				
				vet[qAlu].setMedia(somaNota/totalProva);

				System.out.println(vet[qAlu]);
				return;
			} catch(ArrayIndexOutOfBoundsException ex){
				System.out.println("Aluno não encontrado");
			} catch(NullPointerException ex){
				System.out.println("Não existe esse registro de aluno");
			} catch(ArithmeticException ex){
				System.out.println("O número de provas não pode ser zero!");
			} catch(NumberFormatException ex){
				System.out.println("O valor tem que ser inteiro!");
			}
		} while(true);
	}
}

