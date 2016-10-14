def lis(arr):
    n = len(arr)
    lisCount = [1]*n

    for i in range(0,n-1):
        for j in range(i,n-1):
            if(arr[j]>arr[i] and lisCount[j]<lisCount[i]+1):
                lisCount[j] = lisCount[i]+1

    maxLen = 0;
    for i in range (0,n-1):
        if(lisCount[i]>maxLen):
            maxLen = lisCount[i]

    return maxLen

arr = [10, 22, 9, 33, 21, 50, 41, 60]
print (lis(arr))