# sieve of eratosthenes
# find all prime numbers less than
def find_primes(n):
    primes = []
    sieve = [True] * (n + 1)
    for p in range(2, n + 1):
        if sieve[p]:
            primes.append(p)
            for i in range(p * p, n + 1, p):
                sieve[i] = False
    return primes


# find all prime factors of n
def find_prime_factors(n, primes):
    factors = []
    for p in primes:
        if n % p == 0:
            factors.append(p)
    return factors


if __name__ == "__main__":
    # Too large... ofc
    # primes = find_primes(100000000)
    # print(find_prime_factors(769457290801263793712740792519696786147248001937382943813345728685422050738403253, primes))

    # FactorDB
    p = 1617549722683965197900599011412144490161
    q = 475693130177488446807040098678772442581573
    c = 8533139361076999596208540806559574687666062896040360148742851107661304651861689
    n = 769457290801263793712740792519696786147248001937382943813345728685422050738403253
    e = 65537

    totient = (p - 1) * (q - 1)
    d = pow(e, -1, totient)
    message = pow(c, d, n)

    print(message)
    print(hex(message))
    print(bytes.fromhex(hex(message)[2:]).decode("utf-8"))
