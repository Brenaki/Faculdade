# Resolução de Sistemas lineares métodos diretos

- Dentre os métodos diretos podemos citar:
  - A regra de Cramer
  - Eliminação de Gauss
  - Decomposição L.U
  - Decomposição Cholesky

## O método de eliminação de Gauss

- Para fixar ideias considere o seguinte sistema linear de três incóguitas e três equações:

```math
  a11x1 + a12x2 + a13x3 = b1
{ a21x1 + a22x2 + a23x3 = b2
  a31x1 + a32x2 + a33x3 = b3
```

- A matriz ampliada do sistema é a matriz

```math
  a11 a12 a13 b1
[ a21 a22 a23 b2 ]
  a31 a32 a33 b3
```

- Considere os multiplicadores

```math
Mk1 = ak1   , onde k = 2,3
      ---
      a11
```

- A fim de eliminar os elementos a21 e a 31 faremos a seguinte operação elementar

```math
Lk <- Lk - Mk1L1  , onde k = 2,3
```

- Após essa etapa obtemos a matriz A¹ cujos elementos são obtidos pela operação anterior

```math
       a11¹ a12¹ a13¹ b1¹
A¹ = [ 0   a22¹ a23¹ b2¹ ] L2¹ <- L2 - M21L1
       0   a32¹ a33¹ b3¹   L3¹ <- L3 - M31L1
```

- E tal matriz A¹ = (aij¹) equivalente à A.
- A fim de eliminar a32 definimos o multiplicador `mk2 = ak2/a22`, k=3, e fazemos a operação elementar
  - `Lk² <- Lk¹ - Mk2L2¹` e assim, encontramos

```math
       a11² a12² a13² b1²
A² = [ 0    a22² a23² b2² ] 
       0    0    a33² b3²   L3² <- L3 - M32L2
```

- Encontramos assim A² equivalente à A e como está na forma escalonada torna mais fáaaaaacil determinar a solução do sistema. A saber

```math
x3 = b3² / a33²

x2 = b2² - a23²x3 / a22²

x1 = b1² - a13²x3 - a12²x2 / a11²
```

- Desde que a11², a22² e a33² sejam diferentes de zeros

- De maneira análoga podemos seguir este mesmo processo para sistemas lineares de oedens maiores, nxn.

### Exemplo

- Considere o sistema linear:

```math
  10x + 5y + 2z + w = 1
{ 2x  + 8y - 2z + w = 2}
{ 4x  + 5y + 20z+ w = 3}
  2x  - 3y + 22z + 2w = 1
```

- A matiz ampliada do sistema é

```math
      10 5  2  1  1  
A = [ 2  8  -2 1  2]
      4  5  20 1  3
      2  -3 22 2  1
```

- Consideremos os multiplicadores

```math
m21 = a21/a11 = 2/10 = 1/5

m31 = a31/a11 = 4/10 = 2/5

m41 = a41/a11 = 2/10 = 1/5
```

```math
       10 5     2   1    1  
A¹ = [ 0  7  -12/5 4/5  9/5] | 2 - (2/10) * 10 = 0
      0   3   98/5  1  13/5  | 4 - (4/10) * 10 = 0
      0  -4  108/5 9/5  4/5  | 2 - (2/10) * 10 = 0
```

- Repetindo o processo 3 vezes, chegamos que o sistema original é equivalente ao seguinte

```math
  10x + 5y + 2z + w = 1
{    35y - 12z + 4w = 9}
{         708z + 9w = 64}
                 2w = 0
```

- Logo, a solução do sistema é a seguinte:

```
w = 0/2 = 0

z = (64 - 9w)/708 = (64-0)/708 = 64/708 = 32/354 = 16/177

y = (9-4w+12z)/35 = (9-0+12(16/177))/35 = (9+(192/177)) = 1785/177 * 1/35 = 51/177 = 17/59

x = (1-w-2z-5y)/10 = (1-0-2*(16/177)-5(51/177))/10 = (1-(32/177)-(255/177))/10 = -110/177 * 1/10 = -11/177 
```

## Decomposição L.U

- A decomposição L.U é uma variante do método de eliminação de Gauss. Dizemos que uma matriz Anxn admite decomposição L.U se existem matrizes L e U triangulares inferior e superior, respectivamente, tais que
  - `A = L*U`

- Suponha que queremos resolver o sistema de equações lineares `Ax = b`, ou seja,

```math
 a11 a12 ... a1n
[a21 a22 ... a2n]
 .    .   .   .
 .    .   .   .
 .    .   .   .
 an1 an2 ... ann
```

- Suponha também que A admita decomposição LU , isto é, podemos escrever A como ainda L matriz trinagular inferior e U superior
- Assim, para resolvermos o sistema `Ax = b`, podemos resolver de maneira equivalente, dois sistemas de equações lineares mais simples

```math

{Ly = b} (sistema trinagular inferior)
 Ux = y  (sistema trinagular superior) 


b = Ly = L(Ux) = LUx = Ax
```

- Como saber se uma matriz admite decomposição L.U?
- Para responder precisamos dos seguintes conceitos:

1. Dizemos que uma matriz `Anxn = (ay)` é *diagonalmente dominante* se

```math
          n
|aii| >= E |aij|  , Vi = 1,2,...,n
          i=1
          j!=i
```

2. Dizemos que uma matriz `Anxn = (ay)` é *estutamente diagonalmente dominante* se

```math
          n
|aii| > E |aij|  , Vi = 1,2,...,n
          i=1
          j!=i
```

> **Teorema:** Toda matriz estritamente diagonalmente dominante possui decomposição L.U. Ou seja, se a matriz `Anxn = (ay)` é tal que

```math
          n
|aii| > E |aij|  , Vi = 1,2,...,n
          i=1
          j!=i
```

- Então A pode ser escrito como `A = LU`, onde L e U são triangulares inferior e superior, respectivamente. Além disso, `L = (mij)` onde `mii = 1` para todo `i=1,2,...,n, e mij, com i!=j` são os multiplicadores do processo                               de eliminação de Gauss da matriz `A = (aij)` e a matriz `U = (uij)` é a matriz resultante desse processo.

### Exemplo

- A matriz dada por A:

```math
      7 1 2 2
A = [ 1 4 0 1 ]
      2 1 8 1
      1 1 1 7
```

- é estritamente diagonalmente dominante, pois

```math
7 = |7| > |1|+|2|+|2| = 5

4 = |4| > |1|+|0|+|1| = 2

8 = |8| > |2|+|1|+|1| = 4

7 = |7| > |1|+|1|+|1| = 3


     1      0      0    0     7    1     2    2
A = [1/7    1      0    0] * [0  27/7  -2/7  5/7]
     2/7  5/25     1    0     0    0  202/27 8/27
     1/7  2/9  21/202   1     0    0     0   659/101
```

- U é obtida por eliminação de Gauss em A e L é a matriz dos multiplicadores

```math
   1    0  0   0
L [m21  1  0   0]
   m31 m32 1   0
   m41 m42 m43 1
```

### Exemplo

- A matriz

```math
     10  5  2  1
A = [2   8 -2  1]
     4   5  20 1
     2  -3  22 2
```

- não é estritamente diagonalmente dominante, pois na linha 4 temos `2 = |2| < |2|+|-3|+|22| = 27`
- No entanto admite decomposição L.U
