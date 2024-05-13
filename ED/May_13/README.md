# Algoritmos de Ordenação

### Introdução

- Ordenar dados é um dos problemas mais fundamentais da estrutura de dados
- Trabalhar com dados é importante para mineração de dados, aprendizado de dados, etc.

### Algoritmo de ordenação por troca

- Um dos algoritmos mais simples de ordenação é conhecido como bubble sort;
- Nesse algoritmo cada elemento (i) de um vetor é comparado com o elemento i+1;
- Quando uma ordenação (crescente ou decrescente) é encontrada é realizada uma troca.

#### Exemplo em Linguagem C

```c
void bubbleSort(int v[])
	for(int i=0;i<5;i++){
		for(int j=0; j<4; j++){
			if(v[j]>v[j+1]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
```

```go
func bubbleSort(v[] int){
	for i:=0;i<5;i++{
		for j:=0;j<4;j++{
			aux := v[j]
			v[j] = v[j+1]
			v[j+1] = aux
		}
	}
}
```

##### Exemplo em C com o bubble sort de trás para frente

```c
void bubbleSort(int v[])
	for(int i=0;i<=5;i++){
		for(int j=4; i>=j; j--){
			if(v[j]<v[j-1]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
```

### Melhorando ainda mais o bubble sort

```c
int n=1, troca = 1;

while(n<=5 && troca=1){
	troca =0;
	for(int i=0; i<3;i++){
		if(v[i]<v[i+1]){
			int aux = v[i];
			v[i] = v[i+1];
			v[i+1] = aux;
		}
	}
	n=n+1
}
```

### Algoritmo de ordenação por inserção

- Diferente do bubble o *inserction sort* escolhe um pivô para comparação;
- O pivô é comparado com todos elementos antes dele e são colocados em ordem;
- Depois, o pivô é trocado.

```
void inserctionSort(int v[]){
	for(int i=1;i<4;i++){
		pivo = v[i];
		j=i-1;
		x=0;
		while(x==0 && j>=0){
			if(v[j] > pivo){
				int aux = v[j]; 
				v[j] = v[j+1];
				v[j+1] = aux;
				j--;
			} else x=1;
		}
	}
}
```
