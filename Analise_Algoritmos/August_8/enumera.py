def enumera_rec(i, sub, N):
    if i == N+1:
        print(sub)
    else:
        sub.append(i)
        enumera_rec(i+1, sub, N)
        sub.pop()
        enumera_rec(i+1, sub, N)

def enumera(n):
    sub = []
    enumera_rec(1, sub, n)

# enumera todos os subconjuntos do conjunto {1, 2, 3}
enumera(3)
