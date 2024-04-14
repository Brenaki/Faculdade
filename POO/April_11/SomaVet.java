import java.util.Arrays;

public class SomaVet {

  public static int somar(int vet[]) {
    int soma = 0;
    for (int i = 0; i < vet.length; i++) {
      soma += vet[i];
    }
    return soma;
  }

  public static float media(int vet[]) {
    int soma = somar(vet);
    float media = soma / vet.length;
    return media;
  }

  public static void imprimir(int vet[]) {
    System.out.printf("Itens dentro do vetor: ");
    for (int i = 0; i < vet.length; i++) {
      System.out.printf("%d ", vet[i]);
    }
    System.out.println("");
  }

  public static void ordenar(int vet[]) {
    for (int i = 0; i < vet.length; i++) {
      for (int j = 0; j < vet.length; j++) {
        if (vet[i] < vet[j]) {
          int aux = vet[i];
          vet[i] = vet[j];
          vet[j] = aux;
        }
      }
    }
  }

  public static void buscaBinaria(int vet[], int valor) {
    int value = Arrays.binarySearch(vet, valor);
    System.out.println("Valor " + valor + " encontrado na posição " + value);
  }
}
