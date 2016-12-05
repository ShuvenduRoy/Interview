num = input().split()
n = int(num[0])
n1 = int(num[1])
n2 = int(num[2])

num = input().split()
arr = []
for i in range(n):
    arr.append(int(num[i]))

n1,n2 = min(n1,n2), max(n1,n2)
arr.sort(reverse=True)

ans = sum(arr[:n1])/n1 + sum(arr[n1:n1+n2])/n2
print(ans)
