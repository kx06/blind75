def isValid(s):
    stack = []
    dict = {"(": ")", "[": "]", "{": "}"}
    for i in s:
        if i == "(" or i == "{" or i == "[":
            stack.append(i)
        if i == ")" or i == "}" or i == "]":
            if len(stack) == 0:
                continue
            if dict[stack[-1]] == i:
                stack.pop()
                continue
            else:
                return False
    if len(stack) != 0:
        return False
    return True


string = "()"
res = isValid(string)
print(res)
