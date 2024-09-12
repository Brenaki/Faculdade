# Solucionando Harzards no pipeline

![Revisão do caminho de dados com pipelining](./OAC0.png)

![Forma mais simples de resolver hazard de dados](./OAC1.png)

![Solução com encaminhamento(forwarding)](./OAC2.png)

## Implementação de encaminhamento

Encaminhamento (forwarding)

- A Implementação do *forwarding* necessita de uma forma de identificar o hazard
- Deve-se coletar o resultado dos registradores de pipeline e realizar o encaminhamento para a ALU que necessita de dados
    - Para a ALU, as entradas vem de quaisquer registradores de pipeline ao invés do registrador ID/EX
    - Multiplexadores são adicionados nas entradas da ALU para selecionados os dados corretos
    - Adiciona-se um controle de hardware apropriado para controlar os novos multiplexadores
    - Outras unidades funcionais, como DM, necessitam de uma lógica similar
- Com *forwarding*, é possível atigir um CPI igual a 1 mesmo quando existirem dependências de dados

![Sinais de controle que trafegam pelo caminho de dados](./OAC3.png)

![Implementação do encaminhamento](./OAC4.png)

## Condições para deteccção de hazard de dados

```vhd
EX/MEM hazard:
if (EX/MEM.RegWrite
and (EX/MEM.RegisterRd !=0)
and (EX/MEM.RegisterRd = ID/EX.RegisterRs))
    ForwardA = 10
if(EX/MEM.RegWrite
and (EX/MEM.RegisterRd !=0)
and (EX/MEM.RegisterRd = ID/EX.RegisterRt))
    ForwardB = 10
MEM/WB hazard:
if (EX/WB.RegWrite
and (EX/WB.RegisterRd !=0)
and (EX/WB.RegisterRd = ID/EX.RegisterRs))
    ForwardA = 01
if(EX/WB.RegWrite
and (EX/WB.RegisterRd !=0)
and (EX/WB.RegisterRd = ID/EX.RegisterRt))
    ForwardB = 01
```

![Encaminhamento em ação](./OAC5.png)

## Outra complicação

Outro potencial *data* hazard pode ocorrer quando existe um conflito entre o resultado do estágio WB e o estágio MEM - qual resultado de ser encaminhado?

![Representação](./OAC6.png)
