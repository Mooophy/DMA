def quick_sort(arr):
    """
    :param arr:
    :return: sorted arr
    :pros : tidy and terse, no write operation on original data, good for multi-threading
    :cons : passing by copy, quite high space complexity compared with C.L.R.S way.
    """
    if not arr:
        return arr
    pivot = arr[0]
    less = quick_sort([elem for elem in arr[1:] if elem < pivot])
    more = quick_sort([elem for elem in arr[1:] if elem >= pivot])
    return less + [pivot] + more


li = [3, 2, 1, 0, 4]
li = quick_sort(li)
print(li)

ls = ["aaa", "1234", "hello", "google", "hi"]
ls = quick_sort(ls)
print(ls)

"""
output :
[0, 1, 2, 3, 4]
['1234', 'aaa', 'google', 'hello', 'hi']
"""
