#!/usr/bin/env python

def quick_sort(arr):
    """
    :param : arr
    :return: sorted arr
    :pros : tidy and terse, no write operation on original data, good for multi-threading
    :cons : passing by copy, quite high space complexity compared with C.L.R.S way.
    """
    if len(arr) < 2:
        return arr
    pivot = arr[0]
    less = quick_sort([elem for elem in arr[1:] if elem < pivot])
    more = quick_sort([elem for elem in arr[1:] if elem >= pivot])
    return less + [pivot] + more


def quick_sort_2_pointers(arr, first, last):
    """
     C.L.R.S style that uses fast and slow pointers to sort in place.
     O(1) for space complexity.
    """
    if last-first < 2:
        return arr
    pivot, slow = last-1, first-1
    for fast in range(first, pivot):
        if arr[fast] <= arr[pivot]:
            slow += 1
            arr[fast], arr[slow] = arr[slow], arr[fast]
    arr[pivot], arr[slow+1] = arr[slow+1], arr[pivot]
    pivot = slow+1
    quick_sort_2_pointers(arr, first, pivot)
    quick_sort_2_pointers(arr, pivot+1, last)


li = [3, 2, 1, 0, 4]
li = quick_sort(li)
print(li)
ls = ["aaa", "1234", "hello", "google", "hi"]
ls = quick_sort(ls)
print(ls)

li2 = [3, 2, 1, 0, 4]
quick_sort_2_pointers(li2, 0, len(li))
print(li2)
ls2 = ["aaa", "1234", "hello", "google", "hi"]
quick_sort_2_pointers(ls2, 0, len(ls2))
print(ls2)


"""
output:
[0, 1, 2, 3, 4]
['1234', 'aaa', 'google', 'hello', 'hi']
[0, 1, 2, 3, 4]
['1234', 'aaa', 'google', 'hello', 'hi']
"""
