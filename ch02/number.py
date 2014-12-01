"""
algorithms from section 2.5, Rosen's DMA 5th
    by Yue Wang 28.11.2014
"""


def get_expansion(num, base=2):
    expansion = []
    while num > 0:
        expansion = [num % base] + expansion
        num //= base
    return expansion


def add(lhs, rhs, base=2):
    l = get_expansion(lhs, base)
    r = get_expansion(rhs, base)
    size = max(len(l), len(r))
    l = [0] * (size-len(l)) + l
    r = [0] * (size-len(r)) + r
    ret = []
    carry = 0
    for i in reversed(range(size)):
        digit_sum = l[i] + r[i] + carry
        ret = [digit_sum % base] + ret
        carry = digit_sum//base
    if carry > 0:
        ret = [carry] + ret
    return ret


def multiply(lhs, rhs):
    l = get_expansion(lhs)
    list_for_ret = []
    for i in range(len(l)):
        if l[i]:
            list_for_ret += [rhs << (len(l) - i - 1)]
    ret = 0
    for num in list_for_ret:
        ret += num
    return ret


def division(lhs, rhs):
    quotient = 0
    remainder = abs(lhs)
    while remainder >= rhs:
        remainder -= rhs
        quotient += 1
    if lhs < 0:
        if remainder > 0:
            remainder = rhs - remainder
            quotient = -(quotient+1)
    return quotient, remainder


def modular_exponentiation(b, n, m):
    expansion = get_expansion(n)
    result = 1
    power = b % m
    for bit in expansion:
        if bit:
            result = result * power % m
        power = power ** 2 % m
    return result


def gcd(lhs, rhs):
    while rhs:
        rmd = lhs % rhs
        lhs = rhs
        rhs = rmd
    return lhs


def is_prime(num):
    if num < 2:
        return False
    for checker in range(3, num//2+1, 2):
        if num % checker == 0:
            return False
    return True