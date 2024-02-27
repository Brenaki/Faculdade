# Atributos Privados

Os atributos privados diferente dos publicos, não podem ser acessados pelos objetos, então como adicionar valores nos atributos? Simples é só dar um `this.[nome do atributo]`.

- Exemplo:

```java
  public class Exemplo1 {
    private String nome;

    // Insere o valor no atributo quando é chamado
    public void setNome(String nome) {
      this.nome = nome;
    }
    // Retorna o valor do atributo quando é chamado
    public String getNome(){
      return this.nome;
    }
  }
```

# Método construtor

Em java para que os atributos que você criou não fiquem ocupando espaço em memoria e não fiquem vazios. Você força o usuário quando cria um objeto ele inserir os dados nos atributos.

- Exemplo:

```java
  public class Exemplo2 {
    private String nome;
    private int idade;

    public Exemplo2(String nome, int idade) {
      this.nome = nome;
      this.idade = idade;
    }
  }
```

# Sobrecarga de métodos

Em java você pode criar métodos com o mesmo nome. O que diferencias eles são os paremetros que você coloca nele. A Sobrecarga de métodos é chamada de overload.

- Exemplo:

```java
   public void metodo()
   public void metodo(int a)
   public void metodo(float a)
   public void metodo(int a, float)
```
