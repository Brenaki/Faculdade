# Exercício 2

- Supondo que você queira utilizar a classe da questão 1 em outra classe que não esteja no mesmo pacote, o que você precisaria fazer? Quais operações com a classe ContaCorrente você conseguiria fazer nessa outra classe?

## Resolução

- Você teria que utilizar o `import`.

```Java
import br.deinfo.uepg;

public class Cliente{
  ...
}
```

- Você conseguiria ler o apenas o nome que é público, utilizando o `getNome()`.

```Java
import br.deinfo.uepg;

public class Cliente{
  public static void main(args String){
    ContaCorrente.getNome();
  }
}
```
