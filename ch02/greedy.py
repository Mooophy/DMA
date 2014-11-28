'''
algorithms from ch02, Rosen's Discrete Mathematics and its Applications 5th
    by Yue Wang
    28.11.2014

'''

'''
Greedy change
'''
def get_change(coins, total):
    ret = []
    for curr in coins :
        while total >= curr :
            ret.append(curr)
            total -= curr
    return ret
