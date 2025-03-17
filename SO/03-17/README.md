# Explicando o trabalho

O `calcula_média é parecido do `exit_wait.c`. 

Exite um problema de granularidade de quantos processos eu posso criar. Então a ideia é fazer os processos filhos não retornar não só 1 valor, mas sim, um conjunto de dados processados. Ler o `fork_1.c`

Região crítica é o dado que pode ser acessado por mais de um processo, e não a controle que vai fazer a alterção. Só a como controlar utilizando semáforo.

Professor deseja que escrevemos 3 relatórios, um sobre `calcula_média.c` básico, o outro é fazer um programa similar ao primeiro, porém não utilizando as funções do `calcula_média.c`, e o último relatório é sobre utilizar uma memoria compartilhada, aonde o programa deve verificar quantas nos serão calculadas e dividir de forma eficiente em processos dependendo da quantidade de linhas.
