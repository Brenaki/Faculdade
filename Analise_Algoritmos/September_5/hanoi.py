def hanoi(n, origem, temp, destino):
    if n > 0:
        hanoi(n-1, origem, destino, temp) # RECURSÃO com n-1 discos
        if origem[0]:
            disk = origem[0].pop()
            print("moving " + str(disk) + " from " + origem[1] + " to " + destino[1])
            destino[0].append(disk)
        hanoi(n-1, temp, origem, destino) # RECURSÃO com n-1 discos

origem = ([1,2,3,4], "origem")
destino = ([], "destino")
temp = ([], "temp")
print(origem, temp, destino)
hanoi(len(origem[0]), origem, temp, destino)
print(origem, temp, destino)
