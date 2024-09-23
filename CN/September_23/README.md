# Interpolação Polinomial

A interpolação polinomial tem por objetivo aproximar funções (tabeladas ou dadas por equações) por polinômios de grau até `n`. 

Isso tem o intuito de facilitar os cálculos das funções em pontos não conhecidos.

Interpolar significa calcular pontos intermediários não dados

Dados os (n+1) pontos (x0, f(x0)), (x1, f(x1)), ..., (xn, f(xn)), queremos aproximar `f(x)` por um polinômio, `P(x)` de grau no máximo `n`.

Tal que `Pn(xi) = f(xi), Vi = 0.1, ..., n`

Tal polinômio é chamado de Polinômio interpolador de `f` que interpola `f` nos `(n+1)` pontos `(x0, y0) = (x0, f(x0))`, `(x1,y1) = (x1, f(x1))`, ..., `(xn, yn) = (xn, f(xn))`.

**Teorema**: O polinômio interpolador de `f(x)` sobre os `(n+1)` pontos `(x0,y0)`, `(x1,y1)`, ..., `(xn, yn)`, onde `x0`, `x1`, ..., `xn` são distintos, existe e é único.

**Demonstração**: Seja `Pn(x) a0 + a1x + a2x² + ... + anx^n`

um polinômio que interpola `f(x)` nos pontos `(x0,y0)`, `(x1,y1)`, ..., `(xn, yn)`. Assim:
    
- Pn(x0) = y0 <=> a0+a1x0+a2x0²+...+anx0^n = y0
- Pn(x1) = y1 <=> a0+a1x1+a2x1²+...+anx1^n = y1
- Pn(x2) = y2 <=> a0+a1x2+a2x2²+...+anx2^n = y2
- ...
- Pn(xn) = yn  <=> a0+a1xn+a2xn²+...+anxn^n = yn

Temos portanto um sistema de `(n+1)` equações e `(n+1)` incógnitas: `a0,a1,a2,...,an`.

Na forma matricial `Ax=b`, onde

```math
    [1 x0 x0² ... x0^n]     x = [a0] , b = [y0] 
A = [1 x1 x1² ... x1^n]         [a1]       [y1]
    [1 x2 x2² ... x2^n]         [a2]       [y2]
    [.  .  .   .   .  ]         [.]        [.]
    [1 xn xn² ... xn^n]         [an]       [yn]
```

A matriz `A` é uma matriz de Vandermande, então `detA!=0` e o sistema admite única solução, ou seja, existem únicos `a0,a1,a2,...,an` que satisfazem os sistema, e e possua vez, únicos coeficientes `a0,a1x,a2x²,an` que torna o polinômio `Pn(x)=a0+a1x+x2x²+...+anx^n` o polinômio que interpola os pontos `(x0,y0)`, `(x1,y1)`, ..., `(xn,yn)`.

## Forma de obter `Pn(x)`

- Resolução de sistema linear

**Por exemplo**: Vamos encontrar o polinômio de grau no máximo 2 que interpla ns seguintes pontos

**Tabela 1**
x | f(x)
:-- | --:
x0 = -1 | 4 = y0
x1 = 0 | 1 = y1
x2 = 2 | -1 = y2

Considere `P2(x) = a0+a1x+a2x²`, onde `a0`, `a1` e `a2` senão determinados de modo que `P2(x)` interpole os pontos dados. 

Então, devemos ter

```math
{P2(x0) = y0    <=> {P2(-1) = 4
{P2(x1) = y1    <=> {P2(0) = 1
{P2(x2) = y2    <=> {P2(2) = -1

<=> {a0 + a1*(-1) + a2(-1)² = 4
<=> {a0 + a1*0 + a2*0² = 1
<=> {a0 + a1*2 + a2*2² = -1


<=> {a0 - a1 + a2 = 4
<=> {a0 = 1
<=> {a0 + 2a1 + 4a2 = -1


a2 = 4 - 1 + a1     |   1 + 2 * a1 + 4*(a1+3) = -1
a2 = a1 + 3         |   2a1 + 4a1 = - 1 - 1 - 12
a2 = -7/3 + 3       |   6a1 = -14
a2 = 2/3            |   a1 = -14/6 => -7/3
```

