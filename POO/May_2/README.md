# Exercícios de Programação Orientada a Objetos

1. Usando a classe JOptionPane para E/S
- Desenvolva uma classe Principal que faça as seguintes operações:
- Pergunte “Você quer calcular o dobro de um número?”
	- Use JOptionPane.showConfirmDialog(null,mensagem);
	- Se o usuário não clicar em <Yes>, termine a execução
- Imprima a mensagem “Digite o número” e leia o valor digitado;
	- Use o método JOptionPane.showInputDialog(null,mensagem);
	- Se o usuário clicar em <Cancel>, termine a execução
- Transforme o número lido em inteiro (o método showInputDialog lê apenas strings)
	- int num = Integer.parseInt(valor);
- Imprima a mensagem “O dobro do valor lido é X”, onde X é o dobro do valor lido
	- Use o método JOptionPane.showMessageDialog(null, mensagem)

> Em todos os métodos, mensagem é uma string. Lembre-se que uma string pode ser
formada pela concatenação de várias strings.

[Code](./Ex1/Principal.java)

2. Crie um pacote com o nome br.uepg.deinfo.primeiro, e inclua dentro dele 2 classes.
	1. Uma classe chamada Pessoa, que contenha três atributos: código, nome e salário.
		- O atributo salário pode ser acessado livremente dentro do pacote.
		- Os atributos código e nome podem ser lidos dentro do pacote, mas devem ter seus valores modificados apenas pelo construtor.

- A classe Pessoa deve ter um construtor que inicie apenas código e nome da pessoa, um método toString(), e deve ter apenas os métodos get ou set que sejam obrigatórios, de acordo com as restrições de acesso aos atributos. Além disso, a classe Pessoa pode apenas ser instanciada dentro do pacote.

	2. Uma classe chamada Vetor, que defina um vetor no qual sejam armazenados objetos da classe Pessoa. Inclua métodos para incluir uma pessoa (as informações da pessoa devem ser digitadas no próprio método de inclusão, o qual não tem parâmetros) e para imprimir todas as pessoas incluídas no vetor. O vetor deve ter um comportamento igual de uma lista linear, ou seja, os elementos devem ser inseridos em posições consecutivas iniciando pela posição 0.

> Crie um pacote chamado br.uepg.deinfo.segundo, e inclua nele uma classe Principal, na qual
seja instanciada a classe Vetor e sejam executados os métodos de inclusão e impressão.

[Code](./Ex2)
