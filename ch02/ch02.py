'''
algorithms from ch02 DMA
    by Yue Wang 28.11.2014
'''

#find the max element from the container
def max(seq):
    max = seq[0]
    for elem in seq : 
        if elem > max   :   max = elem
    return max

#linear search
def linear_search(seq,val):
    for idx,elem in enumerate(seq):
        if elem == val  :   return idx
    return None

def binary_search(seq,val):
	beg = 0
	end = len(seq)
	while beg < end	:
		mid = beg + (end - beg)//2
		if seq[mid] == val:	
			return mid
		elif seq[mid] > val:	
			end = mid
		else:	
			beg = mid
	return None	



		




