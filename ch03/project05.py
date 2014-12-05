"""
@author Yue Wang
@date   05.12.2014
@brief  Implemented for DMA
@project 05 : generate well-formed formulae for operands : x,y,z and operators : + - * /
"""


def generate_formulae(operands, operators, max_size=2):
    expr = operands
    for size in range(max_size-1):
        expr |= {lhs+op+rhs for lhs in expr for op in operators for rhs in expr}
    return expr


ops = {'+', '-', '*', '/'}
exp = {'x', 'y', 'z'}
result = generate_formulae(exp, ops)
print(result)


"""
@output:
{'y', 'y-x', 'y+x', 'z-z', 'z*y', 'x*x', 'y+z', 'y*x', 'y-z', 'y+y', 'x+z', 'z/y', 'z/z', 'x-y', 'z+x', 'y/x', 'x*y', 'z+y', 'x-z', 'z*z', 'z', 'x/x', 'z-y', 'x+y', 'x*z', 'y/y', 'z/x', 'z*x', 'z-x', 'z+z', 'x/z', 'x/y', 'y/z', 'x+x', 'x', 'y*y', 'y*z', 'y-y', 'x-x'}
"""

