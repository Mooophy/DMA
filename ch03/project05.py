def generate_formulae(operands, operators, max_size=2):
    expr = operands
    for size in range(max_size-1):
        expr |= {lhs+op+rhs for lhs in expr for op in operators for rhs in expr}
    return expr


ops = {'+', '-', '*', '/'}
exp = {'x', 'y', 'z'}
result = generate_formulae(exp, ops)
print(result)




