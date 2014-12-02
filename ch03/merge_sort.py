def merge(seq, first, mid, last):
    left = seq[first: mid]
    right = seq[mid: last]
    l, r = 0, 0
    curr = first
    while l != len(left) and r != len(right):
        if left[l] < right[r]:
            seq[curr] = left[l]
            l += 1
        else:
            seq[curr] = right[r]
            r += 1
        curr += 1
    (x, rest) = (r, right) if l == len(left) else (l, left)
    for idx in range(x, len(rest)):
        seq[curr] = rest[x]
        curr += 1
        x += 1


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
