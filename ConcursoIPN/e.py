vec = []
p = int(input())
for i in range(p):
    s = input()
    vec.append(s)

n = int(input())

ans = 0
while n > 0:
    ans = ans + 1
    ban = True
    for s in vec:
        if s in str(ans):
            ban = False
            break
    if ban == True:
        n = n - 1

print(ans)