'''
algorithms from section 2.5, Rosen's DMA 5th
    by Yue Wang 28.11.2014
'''

'''
Constructing Base b Expansions
O( log base (num) )
'''
def get_expansion(num, base=2) :
    expansion = []
    while num>0 :
        expansion = [num%base] + expansion
        num //= base
    return expansion

'''
O(n)
'''
def add(lhs, rhs, base=2) :
    l = get_expansion(lhs,base)
    r = get_expansion(rhs,base)
    size = max(len(l),len(r))
    l = [0] * (size-len(l)) + l
    r = [0] * (size-len(r)) + r
    ret = []
    carry = 0
    for i in reversed(range(size)) :
        digit_sum = l[i] + r[i] + carry
        ret = [digit_sum % base] + ret
        carry = digit_sum//base
    if(carry>0):
        ret = [carry] + ret
    return ret
