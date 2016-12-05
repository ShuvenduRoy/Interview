def solution():
    number = input()
    seq = input()

    n = int(number.split()[0])
    k = int(number.split()[1])

    i = seq.find('T')
    j = seq.find('G')

    i, j = min(i, j), max(i, j)

    while i + k <= j:
        i += k
        if seq[i] == '#':
            return False
        if seq[i] =='T' or seq[i] == 'G':
            return True
    return False


if(solution()==True):
    print("YES")
else:
    print("NO")


