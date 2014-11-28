'''
algorithms from ch02 DMA
    by Yue Wang 28.11.2014
'''

#find the max element from the container
def max(seq):
    max = seq[0]
    for elem in seq: 
        if elem > max : max = elem
    return max
'''
def linear_search(l,val):
'''
