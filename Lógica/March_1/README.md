# Lógica

## Objetivos da lógica

Fornecer uma linguagem formal para expressar e racionar(processar) argumentos.

- Argumento: uma sequencia de afirmações chamadas premissas, cuja veracidade leva a uma afirmação chamada conclusão.

- Argumento válido: se sempre que as premissas são verdadeiras, a conclusão também é.

## Linguagem formal

- **Expressões**: programas, aritimética.
- **Sintaxe**: um conjunto de regras para construir expressões em uma linguagem.
- **Semântica**: Diz respeito ao significado das expressões que compoem um determinado discurso. Relaciona cada termo da expressão aos objetos do domínio de discussão.

## Tipo de lógica

- **Lógica proposicional**;
- **Lógica de primeira ordem**;
- Lógica propabilistica;
- Lógica fuzzy.

> A Lógica proposicional e Lógica de primeira ordem --> automação do raciocínio.

# Lógica Proposicional

## Conhecimento Declarativo X Procedimental

- **Conhecimento procedimental**: É uma descrição de como executar uma tarefa proposta. Para tanto faz uso de linguagens imperativas. Por exemplo, resolver uma equação de segundo grau.
> x = -b+-sqrt(delt)/2.a, antes delt = (b²)-4.a.c, se delt >= 0.

- **Conhecimento declarativo**: É composto por um conjunto, de informações (declarações, preposições) que informa fatos e relações sobre objetos de um domínio.

> Ex: As raizes x1 e x2 da equação x²+bx+c = 0, são valores que quando substituidos em x, atendem a igualdade.

> Ex: Todos os humanos são mortais. Socratés é mortal.

## Sentenças declarativas e a lógica proposicional

- A lógica proposicional objetiva representar sentenças declarativas sobre os objetos de universo de discurso. Uma sentença declarativa ou proposição é uma afirmação que pode ser verdadeira ou falsa.
- Assim, as sentenças exclamativas e imperativas estão fora do escopo da lógica proposicional. 

> Ex: Totó é um cão;

> Os suiços fazem os melhores relógio;

> Gatos gostam de leite.

- Afim de formalizar a representação de um discurso declarativo, a lógica proposicional associa cada sentença há um simbolo de variável proposicional. Estes símbolos em geral são denotados por letras minúsculas com ou sem índices.

## Principios da lógica proposicional

1. **Identidade**: Toda proposição é idêntica si mesmo;
2. **Não contradição**: Uma proposição não pode simultaneamente ser verdadeira ou falsa;
3. **Terceiro excluido**: Toda proposição é verdadeira ou falsa, não há outro valor;

## Sintaxe e gramáticas

- Regras para gerar sentenças em um linguagem

### Exemplos de gramátoca formal

> Ex1: S -> asb; s -> c;

> Ex2: S -> 1; S -> SS; S -> (S)

> S -> SS -> (S)S -> (SS)S -> ((S)S)S -> ((S)(S))S -> ((1)(1))1

## Preposições

- A lógica proposicional também trata da representação de preposições compostas de preposições menores. No entanto, ela específica que tipo de estrutura conceitual pode ser representada.
- Na lógica fazemos o uso de 5 estruturas para conectar as preposições. Estas 5 cincos estruturas são chamadas de conectivos lógcos ou operadores lógicos, e são:

#### Conectivos lógicos:

1. **Negação**: (~)
2. **Conjução**: (^, e)
3. **Desjunção**: (v, ou)
4. **Condicional ou implicação**: (->, se, então)
5. **Bicondicional ou equivalencia**: (<-->, sss)

- Durante a modelagem de um discurso precisamos identificar as sentenças e representá-las usando os conectivos.

### Exemplos:

> `João é humano` e `Torce para o Inter`. p ^ q

> `O livro é detalhado` ou `é barato`. p v q

> Eu não `comprei o carro`. ~p

> `O triângulo é retângula` se `tiver um angulo reto`. q -> p

> `ABC é um triângulo equilátero` se, e somente se `AB é equiângulo`. p <--> q
