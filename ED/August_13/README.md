# Tabela Hashing - Lista Encadeada

## Relembrando

- Tabela hash é um dicionário para melhorar o armazenamento, busca e atualização de informações

- Definições:
  - Um arranjo `A` de tamanho `n`, no qual cada célula de `A` é considerada como um contêiner para pares chave elemento.
  - Se as chaves forem inteiros bem distribuídas no intervalo `[0,n-1]`, esse arranjo é suficiente.
  - Funções de hash
    - Uma função de hash `h` mapeia cada chave `k` em um inteiro no intervalo `[0,n-1]` -> `A[h(k)]`
  - Códigos hash
    - Resultado de uma função de hash
  - Mapas de compressão
    - É a compressão do código de hash para o intervalo `[0, n-1]`

## Encadeamento separado

- Saindo do endereçamento aberto temos o encadeamento separado
- Este método é recomentado para sistema que são abundantes
- É mais simples e trabalha bem com as colisões

### Funcionamento

- Cada item do arranjo `A[i]` armazena uma referência para uma lista, vetor ou sequência `Si` que armazena todos os elementos que a função de hash mapeou para a posição `A[i]`
- O custo de cada uma das operações fundamentais de dicionários será o custo para inserção, remoção ou busca na sequência `Si` correspondente.

### Pseudocodigo

```pseudo
inserir(chave){
  hash *novo;
  novo = new hash();
  novo->chave = chave;
  novo->prox = tabela[pos];
  tabela[pos] = novo;
}
```

### Etapas para busca

- `h(k)`
- Verifica se existe o elemento
  - Busca sequêncial na lista

