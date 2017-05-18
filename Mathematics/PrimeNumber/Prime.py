from itertools import islice


class Prime:
    @staticmethod
    def get_first_n_prime(n):
        # return Prime.prime_historic(n)
        return list(islice((p for p in Prime.posponded_sieve()), 0, n))

    @staticmethod
    def get_prime_smaller_than_n(n):
        # primes = Prime.sieve_of_eratosthenes_2(n)
        primes = Prime.sieve_of_atkin(n)
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

            p += 1

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
        primes = [2]
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
        primes.append(i)

    @staticmethod
    def is_prime_regex(n):
        import re
        # see http://tinyurl.com/3dbhjv
        return re.match(r'^1?$|^(11+?)\1+$', '1' * n) == None

    @staticmethod
    def regexp(n):
        M = 100  # upper-bound of search space
        l = list()  # result list

        while len(l) < n:
            l += filter(Prime.is_prime_regex, range(M - 100, M))  # append prime element of [M - 100, M] to l
            M += 100  # increment upper-bound

        return l[:n]  # print result list limited to N elements

    # Posponded Sieve
    # O(sqrt(n))
    @staticmethod
    def posponded_sieve():
        from itertools import count

        yield 2; yield 3; yield 5; yield 7;
        sieve = {}

        ps = Prime.posponded_sieve()
        p = next(ps) and next(ps)  # (3) a Prime to add to dict
        q = p * p  # (9) its sQuare
        for c in count(9, 2):  # the Candidate
            if c in sieve:  # c's a multiple of some base prime
                s = sieve.pop(c)  # i.e. a composite ; or
            elif c < q:
                yield c  # a prime
                continue
            else:  # (c==q):            # or the next base prime's square:
                s = count(q + 2 * p, 2 * p)  # (9+6, by 6 : 15,21,27,33,...)
                p = next(ps)  # (5)
                q = p * p  # (25)
            for m in s:  # the next multiple
                if m not in sieve:  # no duplicates
                    break
            sieve[m] = s

    # Sieve of atkin
    # http://www.geeksforgeeks.org/sieve-of-atkin/
    # http://stackoverflow.com/questions/10580159/sieve-of-atkin-explanation-and-java-example
    # O(n / log log(n) )
    @staticmethod
    def sieve_of_atkin(limit):
        primes = []
        if limit>2:
            primes.append(2)
        if limit>3:
            primes.append(3)

        sieve = [False] * (limit+1)

        for x in range(1, limit):
            if x*x>=limit:
                break
            for y in range(1, limit):
                if y*y >= limit:
                    break

                n = (4*x*x) + (y*y)
                if n <= limit and (n % 12 == 1 or n % 12 == 5):
                    sieve[n] ^= True

                n = (3*x*x) + (y*y)
                if n <= limit and n%12 == 7:
                    sieve[n] ^= True

                n = (3 * x * x) - (y * y)
                if x>y and n <= limit and n % 12 == 11:
                    sieve[n] ^= True

        for r in range(5, n):
            if r*r>n:
                break

            for i in range (r*r, n, r*r):
                sieve[i] = False

        for i in range(5, limit):
            if sieve[i]:
                primes.append(i)

        return primes

print(Prime.sieve_of_atkin(12))