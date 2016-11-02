def binomialCoeff(n,k):
    table = [0 for i in range(k+1)]
    table[0] = 1;

    for i in range(1,n+1):
        j = min(k,i)
        while j>0:
            table[j] = table[j] + table[j-1]
            j-=1

    return table[k]

n = 5
k = 2
print ("Value of C(%d,%d) is %d" %(n,k,binomialCoeff(n,k)))