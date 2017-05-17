class Prime:
    @staticmethod
    def get_first_n_prime(n):
        return Prime.prime_historic(n)

    @staticmethod
    def get_prime_smaller_than_n(n):
        primes = Prime.sieve_of_eratosthenes_2(n)
        return primes

    # Complexity O(n log(log n) )
    @staticmethod
    def sieve_of_eratosthenes(n):
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
    @staticmethod
    def sieve_of_eratosthenes_2(n):
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

    @staticmethod
    def prime_historic(n):
        primes = set([2])
        i = 2

        while len(primes)<n:
            Prime.is_prime(i, primes)
            i += 1
        return primes

    @staticmethod
    def is_prime(i, primes):
        for prime in primes:
            if not (i == prime or i % prime):
                return False
        primes.add(i)


    @staticmethod
    def is_prime_regex(n):
        import re
        # see http://tinyurl.com/3dbhjv
        return re.match(r'^1?$|^(11+?)\1+$', '1' * n) == None


test = Prime()
primes = test.get_first_n_prime(10)
print(primes)