def enumera_rec(permutation, chosen, n):
    if(len(permutation) == n):
        print(permutation)
    else:
        for i in range(1, n+1):
            if chosen[i]:
                continue
            chosen[i] = True
            permutation.append(i)
            enumera_rec(permutation, chosen, n)
            chosen[i] = False
            permutation.pop()

def enumera(n):
    permutation = []
    chosen = [False]*(n+1)
    enumera_rec(permutation, chosen, n)

enumera(3)
