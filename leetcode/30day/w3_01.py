def pe(nums):
    former = [1]
    latter = [1]
    ans = []
    for i in range(len(nums) -1 ):
        former.append(nums[i] * former[i])
        latter.insert(0, nums[len(nums) - i - 1] * latter[0])
    for i in range(len(former)):
        ans.append(former[i] * latter[i])

    return ans

a = [1,2,3,4]
r = pe(a)
print(r)
