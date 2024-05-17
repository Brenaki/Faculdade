# Inferência em LPO

> V = Para todo, ] = Existe algum

- Fórmulas/Expressões Lógicas <-> Interpretação = Valor Verdade

> Exemplo: Sejam os objetos Luis, Carla, Eduardo  e os predicados

```
H = {Luis, Carla, Eduardo}   c = Carla
R = {Carla}                  e = Eduardo
M = {Luis, Eduardo}          l = Luis
```

- Interpreta
  - Pergunta-se:
    - (A) H(e) | .V.
    - (B) R(c) | .V.
    - (C) M(c) v M(e) | .V.
    - (D) VxM(x) | .F.
    - (E) ]xR(x) | .V.
    - (F) M(y) | Depende do valor substituido da variável, .F., .V., .V.
    - (G) ]xH(x)->M(y) | Nessa fórmula, o resultado depende do segundo x
    - (H) ]x(H(x)->M(y)) | .V.

- A dedução do valor verdade de uma expressão em *LPO* depende da interpretação associada aos símbolos do modelo e da forma da expressão. Particularmente, o escopo dos quantificadores afetam consideravelmente a definição do valor verdade.
- Nas expressões `V(Q) e ](Q)` a fórmula `Q()` é o escopo dos quantificadores. Os parênteses são utilizados para evitar interpretações ambíguas sobre o escopo e podem ser removidas quando não houver ambiguidade.

> Ex: Seja a sentença `Todo o número natural x tem um natural y, tal que, y é maior que x`

```
Vx(xEN -> ]y(yEN ^ y>x)) | Fórmula fechada
```

> Ex: `Em cada cidade Exite uma pessoa que nasceu lá`

```
Vx(Cidade(x) -> ]y(Pessoa(y) ^ Nasceu(y,x))) | Fórmula fechada
```

### Definições

- Uma variável x é dita ligada se ocorre dentro do escopo de um quantificador. Caso contrário diz que ela é livre.

> Ex: Vx(E(x)vD(y)) -> ]z(E(x)->(z,x))

- Uma fórmula `S` é uma sentença se, e somente se é fechada, isto é, não possui variaveis livre. 
  - Somente sentenças podem ser ditas verdadeiras ou falsas em LPO. 
  - Obviamente, a verdade ou falsidade de uma sentença depende da interpretação associada ao modelo.
- Definição: Uma sentença `S` é uma tautologia se, e somente se é verdadeira em qualquer interpretação.
  - Nesse caso diz que `S` é lógicamente válido.
- Uma sentença `S` é uma tautologia se for uma instância substitutiva de uma tautologia proposicional. 

## Infêrencia e Consequencia Lógica

- Sejam as sentenças 
  - William é um lógico
  - Todos os lógico usam chapéu
  - Logo, William usa chapéu 
```
L(w)  w = William; L = é um lógico; c = usa chapéu
VxL(x) -> C(x)
----
C(w)
```

- A noção de implicação lógica em LPO diz respeito as sentenças de determinadas conclusões (C) que nunca são falsas quando outras sentenças denominadas premissas (P1, P2, Pn) são verdadeiras, independente da interpretação. Isto é denotado por P1,P2,...,Pn |= C, em que P1,P2,...,Pn e C são sentenças em LPO. Um argumento P1,P2,...,Pn :. C é válido se, e somente se P1,P2,...,Pn |= C.
- Para verificarmos se `C` é consequencia lógica das premissas P1,P2,...,Pn podemos usar regras de infêrencia para mostrar que P1^P2^...^Pn -> C é uma tautologia ou que P1^P2^...^Pn^~C é uma contradição. Para efetuar esses testes podemos utilizar um conjunto de regras de infêrencia. Com tudo, em LPO temos um complicador, apresença de variaveis e quantificadores.

> Ex: Darwin, Lamarck | G: acredita que a evolução foi direcionada | B: Darwin 

```
G : {Lamarck}
](x)(G(x) -> G(B)) :. ](x) G(x) -> G(b)
```

- Dado que uma tautologia é verdadeira em qualquer interpretação e independente de premissas podemos escrever `|= Q, onde Q é uma tautologia`. reversamente `|=~Q, se Q é uma contradição`. Se `A|=B` e `B|=A`, `A` e `B` são **equivalentes**.
