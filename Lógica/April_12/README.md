# Inferência por prova direta

## Teorema da dedução

- S1, S2, ..., Sn .: S

- (S1^S2^...^Sn) -> S é uma tautologia

- (S1^S2^...^Sn) |= S consequência lógica

- Inferência
	- Dedução
	- Raciocínio lógico

- Formas de inferência
	- Tabela verdade
	- Direta
	- Indireta (Refutação, Redução ao absurdo)

- Para quê fazer inferências:

1. Provar um argumento
	* S1, S2, ..., Sn .: S
2. Devivar inclusões
	* S1, S2, S3, ..., Sn .: ?(S)

## Argumentos, Consequência Lógica e Prova

- `Um argumento`: S1, S2, ..., Sn .: S

- `Consequência Lógica`: S1, S2, ..., Sn |= S (sentenças lógicas)

> argumento é válido se é demonstrável por uma consequência lógica

- `Prova`: É o processo de demonstrar a válidade de uma consequência lógica por meio da aplicação de um conjunto de regras sintáticas chamadas regras de inferência. As regras de inferência representam padrões lógicos de dedução e são sentenças válidas do ponto de vista do teorema da dedução. Cada passo em uma prova aplica uma regra de inferência sobre sentenças já conhecidas. Cada passo de inferência é denominado derivação.
	- S1, S2, ..., Sn |- S

## Regras de inferência

- Correção
	- Se A |- B então A |= B

- Completude
	- Se A |= B então A |- B

# A regra da resolução e a prova indireta de argumentos

- Teorema da dedução
	- S1, S2, ..., Sn .: sss
	- S1 ^ S2 ^ ... ^ Sn ^ ~S é uma contradição

## Dem.

- TD A.: B sss A -> B == .V.
	- ~AvB == .V.
	- aplicando a negação
	- ~(~AvB) == .V.
	- A^~B == .F.

- O método da resolução explora a possibilidade de usar o enunciado anterior do teorema da dedução para demonstrar se a conjunção das premissas com a refutação da conclusão levam a uma contradição. Esse método assumi que a expressão S1 ^ S2 ^ ... ^ Sn ^ ~S está ta forma normal conjutiva, por tanto pode ser aplicada a qualquer argumento.

- As disjunções da FNC tratadas pela regra da resolução são chamadas cláusulas. Uma cláusula é uma disjunção de literais. Um literal é uma variável proposicional ou sua negação. No primeiro caso temos um literal positivo, no segundo temos um literal negativo. A aplicação da regra da resolução produz uma cláusula chamada de resolvente.

## Resolução completa

- (A v B) ^ (~A v C) == .V.
	- B v C

- (AvBvC) ^ (Av~Bv~C)
	- (B v (AvC)) ^ (~B v (Av~C))
	- (AvC) v (Av~C)
	- A v C v ~C
	- A v .V.
	- V
