# Aula Prática – Programação Orientada a Objetos

## Exercício

- Considere um sistema muito simples de controle bancário. Desenvolva uma classe chamada ContaCorrente, que contenha:

- Atributos privados:

Identificador | Tipo | Descrição
:-- | :-: | --:
nome | String | Nome do cliente
numero | int | Número da conta
agencia | int | Número da agência
saldo | double | Saldo da conta
limite | double | Limite da conta

- A classe deve conter métodos get e set para todos os atributos privados e os seguintes métodos públicos:

> **construtor** nome, numero, agencia, saldo e limite. Inicia os valores de todos os atributos.

> **construtor** nome, numero, agencia e saldo. Inicia os valores de todos os atributos, exceto limite.

> **construtor** nome, numero, agencia. Inicia os valores de todos os atributos, exceto limite e saldo.

> **atualizar** void saldo e limite. Atualiza saldo e limite da conta ao mesmo tempo.

> **atualizar** void nome e numero e agencia. Atualiza nome, numero e agencia da conta ao mesmo tempo.

> **sacar** void valor: valor a ser sacado. Se houver saldo e for um número positivo, saca um valor da conta.

> **depositar** void valor: valor a ser depositado. Se for um número positivo, deposita um valor na conta.

> **imprimir** void. Imprime todas as informações da conta.

- Tanto o construtor como o método atualizar estão sobrecarregados, ou seja, existem várias versões deles com diferenças nos parâmetros. O método atualizar existe para que o usuário possa atualizar mais de um atributo ao mesmo tempo em um método único.
- Desenvolva uma classe Principal, na qual sejam criadas três contas correntes, cada uma com um construtor diferente, faça atualizações, saques e depósitos e imprima informações sobre as três contas.

## Requisitos

### Linux

- Necessário baixar [jdk](https://www.oracle.com/br/java/technologies/downloads/#jdk21-windows)

```bash
# Clonar o Repositório
git clone https://github.com/Brenaki/Faculdade.git

# Navegar pelas pastas
cd Faculdade/POO/Feb_29

# Compilar o arquivo ContaCorrente e Principal
javac ContaCorrente.java
javac Principal.java

# Executar o programa
java Principal
```

### Windows

- Necessário baixar [jdk](https://www.oracle.com/br/java/technologies/downloads/#jdk21-linux)

```powershell
# Clonar o Repositório
git clone https://github.com/Brenaki/Faculdade.git

# Navegar pelas pastas
cd Faculdade/POO/Feb_29

# Compilar o arquivo ContaCorrente e Principal
javac ContaCorrente.java
javac Principal.java

# Executar o programa
java Principal
```
