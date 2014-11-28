'''
algorithms from ch02, Rosen's DMA 5th
    by Yue Wang	28.11.2014
'''

'''
O( log base (num) )
'''
def get_expansion(num, base) :
	ret = []
	while num>0 :
		ret = [num%base] + ret
		num //= base
	return ret