# Apresentação da Diciplina

- Metodologia
  - Aulas expositivas
  - Resolução de Problemas
  - *Trabalhos*
  - Exercícios
  - Avaliação escritas

- Critérios de Avaliação
  - Prova 1 (30%)
  - Prova 2 (60%)
  - Exercícios (10%)

- Programa da Disciplina
  - Ferramentas para Análise de Algoritmos
    - Notação Assintótica
    - Indução Matemática e Algoritmos
    - Equações de Recorrência
  - Técnicas de Projeto de Algoritmos
    - Ordenar e Varrer
    - Método Guloso
    - Divisão e Conquista
    - Força Bruta (backtracking, ramificação e corte)
    - Programação Dinâmica
  - Algoritmos de Ordenação
  - Algoritmos em Grafos
    - Representação de Grafos
    - Busca em Grafos
    - Problema da Árvore Espalhada de Custo Mínimo
    - Problemas de Caminhos de Custo Mínimo
  - Complexidade Computacional
    - Classes de Problemas
    - Classes P e NP
    - Redução entre Problemas

- Bibliografia
  1. T. H. Cormen, C. E. Leiserson, R. L. Rivest, C. Stein, Algoritmos - teoria e prática, 3a edição, 2012, Ed. Campus.
  2. T. H. Cormen, Desmistificando Algoritmos, 1a Edição, 2013, Ed. Campus.
  3. J. L. Szwarcfiter  - Teoria Computacional de Grafos, Grupo GEN, 2018. 
  4. N. Ziviani, Projeto de Algoritmos. Com Implementações em Pascal e C, 3a edição, 2010, Ed. Cengage.
  5. S. Dasgupta, C. Papadimitriou, U. Vazirani, Algoritmos, 1a edição, 2009.
  6. R. Sedgewick, K. Wayne, Algorithms, 4th Edition, 2011.
  7. B. Miller e D. Ranum, Problem Solving with Algorithms and Data Structures Using Python, 2011. 
  8. K. H. Rosen, Matemática Discreta e Suas Aplicações,  Ed. Mc Graw Hill, 2009.

# Problema TRIÂNGULOS

- São dados `N` pontos em uma circuferencia. Você deve escrever um programa que determine quantos triângulos equiláteros distintos podem ser construidos usando esses pontos com vétices.

### Exemplos
Entrada | Saída
:-- | --:
8 | 2
4 2 4 2 2 6 2 2 |

Entrada | Saída
:-- | --:
6 | 1
3 4 2 1 5 3 |

### Resumo do problema

> Devemos contar o número de `triângulos equiláteros` formados pelos pontos dados

- Formula
  - Circuferência / 3

### Solução

- Seja `C` o comprimento da circuferencia
- Para que o ponto da posição `p` participe de um triângulo equilátero...
  - os pontos `p + c / 3` e `p + 2 * c / 3`
  - devemos estar no conjunto de pontos

#### Código | Solução Inicial - Busca Sequencial

```c
#include <stdio.h>
#define MAXN 100000

int main(){
  int N, x, i, circ, p2, p3;
  int num_triangulos = 0;
  int pontos[MAXN];
  
  // Busca Sequencial no Vetor
  int busca(int p, int *pontos, int n){
    int i;
    for(i=0;i<n;++i)
      if(pontos[i] == p)
        return 1;
    return 0;
  }

  // Leitura da entrada
  scanf("%d", &N);
  pontos[0] = 0;
  for(i=0; i=N-1; ++i){
    scanf("%d", &x);
    pontos[i+1] = pontos[i]+x;
  }

  // Calcula a circuferencia e trata o caso sem solução
  scanf("%d", &x);
  circ = pontos[N-1] + x;
  if(circ%3){
    printf("0\n");
    return 0;
  }
  
  // Percorrer o primeiro terço e faz uma busca pelos pontos p2 e p3
  for(i=0; pontos[i] < circ/3 && i<N; ++i){
    p2 = pontos[i] + circ/3;
    p3 = pontos[i] + 2*circ/3;

    if(busca(p2, pontos, N) && busca(p3, pontos, N)){
      num_triangulos++;
    }
  }
  printf("%d/n", num_triangulos);
  return 0;
}
```

- Complexidade de Tempo: O(n²)
- Tempo real: gcc -O2 (nível de otimização 2)

Algoritmo | Complexidade | Tempo
:-- | :-: | --:
Com Busca Sequencial | O(n²) | 9.244 segundos

- **O tempo limite do problema**: 2 segundos.

#### Código | Solução - Busca Binária (C)

```c
#include <stdio.h>
#define MAXN 100000

int main(){
  int N, x, i, circ, p2, p3;
  int num_triangulos = 0;
  int pontos[MAXN];
  
  // Busca Binária no Vetor
  int busca(int p, int *pontos, int n){
    int i;
    int m, left, right;
    left = 0; right = n-1;
    while(right>=left){
      m = (left+right)/2;
      if(p == pontos[m]) // achou
        return 1;
      if(p < pontos[m])
        right = m-1;
      else left = m+1;
    }
    return 0;
  }

  // Leitura da entrada
  scanf("%d", &N);
  pontos[0] = 0;
  for(i=0; i=N-1; ++i){
    scanf("%d", &x);
    pontos[i+1] = pontos[i]+x;
  }

  // Calcula a circuferencia e trata o caso sem solução
  scanf("%d", &x);
  circ = pontos[N-1] + x;
  if(circ%3){
    printf("0\n");
    return 0;
  }
  
  // Percorrer o primeiro terço e faz uma busca pelos pontos p2 e p3
  for(i=0; pontos[i] < circ/3 && i<N; ++i){
    p2 = pontos[i] + circ/3;
    p3 = pontos[i] + 2*circ/3;

    if(busca(p2, pontos, N) && busca(p3, pontos, N)){
      num_triangulos++;
    }
  }
  printf("%d/n", num_triangulos);
  return 0;
}
```

