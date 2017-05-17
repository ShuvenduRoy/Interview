


class Prime:
    def GetPrimt(self, n):
        pass


    def GetPrimeSmallerThanN(self, n):
        primes = self.SieveOfEratosthenes2(n)
        return primes

    # Complexity O(n log(log n) )
    def SieveOfEratosthenes(self, n):
        primes = [True for i in range(n+1)]
        # initialize first prime number
        p = 2

        while p * p <= n:
            if primes[p]:
                for i in range(p*2, n+1, p):
                    primes[i] = False

            p+=1

        ans = []

        for i in range(n+1):
            if primes[i]:
                ans.append(i)

        return ans

    # Complexity of O(n)
    def SieveOfEratosthenes2(self, n):
        SPF = [0 for i in range(n+1)]
        isPrime = [True for i in range(n+1)]
        isPrime[0] = isPrime[1] = False

        primes = []

        for i in range (2, n+1):
            if isPrime[i]:
                primes.append(i)
                SPF[i] = i

            j = 0
            while j<len(primes) and i*primes[j]<=n and primes[j] <= SPF[i]:
                isPrime[primes[j] * i] = False
                SPF[i * primes[j]] = primes[j]
                j+=1

        return primes


test = Prime()
primes = test.GetPrimeSmallerThanN(100)
print(primes)