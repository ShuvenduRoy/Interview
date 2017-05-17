


class Prime:
    def GetPrimt(self, n):
        pass


    def GetPrimeSmallerThanN(self, n):
        primes = self.SieveOfEratosthenes(n)
        return primes

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


test = Prime()
primes = test.GetPrimeSmallerThanN(10)
print(primes)