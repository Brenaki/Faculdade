# Aula Prática – Programação Orientada a Objetos

## Exercício

- Considere um sistema muito simples de controle de estoque. Desenvolva uma classe chamada Produto, que contenha:

- Atributos privados:

Identificador | Tipo | Descrição
:-- | :-: | --:
nome | String | Nome do produto
preco | double | Preço de venda do produto
qtd | int | Quantidade do produto disponível em estoque


- A classe deve conter métodos get e set para todos os atributos privados e os seguintes métodos públicos:

> **Produto (construtor)** nome, qtd, preco. Inicia os valores de todos os atributos.

> **Produto (construtor)** nome, preco. Inicia os valores de todos os atributos nome e preco.

> **vender** void. qtd: quantidade de produtos vendidos. Se houver itens sufucientes no estoque, faz a venda e diminui a quantidade de produtos em estoque.

> **comprar** void. qtd: quantidade de produtos comprados. Compra uma determinada quantidade de produtos do fornecedor.

> **imprimir** void. Imprime todas as informações do produto.

- Desenvolva uma classe *Principal* na qual seja definido um vetor de produtos, alguns objetos sejam inseridos no vetor e os métodos sejam testados.

## Requisitos

### Linux

- Necessário baixar [jdk](https://www.oracle.com/br/java/technologies/downloads/#jdk21-windows)

```bash
# Clonar o Repositório
git clone https://github.com/Brenaki/Faculdade.git

# Navegar pelas pastas
cd Faculdade/POO/March_8

# Compilar o arquivo ContaCorrente e Principal
javac Produto.java Principal.java

# Executar o programa
java Principal
```

### Windows

- Necessário baixar [jdk](https://www.oracle.com/br/java/technologies/downloads/#jdk21-linux)

```powershell
# Clonar o Repositório
git clone https://github.com/Brenaki/Faculdade.git

# Navegar pelas pastas
cd Faculdade/POO/March_8

# Compilar o arquivo ContaCorrente e Principal
javac Produto.java Principal.java

# Executar o programa
java Principal
```
