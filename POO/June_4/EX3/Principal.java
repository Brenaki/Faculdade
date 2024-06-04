public class Principal {
  public static void main(String[] args) {
    Veiculo vet[] = new Veiculo[2];
    vet[0] = new Carro("BMW", 4);
    vet[1] = new Moto("Kawasaki");
    
    Carro tempC = (Carro) vet[0];
    Moto tempM = (Moto) vet[1];

   for (int i = 0; i < 2; i++) {
    vet[i].imprimirTipo();
   } 
  }
}
