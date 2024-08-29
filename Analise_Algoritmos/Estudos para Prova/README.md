# Big O Notation

Big O Notation é um metodo matemático de você poder medir a complexidade de tempo e espaço de um algoritmo.

#### Exemplo

```c
#include <stdio.h>

void printFirst(int *vet){
	printf("%d", vet[0]);
}

int main(){
	vet[10] = {1,2,3,4,5,6,7,8,9,10}
	printFirst(vet);
	
	return 0;
}
```

Como visto acima esse algoritmo tempo um complexidade de tempo de `O(1)`, sendo assim, não importa o tamanho do vetor, sempre vai ser imprimido o primeiro elemento dele.

Outro exemplo de complexidade de tempo que podemos dar é para uma busca em matrix, que tem a complexidade de tempo de `O(n²)`

#### Exemplo

```python
def searchInVetor(vet, target){
	for row in vet:
		for item in row:
			if(item == target):
				print("Item encontrado!")
				return
	print("Item não encontrado!")
}


vet = [[1,2,3],[4,5,6],[7,8,9]]
searchInVetor(vet, 7)
```

Como dito anteriormente o código acima tem a complexidade de tempo de `O(n²)`, porém a complexidade de espaço é de `O(n)`.

## Complexidade de tempo e espaço

A complexidade de tempo como ja visto acima é o melhor, médio e pior tempo que um algoritmo demoraria para ser executado. Normalmente nós analisamos o melhor e o pior caso, devido a serem mais simples de ser encontrados, mas também é possivel encontrar o caso médio através desse [calculo](https://github.com/Brenaki/Faculdade/tree/master/Analise_Algoritmos/August_15).

Agora a complexidade de espaço é determinada pela a utilização de espaço em mémoria para um algoritmo ocupa.

#### Exemplo

```javascript
function fibonacci(num: number):number {
	if(num === 0 || num === 1) return 1;
	return fibonacci(num-1) + fibonacci(num-2)
}

console.log(fibonacci(6))
```

Com esse exemplo vemos que a complexidade de tempo é `O(2^n)` e a complexidade de espaço também é de `O(n²)`, para ser mais simples de explicar podemos pegar uma função simples de soma recursiva

```javascript
function soma_recursiva(num: number):number {
	if(num <= 0){
		return num
	}
	return num + soma(num-1)
}

function soma_iterativa(num: number):number {
	let total = 0
	
	for(const i = 0; i<num+1; i++){
		total += num
	}
	
	return total
}

console.log(soma_recusiva(13))
console.log(soma_iterativa(13))
```

Na recursiva nos tempo um complexidade de tempo de `O(n)` e de espaço de `O(n)´, e na iterativa a complexidade de tempo é `O(n)`, porém a complexidade de espaço é de `O(1)`. Porque?

Tempos que pensar que dentro da mémoria cada vez que uma função é chamada ela começa a ocupar um espaço a mais na mémoria, sendo assim, na iterativa como a função é chamada uma vez o espaço dela é irelevante, ao contrário da recursão que a cada vez que a soma acontece ela é chamada, sendo assim, dependendo do tamanho do número que for para soma é o espaço que ela vai ocupar em mémoria.



# Referencias 

[Big O Notation: O Pesadelo do Programador Iniciante](https://www.youtube.com/watch?v=GLKDo13920k)
[Big O Notation | Explicações para iniciantes](https://www.youtube.com/watch?v=3mwnw3XsEH4&t=1s)
[Big O Notation (Descubra Agora se Seus Algoritmos São Eficientes) // Dicionário do Programador](https://www.youtube.com/watch?v=RGD3iwqDdAE&t=2s)
[Complexidade de algoritmo - Entenda O(log(n)) finalmente](https://www.youtube.com/watch?v=qxnOI5qh7EE)
[Comparação assintótica de funções](https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/Oh.html)
