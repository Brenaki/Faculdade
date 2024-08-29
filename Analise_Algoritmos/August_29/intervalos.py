#!/usr/bin/env python
# -*- coding: latin-1 -*-

import functools

# Função usada para ordenar os intervalos:
#    1. em ordem crescente do ponto esquerdo e, em caso de igualdade,
#    2. em ordem decrescente pelo ponto direito
def compare(i1, i2):
    if i1[0] == i2[0]:
        return i2[1]-i1[1]
    else:
        return i1[0] - i2[0]

def Intervalos(I):
    """ devolve uma lista com todos os intervalos contidos em outros intervalos """

    Resposta = []
    I = sorted(I, key=functools.cmp_to_key(compare))
    MaxR = I[0][1]  # ponto direito do primeiro intervalo
    # do segundo ao ultimo intervalo faça
    for j in range(1,len(I)):
        if I[j][1] > MaxR:
            MaxR = I[j][1]
        else:
            Resposta.append(I[j])
    return Resposta

# exemplo
I = [(0,5),(1,7),(6,10),(5,9),(0,2),(6,7),(2,4), (0,1),(0,3),(5,10),(5,1),(5,20),(15,21)]
print("Entrada: ", I)
print("Ordenado: ", sorted(I, key=functools.cmp_to_key(compare)))
print("Marcados: ",Intervalos(I))
