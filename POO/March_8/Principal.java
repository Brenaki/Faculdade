public class Principal {
   public static void main(String[] args){
      Produto vetor[];
      
      vetor = new Produto[3];
      
      vetor[0] = new Produto("Feijao - 1kg", 3, 5.98);
      vetor[1] = new Produto("Feijao - 2kg", 10.35);
      vetor[2] = new Produto("Feijao - 5kg", 1, 15.99);
      
      vetor[0].imprimir();
      vetor[1].imprimir();
      vetor[2].imprimir();
      
      // Alterando nome
      vetor[1].setNome("");
      vetor[0].setNome("Arroz - 2kg");
      System.out.println("Nome do produto 1: R$" + vetor[0].getNome());
      
      // Alterando preço
      vetor[2].setPreco(-1.1);
      vetor[1].setPreco(9.98);
      System.out.println("Preco do produto 2: R$" + vetor[1].getPreco());
      
      // Alterando quantidade
      vetor[0].setQtd(-1);
      vetor[2].setQtd(3);
      System.out.println("Quantidade produto 3: R$" + vetor[2].getQtd());
      
      // Vendendo
      vetor[0].vender(1);
      vetor[0].imprimir();
      vetor[1].vender(1);
      
      
      // Comprando
      vetor[1].comprar(1);
      vetor[1].imprimir();
      vetor[2].comprar(-1);
   
   }

}