Portanto, `P2(x) = 1 - 7/3*x + 2/3x²` é o polinômio interpolados dos pontos dado.

## Fórmula de Lagrange

Seja `x0`, `x1`, ..., `xn` (n+1) pontos distintos e `yi = f(xi)`, `i=0,1,2,...,n`

Seja `Pn(x)` o polinômio de grau no máximo `n` que interpola `f` nos pontos `x0`, `x1`, `x2`, ..., `xn`

Vamos escrever

`Pn(x) = y0L0(x) + y1L1(x) + ... + ynLn(x)`, onde `Lk(x)` são polinômios de grau `n`.

Para que `Pn(x)` interpole os pontos, devemos ter `Pn(xi) = yi, i = 0,1,...,n`, ou seja, `Pn(xi) = y0L0(xi) + y1L1(x1) + ... + ynLn(xi) = yi`

Para isto, devemos ter `Lk(xi) = {0, se o k != i && 1, se k = i`

e com esse fim, definimos

`Lk(x) = ((x-x0)(x-x1)...(x-xk-1)(x-xk+1)...(x-xn)) / ((xk-x0)(xk-x1)...(xk-xk-1)(xk-xk+1)...(xk-xn))`

É fácil ver que `Lk(xk) = 1` e `Lk(xi) = 0` se `k!=i`

Além disso, o numerador de `Lk` tem `n` fatores da forma `(x-xi), i = 0,1,2,...,n`, para `i!=k`.

Então `Lk(x)` é um polinômio de grau `n`. Tais polinômios são chamados polinômis fundamentais de Lagrange.

Portanto, o polinômio interpolador de `f` nos pontos `(x0,y0)`, `(x1,y1)`, ..., `(xn,yn)` dad pela Fórmula de Lagrange é a seguinte:

```math
            n
Pn(x) = Somatório ykLk(x) = y0L0(x) + y1L1(x) + ... + ynLn(x)
            k=0
```

onde 

```math
    ---n---
Lk(x) | | (x-i)         (x-x0)(x-x1)...(x-xk-1)(x-xk+1)...(x-xn)
      | | -----     =   ----------------------------------------
      | | (xk-xi)       (xk-x0)(xk-x1)...(xk-xk-1)(xk-xk+1)...(xk-xn)
      i=0
      i!=k
```

**Exemplo**: Vamos encontrar `P2(x)` o polinômio que interpola os pontos (Tabela 1) pela Fórmula de Lagrange

Pela fórmula de Lagrange temos

```math
P2(x) = y0L0(x) + y1L1(x) + y2L2(x)
P2(x) = 4L0(x) + L1(x) - L2(x) (*)

L0(x) = (x-0)(x-2) / (-1+0)(-1-2) = 1/3(x²-2x)
L1(x) = (x+1)(x-2) / (0+1)(0-2) = 1/2(-x²+x+2)
L2(x) = (x+1)(x-0) / (2+1)(2-0) = 1/6(x²+x)
```

Voltando em (*), obtemos

```math
P2(x) = 4L0(x) + L1(x) - L2(x)
P2(x) = 4*1/3(x²-2x) + 1/2(-x²+x+2) - 1/6(x²+x)
P2(x) x²(4/3-1/2-1/6) + x(-8/3+1/2-1/6) + 1
P2(x) = x²(8-3-1 / 6) + x(-16+3-1 / 6) + 1
P2(x) = 2/3x²-7/3x+1
```

### Atividade 5

Use a fórmula de Lagrange para determinar o polinômio que interpola estes pontos:

xk | 0 | 1 | 2 | 3 | 4
:-- | :-: | :-: | :-: | :-: | --:
f(xk) = yk | 0 | 3 | 1 | 3 | 0
