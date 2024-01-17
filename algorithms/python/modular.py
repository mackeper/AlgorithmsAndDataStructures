def ext_eclid(a, b):
    if a == 0:
        return (b, 0, 1)

    (gcd, x, y) = ext_eclid(b % a, a)

    return (gcd, y - (b//a) * x, x)


def crt(a1, m1, a2, m2):
    (gcd, n1, n2) = ext_eclid(m1, m2)
    ans = ((a1 * (n2 + m1)) % m1) * m2 + ((a2 * (n1 + m2)) % m2) * m1
    if ans >= m1 * m2:
        ans -= m1 * m2
    return (ans, m1*m2)


def general_crt(a1, m1, a2, m2):
    (gcd, n1, n2) = ext_eclid(m1, m2)
    if (a1 + gcd) % gcd == (a2 + gcd) % gcd:  # unique solution
        lcm = (m1*m2)//gcd
        ans = ((a1 * (n2 + m1)) % m1) * m2 + ((a2 * (n1 + m2)) % m2) * m1
        return (ans//gcd) % lcm
    return -1