- Complexidade de Tempo: O(n*log(n))
- Tempo real: gcc -O2 (nível de otimização 2)

Algoritmo | Complexidade | Tempo
:-- | :-: | --:
Com Busca Sequencial | O(n²) | 9.244 segundos
Com Busca Binária (C) | O(n*log(n)) | 0.052 segundos
Com Busca Binária (STL) | ? | ?
Soulução Linear | ? | ?

#### Código | Solução - Busca Binária (STL)

```cpp
#include <stdio.h>
#define MAXN 100000

int main(){
  int N, x, i, circ, p2, p3;
  int num_triangulos = 0;
  int pontos[MAXN];

  // Leitura da entrada
  scanf("%d", &N);
  pontos[0] = 0;
  for(i=0; i=N-1; ++i){
    scanf("%d", &x);
    pontos[i+1] = pontos[i]+x;
  }

  // Calcula a circuferencia e trata o caso sem solução
  scanf("%d", &x);
  circ = pontos[N-1] + x;
  if(circ%3){
    printf("0\n");
    return 0;
  }
  
  // Percorrer o primeiro terço e faz uma busca pelos pontos p2 e p3
  for(i=0; pontos[i] < circ/3 && i<N; ++i){
    p2 = pontos[i] + circ/3;
    p3 = pontos[i] + 2*circ/3;

    if(binary_seach(pontos.begin(), pontos.end(), pontos[i] + circ/3) &&
    binary_seach(pontos.begin(), pontos.end(), pontos[i] + 2*circ/3) ){
      num_triangulos++;
    }
  }
  cout << num_triangulos << endl;
  return 0;
}
```

- Complexidade de Tempo: O(n*log(n))
- Tempo real: gcc -O2 (nível de otimização 2)

Algoritmo | Complexidade | Tempo
:-- | :-: | --:
Com Busca Sequencial | O(n²) | 9.244 segundos
Com Busca Binária (C) | O(n*log(n)) | 0.052 segundos
Com Busca Binária (STL) | O(n*log(n)) | 0.124 segundos
Soulução Linear | ? | ?

#### Código | Solução - Linear (Hash)

```c
#include <stdio.h>
#define MAXN 100000

int main(){
  int N, x, circ, circ3, i1, i2, i3;
  int num_triangulos = 0;
  int pontos[MAXN];

  // Leitura da entrada
  scanf("%d", &N);
  pontos[0] = 0;
  for(i=0; i=N-1; ++i){
    scanf("%d", &x);
    pontos[i+1] = pontos[i]+x;
  }

  // Calcula a circuferencia e trata o caso sem solução
  scanf("%d", &x);
  circ = pontos[N-1] + x;
  if(circ%3){
    printf("0\n");
    return 0;
  }
  
  circ3 = circ/3;
  i2 = 1;
  i3 = 2;
  for(i1=0; pontos[i1] < circ3 && i3 < N; ++i1){
    while(pontos[i2] < pontos[i1] + circ3)
      ++i2;
    while(pontos[i3] < pontos[i1] + 2*circ3)
      ++i3;
    if(pontos[i2] == pontos[i1] + circ3 && pontos[i3] == pontos[i1] + 2*circ3)
      num_triangulos++;
  }
  
  printf("%d\n", num_triangulos);
  return 0;
}
```

- Complexidade de Tempo: O(n)
- Tempo real: gcc -O2 (nível de otimização 2)

Algoritmo | Complexidade | Tempo
:-- | :-: | --:
Com Busca Sequencial | O(n²) | 9.244 segundos
Com Busca Binária (C) | O(n*log(n)) | 0.052 segundos
Com Busca Binária (STL) | O(n*log(n)) | 0.124 segundos
Soulução Linear | O(n) | 0.028 segundos

# Algoritmos Eficientes e Ineficientes

- Precisamos de Algoritmos mais rápidos?
  - Considere os dois Algoritmos:
    - Ordenação por Inserção: c1 n² operações
    - Ordenação por Combinação (Merge): c2 n*log(n) operações

  - Computador A(rápido): Ordenação por Inserção - O(n²)
    - Desenvolvedor bom
    - C/ Otimização no código
      - 2(10⁷)² instruções / 10¹⁰ instruções por segundo = 20000 segundos ou 5,5 horas
  
  - Computador B(lento): Merge Sort - O(n*log(n))
    - Desenvolvedor ruim
    - S/ Otimização no código
      - 50 * 10⁷log(10²) instruções / 10⁷ instruções por segundos = 1163 segundos < 20 minutos
  
  - Conclusão: um computador mais rápido pode não ser suficientemente rápido para fazer a execução de um algoritmo ruim terminar suficientemente rápido.
    - Ter um melhor algoritmo em mãos é melhor do que esperar os computadores ficarem maus rápidos.

- O que é um algoritmo eficiente?
  - A resposta depende da situação dos requisitos de tempo da situação.
  - Quanto tempo você pode esperar pela resposta?

## Algoritmo muito ineficientes

- Exemplo (2^n):
```c
void F(int n){
  if(n == 0)
    return ;

  F(n-1);
  F(n-1);
}

int main(){
  F(100);
}
```
