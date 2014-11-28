'''
algorithms from ch02 DMA
    by Yue Wang 28.11.2014
'''

#find the max element from the container
def max(list):
    max = list[0]
    for elem in range(0,len(list)) : 
        if(elem) > max : max = elem
    return max

