public class Principal {
   public static void main(String[] args){
      Produto vetor[];
      Data vdata[];	

      vetor = new Produto[3];
      vdata = new Data[3];

      vdata[0] = new Data(13, 6);
      vdata[1] = new Data(24, 8, 2026);
      vdata[2] = new Data(14, 9, 2029);
      
      vetor[0] = new Produto("Feijao - 1kg", 3, 5.98, vdata[0]);
      vetor[1] = new Produto("Feijao - 2kg", 10.35, vdata[1]);
      vetor[2] = new Produto("Feijao - 5kg", vdata[2]);
      
      System.out.println(vetor[0]);
      System.out.println(vetor[1]);
      System.out.println(vetor[2]);
      
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
      System.out.println(vetor[0]);
      vetor[1].vender(1);
      
      
      // Comprando
      vetor[1].comprar(1);
      System.out.println(vetor[1]);
      vetor[2].comprar(-1);
   
   }

}
