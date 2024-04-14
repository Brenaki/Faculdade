public class Principal {
  public static void main(String[] args) {
    int vet[] = { 2, 1, 5, 3, 5 };
    SomaVet.imprimir(vet);
    int soma = SomaVet.somar(vet);
    System.out.println("Valor total dentro do vetor: " + soma);
    float media = SomaVet.media(vet);
    System.out.println("Média de valores dentro do vetor: " + media);
    SomaVet.ordenar(vet);
    SomaVet.imprimir(vet);
    SomaVet.buscaBinaria(vet, 3);
  }
}
