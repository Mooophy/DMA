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
