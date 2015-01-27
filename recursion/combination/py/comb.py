def combination(A):
    if not A: return [[]]
    first = A[0]
    remain = A[1:]
    remain_comb = combination(remain)
    addition_comb = []
    for comb in remain_comb:
        addition_comb.append([first] + comb)
    return remain_comb + addition_comb
