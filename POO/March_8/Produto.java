public class Produto {
   private String nome;
   private double preco;
   private int qtd;
   
   // Construtor nome, qtd e preço
   public Produto(String nome, int qtd, double preco){
      this.nome = nome;
      this.qtd = qtd;
      this.preco = preco;
   }
   
   // Construtor nome e preço
   public Produto(String nome, double preco){
      this.nome = nome;
      this.preco = preco;
   }
   
   // Altera nome do produto
   public void setNome(String nome){
      if(nome.equals("")) System.out.println("\nNome nao pode ser vazio");
      else this.nome = nome;
   }
   public String getNome(){
      return this.nome;
   }
   
   // Altera preço do produto
   public void setPreco(double preco){
      if(preco > 0) this.preco = preco;
      else System.out.println("\nPreco e menor que 0");
   }
   public double getPreco(){
      return this.preco;
   }
   
   // Altera a quatidade do produto
   public void setQtd(int qtd){
      if(qtd>0) this.qtd = qtd;
      else System.out.println("\nQuantidade e menor que 0");
   }
   public int getQtd(){
      return this.qtd;
   }
   
   // Faz a venda de um produto, diminuindo ele em estoque
   public void vender(int qtd){
      if(qtd > 0 && qtd <= this.qtd) this.qtd -= qtd;
      else System.out.println("\nNao ha estoque desse produto");
   }
   
   // Faz a compra do produto, para ser vendido, aumenta a qtd em estoque
   public void comprar(int qtd){
      if(qtd>0) this.qtd += qtd;
      else System.out.println("\nNao se pode comprar qtds menores que 0");
   } 
   
   // Mostra os dados do produto
   public void imprimir(){
      System.out.println("\nInformacoes do Produto:");
      System.out.println("Nome do produto: " + this.nome);
      System.out.println("Preco do produto: R$" + this.preco);
      System.out.println("Quatidade do produto: " + this.qtd +"\n");
   }

}