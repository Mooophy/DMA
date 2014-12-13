Chapter 02
-----------------
######project01
```python
import search_and_sort as sas

li = [1, 2, 3, 5, 2, 1]
print(sas.max(li))
"""
output :
5
"""
```

######project02
```python
import search_and_sort as ss

def project02(li):
    maximum = ss.max(li)
    size = len(li)
    first = 0
    for idx in range(size):
        if li[idx] == maximum:
            first = idx
            break
    last = 0
    for idx in reversed(range(size)):
        if li[idx] == maximum:
            last = idx
            break
    return first, last
    
seq = [1, 3, 2, 3, 1]
fis, las = project02(seq)
print(fis, las)
"""
output :
1 3
"""
```

######project03
```python
import search_and_sort as ss

li = [78,1, 2, 3, 6, 9]
print(ss.linear_search(li, 3))
"""
output :
3
"""
```

######project04
```python
import search_and_sort as ss

li = [78,1, 2, 3, 6, 9]
print(ss.binary_search(li, 3))
"""
output :
3
"""
```

######project05
- My Python version:
```python
import search_and_sort as ss

li = [78,1, 2, 3, 6, 9]
ss.bubble_sort(li)
print(li)
"""
output :
[1, 2, 3, 6, 9, 78]
"""
```
- My Haskell version:
```haskell
bubbleSort :: (Ord a) => [a] -> [a]
bubbleSort [] = []
bubbleSort xs = bubbleSort [x|x<-xs, x < maximum xs] ++ [x|x<-xs, x == maximum xs]
```

######project06
```python
import search_and_sort as ss

li = [78,1, 2, 3, 6, 9]
ss.insertion_sort(li)
print(li)
"""
output :
[1, 2, 3, 6, 9, 78]
"""
```

######project07
```python
import greedy as grd

coins = [25, 10, 5, 1]
print(grd.get_change(coins, 149))
"""
output :
[25, 25, 25, 25, 25, 10, 10, 1, 1, 1, 1]
"""
```

######project08
```python
def linear_search_and_count(seq, val):
    """
    :rtype : int, int
    """
    pos = None
    cnt = 0
    for i in range(len(seq)):
        cnt += 1
        if seq[i] == val:
            pos = i
            break
    return pos, cnt


def binary_search_and_count(seq, val):
    """
    :rtype : int, int
    """
    pos = None
    cnt = 0
    beg = 0
    end = len(seq)
    while beg < end:
        mid = beg + (end - beg)//2
        if seq[mid] == val:
            cnt += 1
            pos = mid
            break
        elif seq[mid] < val:
            cnt += 1
            beg = mid
        else:
            end = mid
    return pos, cnt

seq = [num for num in range(50000)]
print(linear_search_and_count(seq, 48800))
print(binary_search_and_count(seq, 48800))
"""
output :
(48800, 48801)
(48800, 12)
"""
```

######project09
```python
def insertion_sort_and_count(seq):
    size = len(seq)
    if size < 2:
        return 0

    cnt = 0
    for i in range(1, size):
        key = seq[i]
        j = i-1
        while j > -1 and seq[j] > key:
            seq[j+1] = seq[j]
            j -= 1
            cnt += 1
        seq[j+1] = key
    return cnt


def bubble_sort_and_count(seq):
    size = len(seq)
    if size < 2:
        return 0

    cnt = 0
    for i in range(size-1):
        for j in range(size-1-i):
            cnt += 1
            if seq[j] > seq[j+1]:
                seq[j], seq[j+1] = seq[j+1], seq[j]
    return cnt

sequence1 = [1, 2, 6, 7, 1, 2, 3, 4, 56, 7, 8, 9, 3, 34, 2]
sequence2 = list(sequence1)

count1 = insertion_sort_and_count(sequence1)
print(sequence1, count1)

count2 = bubble_sort_and_count(sequence2)
print(sequence2, count2)
"""
output :
[1, 1, 2, 2, 2, 3, 3, 4, 6, 7, 7, 8, 9, 34, 56] 30
[1, 1, 2, 2, 2, 3, 3, 4, 6, 7, 7, 8, 9, 34, 56] 105
"""
```

######project10
```python
def is_prime(num):
    if num < 2:
        return False
    for checker in range(3, num//2+1, 2):
        if num % checker == 0:
            return False
    return True

for number in range(900, 1000):
    if is_prime(number):
        print(number, end=" ")
"""
output :
907 911 919 929 937 941 947 953 967 971 977 983 991 997
"""
```

