# Exercício Sintaxe e Semântica I

## 1
- B) (a -> b) ^ c = fbf
- C) B ^ (C v D)) = ~fbf

## 2
- G) (P v Q) v (S -> (P -> R))

## 4
- B) Se x<4 e x>2, então x=3. | (P ^ Q) -> R

# Exercício sobre argumento

## 1
- A) Se eu for na festa eu estarei cansado amanhã. Se eu for na festa, eu verei meus amigos. Logo, se eu não ver meus amigos, eu não estarei cansado amanhã.
	- ((p -> q)^(p -> r)) -> ~r -> ~q
- C) Ou voltamos para o clube, ou retornamos para casa. Decidimos não retornar para casa. Logo, voltamos ao clube.
	- ((p v q)^ ~(p^q)) ^ ~q -> p
## 3

- T = 2¹⁰⁰⁰/10⁹

## 5
- B) (AvC)^(B -> C) ^ (C -> A) é equivalente a (A v C) ^ (A -> C)
	- Não é equivalente

# Tautologia

- Se A pe uma tautologia, então a formula gerada com a substituição das variáveis de A, P1, ..., Pn, com as sentenças A1, ..., An é uma tautologia.

## Exemplo

- (P ^ ~R) ^ ((P ^ ~R) -> (~P -> ~Q)) -> (~P ^ ~Q)

# FNCs e FNDs

## Observações sobre FNCs e FNDs: 

- Qualquer sentença proposicional é equivalente a alguma FND ou alguma FNC. 

- Uma FND pode ser obtida a partir da tabela verdade tomando algumas disjunções de todas as linhas. 

- Cada uma é representada pela conjunção das variáveis, segundo os valores instanciados. 

- Uma FNC pode ser obtida por meio de uma tabela verdade tomando as conjunções das negações das linhas que falseiam a expressão.

# Inferência, Consequência Lógica e Provas

- Um dos objetivos principais da lógica é verificar a validade de argumentos. Isto é, verficar se sempre que as premissas de um argumento P1, P2, ..., Pn ... C são verdadeiras a conclusão também é. 

- Para fazermos isso recorremos a ideia da consequencia lógica. Uma sentença S1 |= S se, e somente se S é verdadeira em todos os mundos possiveis em que S1 é verdadeira.

- A ideia básica que um argumento é valido se, e somente se sua conclusão é consequência lógica de suas premissas. Argumento válido P1 ^ P2 ^ ... ^ Pn |= C.

- O teorema da dedução provê de um mecanismo lógico para testar consequência lógica. Segundo esse teorema S1 |= S se, e somente se: 
	- S1 -> S é válido
	- S1 ^ ~S é contradição

- O teorema da dedução permite testar a validade de um argumento. A sua correção(Veracidade no mundo real) não é tratada pelo teorema da dedução.

## BC simples

- Descrição da BC inicial
	- R1: ~P11
	- R2: B11 |= (P11 v P21)
	- R3: B21 |= (P11 v P22 v P31)
- Fatos novos - sensores
	- R4: ~B11
	- R5: B21
![Tabela de BC simples](.LC0.png)

