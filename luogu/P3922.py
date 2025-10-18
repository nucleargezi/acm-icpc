from decimal import Decimal, getcontext
getcontext().prec = 1000
n, k0 = input().split()
n = Decimal(n)
k0 = Decimal(k0)
if n == Decimal('0'):
    k0 = 10 ** k0
print((k0 * Decimal('1.25').log10() + Decimal('0.999999999')) // Decimal('1'))