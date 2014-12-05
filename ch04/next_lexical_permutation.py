#!/usr/bin/env python
"""
@author Yue Wang
@date   06.12.2014
@brief  Generate the lexicographically next permutation of a sequence of elements.
        Chapter 4, DMA
"""


def next_permutation(a):
    i = len(a) - 2
    while not (i < 0 or a[i] < a[i+1]):
        i -= 1
    if i < 0:
        return False
    j = len(a) - 1
    while not (a[j] > a[i]):
        j -= 1
    a[i], a[j] = a[j], a[i]        # swap
    a[i+1:] = reversed(a[i+1:])    # reverse
    return True


# test:
li = ['h', 'e', 'l', 'l', 'o']
while next_permutation(li):
    print(li)
"""
@output :
['h', 'e', 'l', 'o', 'l']
['h', 'e', 'o', 'l', 'l']
['h', 'l', 'e', 'l', 'o']
['h', 'l', 'e', 'o', 'l']
['h', 'l', 'l', 'e', 'o']
['h', 'l', 'l', 'o', 'e']
['h', 'l', 'o', 'e', 'l']
['h', 'l', 'o', 'l', 'e']
['h', 'o', 'e', 'l', 'l']
['h', 'o', 'l', 'e', 'l']
['h', 'o', 'l', 'l', 'e']
['l', 'e', 'h', 'l', 'o']
['l', 'e', 'h', 'o', 'l']
['l', 'e', 'l', 'h', 'o']
['l', 'e', 'l', 'o', 'h']
['l', 'e', 'o', 'h', 'l']
['l', 'e', 'o', 'l', 'h']
['l', 'h', 'e', 'l', 'o']
['l', 'h', 'e', 'o', 'l']
['l', 'h', 'l', 'e', 'o']
['l', 'h', 'l', 'o', 'e']
['l', 'h', 'o', 'e', 'l']
['l', 'h', 'o', 'l', 'e']
['l', 'l', 'e', 'h', 'o']
['l', 'l', 'e', 'o', 'h']
['l', 'l', 'h', 'e', 'o']
['l', 'l', 'h', 'o', 'e']
['l', 'l', 'o', 'e', 'h']
['l', 'l', 'o', 'h', 'e']
['l', 'o', 'e', 'h', 'l']
['l', 'o', 'e', 'l', 'h']
['l', 'o', 'h', 'e', 'l']
['l', 'o', 'h', 'l', 'e']
['l', 'o', 'l', 'e', 'h']
['l', 'o', 'l', 'h', 'e']
['o', 'e', 'h', 'l', 'l']
['o', 'e', 'l', 'h', 'l']
['o', 'e', 'l', 'l', 'h']
['o', 'h', 'e', 'l', 'l']
['o', 'h', 'l', 'e', 'l']
['o', 'h', 'l', 'l', 'e']
['o', 'l', 'e', 'h', 'l']
['o', 'l', 'e', 'l', 'h']
['o', 'l', 'h', 'e', 'l']
['o', 'l', 'h', 'l', 'e']
['o', 'l', 'l', 'e', 'h']
['o', 'l', 'l', 'h', 'e']
"""