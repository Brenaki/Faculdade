#include <stdio.h>
#include <stdlib.h>

int V[500000];

int main()
{
    int N, K;
    long long  saida = 0LL;
    long soma;

    scanf("%d %d ", &N, &K);
    for (int i = 0 ; i < N ; i++)
        scanf("%d ", &V[i]);
    
    for (int i = 0 ; i < N ; i++){
        soma = 0L;
        for (int j = i ; j < N ; j++){
            soma += V[j];
            if (soma == K)
                saida++;
        }
    }
    printf("%lld\n", saida);
    return 0;
}
