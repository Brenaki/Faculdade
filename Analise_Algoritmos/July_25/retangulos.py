def ret(vet, k: int) -> int:
    dic, sum, count = {0: 1}, 0, 0

    for num in vet:
        sum += int(num)
        
        if (sum - k) in dic:
            count += dic[sum - k]

        if sum in dic:
            dic[sum] += 1
        else:
            dic[sum] = 1

    return count


n, k = input("N e K: ").split(" ")
vet = input("Vetor: ").split(" ")

print(ret(vet, int(k)))
