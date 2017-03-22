def lis(arr):
    n = len(arr)
    lisCount = [1]*n
    print(lisCount)

    for i in range(0,n):
        for j in range(i,n):
            if( (arr[j]>arr[i]) and (lisCount[j]<lisCount[i]+1) ):
                lisCount[j] = lisCount[i]+1

    print(lisCount)
    maxLen = 0;
    for i in range (0,n):
        if(lisCount[i]>maxLen):
            maxLen = lisCount[i]

    return maxLen

arr = [10, 22, 9, 33, 21, 50, 41, 60]
print (lis(arr))