# Aula 07 - Introdução ao Limite

## 1. Para quê limite?

- R: Para definirmos os principais operações do CDI: `derivação` e `integração`.

## 2. Noção numérica de Limite

- Considere uma função racional:

```
	
f(x) = ((2x+1)(x-1))/(x-1)

```

> D(f) = {xER : x != 1}

> Cd(f) = R

```

j(x) = 2x+1;

```

- A função j não está definida em x = 1.
- Estudo da vizinhaça em torno de x = 1.

x | 0 | 0.5 | 0.9 | 0.99
:-- | :-: | :-: | :-: | --:
f(x) | 1 | 2 | 2.8 | 2.98

x | 2 | 1.5 | 1.1 | 1.01
:-- | :-: | :-: | :-: | --:
f(x) | 5 | 4 | 3.2 | 3.02

## 3. Construindo o critério de aproximação de Limite:

> x = 0.9 => f(x) = 2.8, isto é: x-1 = -0.1 => f(x)-3 = -0.2

> x = 0.99 => f(x) = 2.98, isto é: x-1 = -0.01 => f(x)-3 = -0.02

> x = 0.999 => f(x) = 2.998, isto é: x-1 = -0.001 => f(x)-3 = -0.002

---

> x = 1.1 => f(x) = 3.2, isto é: x-1 = 0.1 => f(x)-3 = 0.2

> x = 1.01 => f(x) = 3.02, isto é: x-1 = 0.01 => f(x)-3 = 0.02

> x = 1.001 => f(x) = 3.002, isto é: x-1 = 0.001 => f(x)-3 = 0.002
