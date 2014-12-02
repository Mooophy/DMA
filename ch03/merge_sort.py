def merge(seq, first, mid, last):
    left = seq[first: mid]
    right = seq[mid: last]
    l = 0
    r = 0
    curr = first
    while l != len(left) and r != len(right):
        if left[l] < right[r]:
            seq[curr] = left[l]
            l += 1
        else:
            seq[curr] = right[r]
            r += 1
        curr += 1
    if l == len(left):
        while r != len(right):
            seq[curr] = right[r]
            curr += 1
            r += 1
    else:
        while l != len(left):
            seq[curr] = left[l]
            curr += 1
            l += 1


def merge_sort(seq, first, last):
    if first + 1 < last:
        mid = first + (last-first)//2
        merge_sort(seq, first, mid)
        merge_sort(seq, mid, last)
        merge(seq, first, mid, last)


li = [4, 3, 2, 1]
merge_sort(li, 0, len(li))
print(li)

ls = ["aaa", "1234", "hello", "google", "hi"]
merge_sort(ls, 0, len(ls))
print(ls)

"""
output:
[1, 2, 3, 4]
['1234', 'aaa', 'google', 'hello', 'hi']
"""
