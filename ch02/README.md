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
