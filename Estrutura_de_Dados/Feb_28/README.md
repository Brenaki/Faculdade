# Revisão C - Vetores

2 tipos de variaveis

- Simples
Ex:
```c
float c;
int a = 8;
char b;
```

- Composta
	- Heterogênea(Registro/Struct)
	- Homogêna(Vetor e Matriz)
### Variável - homogênea -> coleção de dados de mesmo tipo

0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
:-- | :-: | :-: | :-: | :-: | :-: | --:
0 | 1 | 2 | 3 | 3 | 4 | 5 | 6

Declaração:
```c
int m[8];
```
o número dentro [] deve ser um inteiro.
```c
m[4] = 3; // adiciona o numero 3 no indice 4 do vetor. 
```  

```c
int m[8] = {0,1,2,3};
// ou de ser adicionado valores em estruturas de repetição

for(int i=0; i<8; i++){
	m[i] = i+1;
}
```

### Matiz 2D
```c
int mm[2][3] = {{0,1,2}, {0,1,2}};
```

#### mm:
| 0 | 1 | 2
:-- | :-: | --:
0 | 1 | 2

```c
for(int x=0; x<2;x++){
	for(int y=0; y<3; y++){
		mm[x][y] = y+1;
	}
}
```
