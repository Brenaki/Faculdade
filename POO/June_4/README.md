# Conteúdo para Prova

1. Classes Abstratas *(Teoria e Prática)*
2. Herança *(Teoria e Prática)*
3. Pacotes, Atributos e Métodos protegidos *(Teoria e Prática)* 
4. Interfaces *(Teoria e Prática)*
5. Casting *(Teoria e Prática)*
6. Exceções *(Teoria)*
7. Entrada e Saída (E/S) *(Teoria)*

## Exercícios de revisão

1. Construa uma classe ContaCorrente com dois atributos (nome e número da conta) que esteja incluída em um pacote e com as seguintes restrições:
  - Classe ContaCorrente só pode ser instanciada dentro do pacote
  - Atributo nome pode ser lido por qualquer classe e modificado apenas dentro do pacote
  - Atributo número pode ser lido dentro do pacote e modificado apenas dentro da classe

- [Resolução](./EX1/)

2. Supondo que você queira utilizar a classe da questão 1 em outra classe que não esteja no mesmo pacote, o que você precisaria fazer? Quais operações com a classe Cliente você conseguiria fazer nessa outra classe?

- [Resolução](./EX2/)

3. Crie uma classe abstrata chamada `Veículo`. Essa classe possui um método abstrato chamado imprimirMarca. Crie duas classes chamadas `Carro` e `Motocicleta` que estendem `Veículo`. A classe `Carro` possui como atributos marca e númeroDePortas. Motocicleta possui como atributos apenas marca. As duas classes possuem métodos get/set. Crie um vetor que possa armazenar carros e motocicletas, inclua um carro nesse vetor e execute o método setMarca.

- [Resolução](./EX3/)

4. Como criar uma exceção de tratamento obrigatório em Java? Quais as duas maneiras de manipular uma exceção de tratamento obrigatório em Java?

- [Resolução](./EX4/)

5. Quais os dois tipos de fluxos de E/S em java? Qual a diferença entre eles?

- [Resolução](./EX5/)
