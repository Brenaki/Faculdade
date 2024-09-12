# Aula 08 

## Problema do par mais próximo

- distâncias
- métricas
- ex. distância euclidiana

```math

dX1X2 =sqrt((X2-X1)²+(Y2-Y1)²)
```

`n` pontos

quantos pares de ponto?

```math

(n) = n(n-1)
(2)     2
```

- Ordenar: `O(n*log2(n))`
- Varredura: `T(n)`
- Total: `O(n*log2(n))`

```
T(n)

t(n) = 2*t(n/2) + T(n)

t(n) = T(n*log2(n))
```

## Método Mestre

T(n) = a*T(n/b)+f(n)

- a = número de subproblemas
- n/b = tamanho dos subproblemas
- f(n) = tempo gasto na parte não recursiva do algoritmo

**3 casos**

Soluções:
1. T(n) = O(n^logb(a))
2. T(n) = O(n^logb(a) * log2(n))
3. T(n) = O(f(n))

**Caso 1:**

Se f(n) = O(n^logb(a)-E), então T(n) = O(n^logb(a))

**Caso 2:**

Se f(n) = OT(n^logb(a)), então T(n) = OT(n^logb(a) * log2(n))

**Caso 3:**

Se f(n) = W(n^logb(a)+E) e a*f(n/b) <= cf(n) para alguma constante c < 1 e n suficientemente grande.

### Exemplo

1. T(n) = 3*T(n/2)+cn

a = 3

b = 2   cn    n^logb(a) = n^1.585

f(n) = cn    f(n) = O(n^logb(a)-E)

Caso 1:

T(n) = OT(n^log2(3))

