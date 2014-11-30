"""
Implementing algorithms from section 2.5, DMA 5th
    by Yue Wang 30.11.2014
"""


def multiply(lhs, rhs):
    rows = len(lhs)
    cols = len(rhs[0])
    common_range = len(lhs[0])
    product = [[0 for _ in range(cols)] for _ in range(rows)]   # List Comprehensions
    for r in range(rows):
        for c in range(cols):
            for com in range(common_range):
                product[r][c] += lhs[r][com] * rhs[com][c]
    return product