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
Addition of Integers
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

'''
Multiplying Intergers
O(n)
'''
def multiply(lhs, rhs) :
    l = get_expansion(lhs)
    list_for_ret = []
    for i in range(len(l)) :
        if l[i] :
            list_for_ret += [rhs << (len(l) - i - 1)]
    ret = 0
    for num in list_for_ret :
        ret += num
    return ret

'''
Computing div and mod
O(n)
@note rhs must be greater than 0
'''
def division(lhs, rhs) :
    quotient    = 0
    remainder   = abs(lhs)
    while remainder >= rhs :
        remainder   -= rhs
        quotient    += 1
    if lhs<0 and remainder>0 :
        remainder   = rhs - remainder
        quotient    = -(quotient+1)
    return (quotient,remainder)
