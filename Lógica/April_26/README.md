# Correções de Exercícios | Revisão para Prova

##### Equivalências lógicas e simplificação de fórmulas

- 5) Transforme as sentenças abaixo em FND e FNC.
	- (C) (P ^ Q) v (~Q <-> R)

```
P	Q	R	(A)P^Q	 (B)~Q <-> R	AvB

V	V	V	V	     F		V	FND
V	V	F	V	     V		V	FND
V	F	V	F	     V		V	FND
V	F	F	F	     F		F	FNC
F	V	V	F	     F		F	FNC
F	V	F	F	     V		V	FND
F	F	V	F	     V		V	FND
F	F	F	F	     F		F	FNC
```

	- (D) ~((P -> ~Q) -> R)

```
~((P -> ~Q) -> R)
~(~(P -> ~Q) v R)
~(~(~P v ~Q) v R)
~((P ^ Q) v R)
(~P v ~Q) ^ ~R	FNC
```

- 8) Use as equivalências lógicas para mostrar que:

	- (B) (p ∨ q) ∧ (r ∨ p) ∧ (¬q ∨ ¬r ∨ p) ≡ p
```
B = (p v q)
C = (r v p)
A = (~q v ~r v p)

A ^ B ^ C	P	P == (A^B^C)
    
    V		V	    V
    V		V	    V
    V		V	    V
    V		V	    V
    F		F	    V
    F		F	    V
    F		F	    V
    F		F	    V
```

##### Exercícios sobre prova direta em lógica proposicional - Parte 1

- 1) Prove as seguintes equivalências lógicas:
	- a) p⊻ q ≡ (p∧~q)∨(p∧q)
```
p⊻ q ≡ (p ∧ ~q)∨(p ∧ q)
(~p v q) ^ (p v ~q) ≡ p ^ (~q v q)
(~p v q) ^ (p v ~q) ≡ p
```
	- b) (p ⇒ ~q)∧(p ⇒ ~r) ≡ ~(p∧(q∨r))

```
(~p v ~q) ∧ (~p v ~r) ≡ (~p v ~(q ∨ r))
~p v (~q ^ ~r) ≡ (~p v (~q ^ ~r))
~p v ~(q v r) ≡ (~p v ~q) ^ (~p v ~r)
~(p ^ (q v r)) ≡ (p -> ~q) ^ (p -> ~r)                         
```
