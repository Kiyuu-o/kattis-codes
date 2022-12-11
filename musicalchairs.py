N = int(input())
nums = list(map(int, input().split()))
index = [i+1 for i in range(N)] 

ind = 0
while N > 1:
    k = nums[ind]
    ind = (ind + k - 1) % N
#    print(ind)
    nums.pop(ind)
    index.pop(ind)
    N -= 1
    if N != 0:
        ind %= N
print(index[0])
