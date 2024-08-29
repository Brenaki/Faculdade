# Resolvendo problemas

## Problema: Comparando Intervalo

- Entrada
  - `n` intervalos I1, I2, ..., In
  - tal que Ii = (Li, Ri)
  - Não há intervalos idênticos na entrada

Para Ii pertencer a Ij se Li >= Lj e Ri <= Rj

```pseudo
desmaracar todos os intervalos

Para i = 1 até n-1 faça
  Para j = i+1 até n faça
    Se Ii <= Ij
      Então marcar Ii
    Se Ij <= Ii
      Então marcar Ij
```

Para melhorar primeiro a gente ordena ele de forma crescendo quando o valor for
 igual e se for diferente ordenamos de forma descrescente, ai resolvemos de forma
 recursiva todos os intervalos que se cruzam, e no ultimo nos pegamos o valor
 `Rmax` que pode chegar e verificamos se o ultimo esta contido no penultimo

```pseudo
Se Rn <= Rmax
  Então marcar Rn
  Senão Rmax = Rn 
```

No fim devido a ele precisar orderna os seus intervalos ele gasta `O(n * log(n)) + O(n)`

Algoritmos assim são intitulados de *Ordena e varre*

## Equações de Recorrência

T(n) = número de comparações que o algoritmo executa para resolver uma entrada
 de tamanho `n`

T(n) = T(n-1) + 1 <- *equação de recorrência*

T(1) = 0

T(2) = T(1) + 1 = 1

T(3) = T(2) + 1 = 2

T(4) = 3

### Método da Iteração

T(n) = T(n-1) + 1 = T(n-2) + 1 + 1 = T(n-3) + 1 + 1 + 1 = K iterações

= T(n-k) + k

Qual é o valor de `k` para que o termo recorrente desapareça?

Qual é o valor de `k` para que T(n-k) = T(1)

n - k = 1

k = n - 1

para k = n-1, 0

T(n) = T(n-k) + k = T(1) + n-1 = n-1

#### prova por indução sobre n

> Base: n = 1, T(1) = 0 = n-1 = 1-1 = 0

- Passo
  - Hip. da indução: T(n-1) = n-2
  - Provar que T(n) = n-1
  - T(n) = T(n-1) + 1 = H.I
  - n-2 + 1 = n-1

### Busca binária

Pior caso.

T(n) = o número de comparações da busca binária em um vetor ordenado de tamanho `n`

T(n) = T(n/2) + 2

T(1) = 1

#### Provando busca binária

T(n) = T(n/2) + 2 =

T(n/4) + 2 + 2

T(n/8) + 2 + 2 + 2

K iterações

T(n) = T(n/2^k) + k*2

K = ? para T(n/2^k) = T(1)

n/2^k = 1 | n = 2^k

log2(n) = log2(2^k)

k = log2(n)

T(n) = T(1) + 2*log2(n) =

T(n) = 2log2(n) + 1
