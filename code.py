from functools import cmp_to_key

P = int(input())
T = int(input())
seed = int(input())
MP = int(input())
MT = int(input())

state = seed

A, D = [], []
for i in range(0, P):
    state = (state * 1103515245 + 12345) % (2 ** 31)
    A.append((state // 10) % MP)
    state = (state * 1103515245 + 12345) % (2 ** 31)
    D.append((state // 10) % MP)

TA, TD = [], []
for j in range(0, T):
    state = (state * 1103515245 + 12345) % (2 ** 31)
    TA.append((state // 10) % MT);
    state = (state * 1103515245 + 12345) % (2 ** 31)
    TD.append((state // 10) % MT);

print(A)
print(D)

V = []
for i in range(0, P):
    V.append((A[i], D[i], i))

def cmp(p, q):
    if max(p[0], p[1]) > max(q[0], q[1]):
        return -1
    else:
        return 1

V = sorted(V, key=cmp_to_key(cmp))
print(V)
