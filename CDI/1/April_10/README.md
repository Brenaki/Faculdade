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

### Sitetizando:

```
|x-1| = 0.1 => |f(x)-3| = 0.2
|x-1| = 0.01 => |f(x)-3| = 0.02
|x-1| = 0.001 => |f(x)-3| = 0.002
```

> Podemos tornar f(x) tão próximo de 3 quanto desejarmos desde que tomemos x suficientemente próximo de 1.

- **Def.1** Seja f uma função real definida em um intervalo I, e a pertence I, possivelmente f(a) não definida. Diz-se que L é o limite de f(x) se

> `0 < |x-a| < delt` => `|f(x)-L|<E`.

- Denotado por:

```
lim f(x) = L
x->a
```

```
lim f(x) = L <=> (Todo E > 0, Existe um delt > 0 : 0 < |x-a| < delt => |f(x)-1| < E)
x->a
```

## 4. Propriedades de Limites

- **Teorema 1 (Unicidade do Limite)** Se `lim f(x) = L1 \nx->a` e `lim f(x) = L2 \nx->a`, então L1 = L2.

> **Demostração**: hipótese de redução por absurdo:
>> L1 != L2
