# Teste de paradas absolutas e relativas

Para o método de Gauss - Seidel também usamos como teste de parada os erros absolutos e relativo

```math
 k         k    k-1
d = max | Xi - Xi |
  1<=i<=n

 k    k
d  = d
 r  ---
         k
    max|Xi|
    1<=i<=n
```

Uma condição suficiente para a convergência do método de Gauss - Seidel:

**Teorema:**(Critério de Sassenfeld): Seja `A=(aij)` uma matriz quadrada de ordem `n`. Seham também Bj, j = 1,2,...,n dados por

```math

b1 = Somatória |a1j|
            -----------
               |a11|


      i=1                     n
Bi = Somatória |aij|        Somatória |aij|
      j=1   -----------Bj +   j=i+1  ---------
               |aii|                  |aii|
```

Se `B = max {Bi} < 1`, então o método de Gauss - Seidel converge, isto é, gera uma sequência `x^k` que converge para a solução do sistema, independente da aproximação inicial `x⁰` tomada.

### Exemplo: Considere o sistema de equações lineares

```math
[10 2 0 1] [x1] = [10]
[5 10 1 0] [x2] = [2]
[0 1 4 1] [x3] = [8]
[0 0 -1 6] [x4] = [3]


b1 = 1/10(2+0+1) = 3/10

b2 = 1/10(5*b1+1+0) => 1/10*25/10 => 25/100 = 1/4

b3 = 1/4(0*b1 + 1*b2 + 1) => 1/4(1/4+1) => 1/4*5/4 = 5/16

b4 = 1/6(0*b1+0*b2+1*b3) => 1/6(5/16) = 5/96

= B = max{b1, b2, b3, b4} = b3 < 1
```

Logo, a matriz satisfaz o Critério de Sassenfeld e assim o método de Gauss - Seidel converge para este sistema.

Observações: 
    1. O critério de Sassenfeld é uma condição suficiente e não necessária, isto é, pode haver uma matriz que não o satisfaça e ainda assim o método convirja.
    2. Podemos fazer operações elementares nas matrizes de forma que em uma nova confinguração(equivalente) isto satisfaça o critério.

**Teorema:** Seja `A=(aij)` uma matriz de ordem `n`. Se `A` satisfaz o Critério de Linhas, então ela também satisfaz o Critério de Sassenfeld.

Observações:
    1. Pelo Teorema anterior podemos também usar o Critério de Linhas para afirmar a convergência do método de Gauss - Seidel.
    2. A recíproca do Teorema anterior não é verdadeira, isto é, `Sassenfeld !=> Linhas`

### Por exemplo:

```math
    [5 1 2]
A = [4 6 3]
    [1 3 6]
```

Critério de Linhas: 
    - `l1 = 1/5(1+2) = 3/5`
    - `l2 = 1/6(4+3) = 7/6`
    - `l3 = 1/6(1+3) => 4/6 = 2/3`
    - `=> L = max{l1,l2,l3} = l2 = 7/3 > 1`

Logo, o Critério de Linhas não é satisfeito

Critério de Sassenfeld: 
    - `b1 = l1 = 3/5`
    - `b2 = 1/6(4*b1+3)`
    - `b2 = 1/6(12/5+3) = 2/5 + 1/2 = 4+5/10`
    - `b2 = 9/10`
    - `b3 = 1/6(1*b1+3*b2)`
    - `b3 = 1/10 + 9/20`
    - `b3 = 11/20`
    - `=> B = max{b1,b2,b3} = b2 = 0.9 < 1`

Logo, o Critério de Sassenfeld é satisfeito

