# Author: Alberta Blue
def bin_to_dec(binary):
    """
    return type: int
    """
    pos = 1
    if binary[0] == 'T':
        pos = -1

    ind = 1
    x = 1
    res = 0
    while ind < len(binary):
        res *= 2
        if binary[ind] == 'T':
            res += x
        ind += 1

    return pos * res

i = 0
while i < len(instructions):
    if instruction[i:i+2] == 'SS':
        binary = []
        while instruction[i] != 'N':
            binary.append(instruction[i])
        res = bin_to_dec(binary)
