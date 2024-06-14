# Raciocínio para trás

- Objetivo da lógica é *provar os argumentos*.

```
P2, P1, ..., Pn :. Q
sempre que       .V.
V
```

- Regras de inferência: deduzir
  - Exemplo 
```
Homem(Miguel)  Vx Homem(x) -> Humano(x)
Homem(Artur)   Vx Humno(x) -> Mortal(x)
Mulher(Ana)
```

- Dedução de Mortal(Miguel) 
  - R2) Mortal(Miguel)
  - x/Miguel
    - Humano(Miguel)
    - x/Miguel
      - Homem(Miguel)

## Definições

- Literal
  - Um literal é uma formula atomica.

## Cláusula de Horn

- É uma cláusula que contém no máximo um literal.

```
{~humano(x), mortal(x)} = ~humano(x) v mortal(x)   Vx
                          humano(x) -> mortal(x)

{H(Pedro)} - fato
{~R(x), ~Q(x)} clásula negativa

{~r(x), p(x), t(x)} - não é Horn, porque possui duas verdades

```

## Clásula definida

- É uma regra de Horn ou um fato

```
{~h(x), m(x)}
{~r(x), ~g(x), p(x)}   Datalog
{H(Pedro)}

{~H(x), H(mãe(x))} - não é datalog
```

## DataLog

- Um datalog é um conjunto de clásulas definidas sem funções. Um datalog faz duas suposições:
  - A suposição do nome único que diz que constantes diferentes se referem a objetos diferentes.
  - A suposição do mundo fechado, em um datalog fatos não afirmados são assumidos como falsos.

### Exemplo:
- Todo barco a vapor é mais rápido que qualquer veleiro. Todo veleiro é mais rápido que qualquer barco a remo. Para todo X Y e Z, se X é mais rápido do que Y e Y é mais rápido que Z, então X é mais rápido que Z. Sabemos que Olimpico é um barco a vapor, Mistral é um veleiro, e Laguna é um barco a remo.

> Pergunta: Olimpico é mais rápido que Laguna?

```
VxVy(BarV(x) ^ Vel(y) -> Mr(x,y))

VxVy(Vel(x)^BarR(y) -> Mr(x,y))

VxVyVz(Mr(x,y) ^ Mr(y, z) -> Mr(x,z))

BarV(Olimpico)
BarR(Laguna)
Vel(Mistral)
```

# Forma normal prenex conjutiva
- (Notação cláusal)

- Nem todas as sentenças em LPO são datalogs, logo não é possível usar o raciocínio para trás para provar toda forma de argumento.
- A uma regra de inferência bem mais poderosa, ela se chama resolução. Contudo, para utiliza-lá precisamos transformar as sentenças em uma notação, que se chama Notação Cláusal.
- A Notação Cláusal é um conjunto de clásulas e simboliza a conjução dessas cláusulas.

```
{Pai(João, Antonio)}, {(Pai(Antonio, Marcos))}

{~Pai(x,y), ~Pai(y,z), ~Avô(x,z)}
```

- Contudo, nem sempre as formulas estão escritas em notação cláusal para chegar nesse objetivo precisamos aplicar uma serie de transformações. A primeira é converter a sentença na sua forma normal prenex.

## Forma Normal Prenex (FNP)

- Uma sentença S está na FNP se estiver na forma Q1X1, Q2X2, ..., QnXn(alpha), onde Qi é um quantificador e alpha é FBF sem quantificadores.

```
Vx]y(p(x,y))

VxVy(p(x,y) ^ q(y)) FNP

Vx(p(x,z)^]y(q(y))) ~FNP
```

- Qualquer sentença pode ser escrita como uma FNP. Se a sentença S é verdadeira, então sua FNP também o é. Idem para o caso em que S é falso.

### Conversão de Sentenças em FNP

> Ex: ~(]xP(x,y) v VzQ(z) ^ ]wQ(w))

- Reconhecer o escopo dos quantificadores;
- Padronize o nome das variáveis, se necessário;
- Elimine as condicionais e bicondicionais;
- Mova as negações para o inteiror dos parênteses usando as leis de Morgan e as equivalências entre os quantificadores;
- Mova os quantificadores gradualmente para fora dos parênteses até obter a forma normal prenex, mantenha a ordem dos mesmos.

#### Exercício 

- Converta em FNP

1.  Vx[C(x) ^ ]yT(y) ^ L(x,y)] -> ]z[D(z) ^ B(z)]
