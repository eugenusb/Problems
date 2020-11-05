T = int(raw_input())
V = []

def ind(E):
    global V
    n = len(V)
    if V[n-1] == E:
        return (n-1)
    if V[0] > E:
        return 0

    lo, hi = 0,n-1

    while hi - lo > 1:
        m = (hi + lo) / 2

        if V[m] <= E:
            lo = m
        else:
            hi = m

    return (hi)

for caso in range(1,T+1):
    N,K = map(int, raw_input().split())
    V = map(int, raw_input().split())
    S = [0 for i in range(N+1)]
    V = sorted(V)
    for i in range(N-1,-1,-1) :
        S[i] = S[i+1] + V[i]

    ans = S[0] / (N + .0)

    for i in range(K):
        j = ind(int(ans))
        ans = (S[j] + j * ans) / (N + .0)

    print "Case #" + str(caso) + ": " + str("%.10f" % ans)