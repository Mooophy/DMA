'''
algorithms from ch02, DMA.
    by Yue Wang
    28.11.2014
'''

'''
max O(n)
'''
def max(seq):
    max = seq[0]
    for elem in seq:
        if elem > max   :   max = elem
    return max

'''
linear seach O(n)
'''
def linear_search(seq,val):
    for idx,elem in enumerate(seq):
        if elem == val  :   return idx
    return None

'''
binary search O(lg n)
'''
def binary_search(seq,val):
    beg = 0
    end = len(seq)
    while beg < end:
        mid = beg + (end-beg)//2
        if seq[mid] == val  :   return mid
        elif seq[mid] > val :   end = mid
        else                :   beg = mid
    return None

'''
insertion sort O(lg n ^ 2)
'''
def insertion_sort(seq):
    if len(seq) < 2 : return
    for i in range(1,len(seq)):
        key = seq[i]
        j = i-1
        while(j > -1 and seq[j] > key):
            seq[j+1] = seq[j]
            j -= 1
        seq[j+1] = key

'''
bubble sort O(lg n ^ 2)
'''
def bubble_sort(seq):
    size = len(seq)
    if size < 2 : return
    for i in range(size-1) :
        for j in range(size-1-i):
            if(seq[j] > seq[j+1]): seq[j],seq[j+1] = seq[j+1], seq[j]
