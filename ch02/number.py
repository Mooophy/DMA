'''
algorithms from ch02, Rosen's DMA 5th
    by Yue Wang	28.11.2014
'''

'''
O( log base (num) )
'''
def get_expansion(num, base) :
	expansion = []
	while num>0 :
		expansion = [num%base] + ret
		num //= base
	return expansion