######project11 encrypt and decrypt using Caesar cipher
```python
def encrypt(msg, offset=3):
    ret = ''
    for c in msg:
        ret += chr((ord(c) + offset) % 255)
    return ret


def decrypt(msg, offset=3):
    ret = ''
    for c in msg:
        ret += chr((ord(c) - offset) % 255)
    return ret


sonnet = encrypt("From fairest creatures we desire increase")
print(sonnet)
dec = decrypt(sonnet)
print(dec)
"""
output :
Iurp#idluhvw#fuhdwxuhv#zh#ghvluh#lqfuhdvh
From fairest creatures we desire increase
"""
```

######project12 Greatest common divisor
```python
import number as num

print(num.gcd(60, 90))
"""
output :
30
"""
```

######project13 Least common multiple
```python
def lcm(lhs, rhs):
    import number as num
    return lhs * rhs // num.gcd(lhs, rhs)

print(lcm(60, 90))
"""
output :
180
"""
```
######project14 Prime factorization
```python
def get_prime_factorization(num):
    factorization = [d for d in range(1, num//2 + 1) if num % d == 0]
    import number as n
    return [elem for elem in factorization if n.is_prime(elem)]

print(get_prime_factorization(80))
"""
output :
[2, 4, 5]
"""
```

######project15 Expansion
```python
def project15(num, base):
    import number as n
    return n.get_expansion(num, base)

print(project15(10, 2))
print(project15(20, 16))
"""
output :
[1, 0, 1, 0]
[1, 4]
"""
```

######project16 `a^b mod m`
```python
#use number.modular_exponentiation
```

######project17 Cantor expansion
```python
def make_factorial_list(size=13):
    ret = [0] * size
    ret[0] = 1
    for idx in range(1, size):
        ret[idx] = idx * ret[idx-1]
    return ret


def cantor_expansion(num):
    fac_seq = make_factorial_list(15)
    ret = [0] * 15
    for curr in reversed(range(15)):
        while fac_seq[curr] <= num:
            num -= fac_seq[curr]
            ret[curr] += 1
    return ret


expansion = cantor_expansion(10001)
print(expansion)
"""
output :
[1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200]
[0, 1, 2, 2, 1, 5, 6, 1, 0, 0, 0, 0, 0, 0, 0]
"""
```

######project18 Random generator by linear congruential generator Xn+1 = (aXn + c) % c
```python
def generate_pseudorandom_sequence(n, m, a, c, x0):
    """
    :argument m must be the largest among m,a, and x0
    """
    seq = [x0]
    for i in range(1, n):
        elem = (a * seq[i-1] + c) % m
        seq.append(elem)
    return seq

print(generate_pseudorandom_sequence(10, 21, 2, 1, 9))
"""
output :
[9, 19, 18, 16, 12, 4, 9, 19, 18, 16]
"""
```

######project22 Matrix power
```python
def matrix_power(m, power):
    import mat
    result = m
    for p in range(power-1):
        result = mat.multiply(result, m)
    return result


m = [[1, 2], [3, 4]]
ret = matrix_power(m, 4)
print(ret)

"""
output :
[[199, 290], [435, 634]][[199, 290], [435, 634]]
"""
```

######project23 Is symmetric?
```python
def is_symmetric(m):
    return m == [list(i) for i in zip(*m)]

m1 = [(1, 2), (3, 4)]
print(is_symmetric(m1))
m2 = [[1, 1, 0], [1, 0, 1],[0, 1, 0]]
print(is_symmetric(m2))

"""
output :
False
True
"""
```

######project25 Meet and join
```python
def join(lhs, rhs):
    rows = len(lhs)
    cols = len(lhs[0])
    ret = [[0 for _ in range(cols)] for _ in range(rows)]
    for r in range(rows):
        for c in range(cols):
            ret[r][c] = lhs[r][c] or rhs[r][c]
    return ret


def meet(lhs, rhs):
    rows = len(lhs)
    cols = len(lhs[0])
    ret = [[0 for _ in range(cols)] for _ in range(rows)]
    for r in range(rows):
        for c in range(cols):
            ret[r][c] = lhs[r][c] and rhs[r][c]
    return ret

l = [[1, 0], [0, 1]]
r = [[0, 0], [0, 1]]
print("join :", join(r, l))
print("meet :", meet(r, l))


"""
output :
join : [[1, 0], [0, 1]]
meet : [[0, 0], [0, 1]]
"""
```

######project26 Boolean product
```python
#using boolean_multiply in mat.py
```

######project27 Boolean matrix power
```python
#similar to project 22, but use meet and join instead.
```
