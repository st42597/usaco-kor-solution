N = int(input())
A = []
for i in range(N):
    a, b, c = input().split()
    if b == 'Bessie': b = 0
    elif b == 'Elsie': b = 1
    elif b == 'Mildred': b = 2
    a = int(a)
    c = int(c)
    A.append([a, b, c])
A.sort()
    
p = [7, 7, 7]
last_winner = [0, 1, 2]
ans = 0

for a, b, c in A:
    p[b] += c
    winner = []
    for i in range(3):
        if p[i] == max(p):
            winner.append(i)
    if last_winner != winner:
        ans += 1
        last_winner = winner

print(ans)