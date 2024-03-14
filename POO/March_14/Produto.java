public class Produto {
   private String nome;
   private double preco;
   private int qtd;
   private Data validade;
   
   // Construtor nome, qtd, preço validade
   public Produto(String nome, int qtd, double preco, Data validade){
      this.nome = nome;
      this.qtd = qtd;
      this.preco = preco;
      this.validade = validade;
   }
   
   // Construtor nome, preço e validade
   public Produto(String nome, double preco, Data validade){
      this.nome = nome;
      this.preco = preco;
      this.validade = validade;
   }

   // Construtor nome e validade
   public Produto(String nome, Data validade){
	this.nome = nome;
	this.validade = validade;
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

   // Altera a Data
   public void setValidade(int dia, int mes, int ano){
	this.validade.setDia(dia);
	this.validade.setMes(mes);
	this.validade.setAno(ano);
   }

   // Sobrecarga alteração da Data
   public void setValidade(Data validade){
	this.validade = validade;
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
   public String toString(){
	String temp;
	temp = "\n**Informações do Produto**\nNome do produto: " + this.nome +"\nPreço do produto: R$" + this.preco + "\nQuantidade do produto: " + this.qtd + " un\nData de validade: " + this.validade;
	return temp;
   }
}
