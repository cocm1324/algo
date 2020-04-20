import collections

def cvs(s):
    stack = collections.deque()

    for c in s:
        if len(stack) > 0:
            if stack[-1] == 40 and ord(c) == 41:
                stack.pop()
            else:
                stack.append(ord(c))
        else:
            stack.append(ord(c))
    print(stack)  
    par, wild, prev = 0, 0, 0

    for c in stack:
        print(par, wild, prev)
        if prev == 41 and c == 40:
            print("mark")
            if par == 0 or abs(par) <= wild:
                par, wild, prev = 0, 0, 0
            else:
                return False
        
        prev = c

        if c == 40:
            par += 1
        elif c == 41:
            par -= 1
            if wild + par < 0:
                return False
        elif c == 42:
            wild += 1

    print(par, wild)
    if par == 0 or abs(par) <= wild:
        return True
    else:
        return False

#s1 = "(())(())(((()*()()()))()((()()(*()())))(((*)()"
s2 = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"
#r1 = cvs(s1)
r2 = cvs(s2)
#print(r1)
print(r2)
