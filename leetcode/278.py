def isBadVersion(version):
    return False if version < 99 else True

def firstBadVersion(n):
    isMinVerBad = isBadVersion(1)
    if (isMinVerBad):
        return 1
    
    print(findBadVersion(1, n))
    

def findBadVersion(minQuo, maxQuo):
    median = int((minQuo + maxQuo) / 2)
    
    if (isBadVersion(median)):
        if(minQuo == median - 1):
            return median
        else:
            return findBadVersion(minQuo, median)
    else:
        if(maxQuo == median + 1):
            return maxQuo
        else:
            return findBadVersion(median, maxQuo)


firstBadVersion(101)
