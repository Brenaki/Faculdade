# VHDL

```vhdl
library ieee;
use ieee.std_logic_1164.ALL;

entity teste is
  port(AE, EB: in std_logic;
        SA: out std_logic_vector(downto 0);
end;
```

#### Ex1

- EA <= '1'; X
- SA <= "0001"; V
- SA <= '0001'; X

- Utilizando `--` em vhdl você pode fazer comentários no seu código, exemplo, "-- SA: out std_logic_vector(3 downto 0);"

```vhdl
SA <= x"1"; -- SA_32 <= x"00000000";

-- SB: out std_logic;

SA <= '1'; X
SA <= '0'; X

process V
  begin
    SA <= '1';
    SA <= '0';
end;
```

## Gerador de paridade

- Palavra de 3 bits

- (A) -----/(3)-----(B)
- 0 0 1 1 --> 0 0 1 1 | 0 V
- 0 1 1 0 --> 0 0 1 0 | 1 X
- 1 1 1 1 --> 1 1 1 1 | 0 V
- A (+) B

A | B | A (+) B
:-- | :-: | --:
0 | 0 | 0
0 | 1 | 1
1 | 0 | 1
1 | 1 | 0

```vhdl
entity paridade is
  port(E: in std_logic_vector(2 downto 0);
        par, impar: out std_logic);
end;

architecture arch of paridade is
begin
  PAR <= E(0) xor E(1) xor E(2);
  IMPAR <= not PAR;
end;

-- begin
--  PAR <= xor E;
--  IMPAR <= not (xor E);
-- end;
```

## Registrador

```vhdl
entity registrador is 
  port(W: in std_logic;
        E: in std_logic_vector(31 downto 0);
        S: out std_logic_vector(31 downto 0));
end entity;

architecture arch of registrador is
  signal palavra: std_logic_vector(31 downto 0);
  begin 
    P1: process(w) 
          begin
            if w = '1' then palavra <= E;
          end process;
    S <= palavra;
  end;
```


## Máquina de café (vending machine) 

Dinheiro | Binário
:-- | --:
0.00 | 00
0.25 | 01
0.50 | 10
1.00 | 11

Café | Troco
:-- | --:
0 | 00
1 | 00
1 | 01
1 | 10
1 | 11

```vhdl
library ieee;
use ieee.std_logic_1164.ALL;

entity vm is
  port(   clk: in std_logic;
          saidas: out std_logic_vector(2 downto 0);
          moeda: in std_logic_vector(1 downto 0)
      );
end vm;

architecture Bahavioral of vm is
  type estado is (a,b,c,d);
  signal proximoEstado : estado;
  signal temp: std_logic_vector(2 downto 0):= "000";
  begin
    process(Clk)
      begin
        if(rising_edge(Clk)) then
          temp <= "000";
          case proximoEstado is
            when a =>
              if(moeda = "00") then
                proximoEstado <= a;
              elsif(moeda = "01") then
                proximoEstado <= b;
              elsif(moeda = "10") then
                proximoEstado <= c;
              elsif(moeda = "11") then
                temp <= "100";
                proximoEstado <= a;
              end if;
          when b =>
                  if(moeda = "00") then
                    proximoEstado <= b;
                  elsif(moeda = "01") then
                    proximoEstado <= c;
                  elsif(moeda = "10") then
                    proximoEstado <= d;
`````
