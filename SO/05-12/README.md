# Projeto de Cópia de Arquivos - Sistemas Operacionais

Este projeto foi desenvolvido como parte das atividades da disciplina de Sistemas Operacionais, com o objetivo de analisar e otimizar diferentes métodos de cópia de arquivos. O trabalho foi baseado em demandas específicas do professor para explorar e comparar diferentes abordagens de I/O em sistemas operacionais.

## Demandas do Professor

O projeto foi desenvolvido para cumprir as seguintes demandas:

1. **Análise do Código Base**
   - Analisar o código `copiar_arquivo.c` fornecido pelo professor
   - Entender a implementação básica de cópia de arquivos

2. **Pesquisa e Implementação**
   - Pesquisar e implementar métodos para descobrir o tamanho do bloco de alocação de uma unidade de armazenamento
   - Modificar o programa para utilizar diferentes métodos de I/O:
     - Funções de alto nível: `fread()/fwrite()`
     - Funções de baixo nível: `read()/write()`
   - Pesquisar e implementar a alteração do tamanho do buffer interno das funções `fread()/fwrite()`

3. **Avaliação de Desempenho**
   - Realizar testes com arquivos grandes (mínimo 100MB)
   - Comparar diferentes tamanhos de buffer
   - Avaliar a taxa de transferência para cada configuração
   - Medir o tempo gasto em cada método de cópia

4. **Documentação**
   - Elaborar relatório com as informações encontradas
   - Documentar os resultados da avaliação
   - Gerar gráficos comparativos de desempenho

## Descrição do Projeto

Este projeto implementa diferentes métodos de cópia de arquivos com o objetivo de otimizar o processo de transferência de dados, comparando diferentes tamanhos de buffer e métodos de I/O. O programa permite comparar o desempenho entre diferentes abordagens de cópia de arquivos.

## Funcionalidades

- Cópia de arquivos usando diferentes métodos:
  - `fread()/fwrite()` com buffer personalizado
  - `read()/write()` com buffer personalizado
- Testes com diferentes tamanhos de buffer:
  - 512 bytes (0.5 KB)
  - 4096 bytes (4 KB)
  - 8192 bytes (8 KB)
  - 16384 bytes (16 KB)
  - 65536 bytes (64 KB)
  - 131072 bytes (128 KB)
  - 262144 bytes (256 KB)
  - 1048576 bytes (1 MB)
- Barra de progresso em tempo real
- Geração de relatório de desempenho em CSV
- Suporte a arquivos grandes (testado com arquivos de 2GB)

## Como Usar

### Compilação
```bash
gcc -o fcp fcp.c -Wall
```

### Execução
```bash
./fcp <arquivo_origem> <arquivo_destino>
```

### Exemplo
```bash
./fcp mensagem_2GB.bin copia_mensagem.bin
```

## Arquivos do Projeto

### fcp.c
Implementação principal do programa de cópia de arquivos, incluindo:
- Múltiplos métodos de I/O
- Diferentes tamanhos de buffer
- Medição de desempenho
- Barra de progresso
- Geração de relatórios

### gemb.py
Script Python para gerar arquivos de teste grandes:
- Cria um arquivo de 2GB
- Útil para testar o desempenho com arquivos grandes
- Gera um arquivo binário com mensagem repetida

### prof-code.c
Código original do professor, servindo como base para o projeto:
- Implementação básica de cópia byte a byte
- Usa `fgetc()` e `fputc()`
- Entrada via scanf
- Sem uso de buffer

## Evolução do Projeto

1. **Versão Original (prof-code.c)**
   - Cópia byte a byte
   - Entrada via scanf
   - Sem buffer
   - Sem otimizações

2. **Versão Atual (fcp.c)**
   - Argumentos via linha de comando
   - Múltiplos métodos de I/O
   - Buffers otimizados
   - Medição de desempenho
   - Barra de progresso
   - Relatórios em CSV

## Análise de Desempenho

O programa gera um arquivo CSV (`resultados_copia.csv`) contendo:
- Método utilizado
- Tamanho do buffer
- Tempo gasto
- Bytes copiados

Estes dados permitem:
- Comparar diferentes métodos de I/O
- Identificar o tamanho de buffer ideal
- Analisar o desempenho com diferentes tamanhos de arquivo

## Requisitos

- Compilador C (gcc)
- Sistema operacional Unix-like ou Windows
- Python 3.x (para gerar arquivos de teste)

## Notas

- O programa foi testado com arquivos de até 2GB
- A barra de progresso fornece feedback em tempo real
- Os resultados são salvos em formato CSV para análise posterior
- O tamanho do buffer pode ser ajustado conforme necessário 