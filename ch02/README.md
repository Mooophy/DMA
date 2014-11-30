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
import search_and_sort as sas


def project02(li):
    maximum = sas.max(li)
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
