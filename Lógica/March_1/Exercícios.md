# Exercícios

1. Se a `demanda permanecer constante`(p) e `os preços aumentarem`(q), `o número de contratos vai cair`(r).
2. `Nós venceremos a eleição` (p), desde que `João seja eleito o líder do partido`(q).
3. Se `Jonas não for eleito líder do partido` (p), então `Samuel`(r) ou `Roney deixarão o ministério'(s). `Isto fará com que percam a eleição` (t).
4. Se `x é um número racional`(p) e `y é um inteiro`(q), então `o produto x*y`(r) não `é um número irracional`. 
5. `O assassino fugiu do país`(p) ou `alguém está escondendo ele`(q). 
6. Se `o assassino` não `fugiu do país`(p), `alguém o está escondendo`(q).
7. `A soma de dois números é par`(p) se, e somente se `ambos são pares`(q) ou `ambos são ímpares`(r). 
8. Se `y é um inteiro`(p) então `x*y` não `é irracional`(q), desde que `x é racional`(r).

## Resolução

1. (p ^ q) -> r
2. q -> p
3. (~p -> (r v s)) -> t
4. (p^q) -> ~r
5. p v q
6. ~p -> q
7. p <--> q v r
8. (p -> ~q) -> r
