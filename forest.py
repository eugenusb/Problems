from random import randint, seed

seed(123456789)

T = int(raw_input())

DP = []
P = []
ch = []
vis = []

def dfs(v):
    global DP
    global ch
    global vis

    acum = 1
    vis[v] = True
    
    if v in ch:
        for u in ch[v]:
            if not vis[u]:
                dfs(u)
                acum += DP[u]

    DP[v] = acum


for caso in range(1,T+1):
    N = int(raw_input())
    P = map(int, raw_input().split())
    initial = raw_input()
    M = int(raw_input())
    cool = raw_input().split()
    DP = [0 for i in range(N+1)]
    vis = [False for i in range(N+1)]
    ch = {}

    for i in range(N):
        if P[i] in ch:
            ch[P[i]] += [i+1]
        else:
            ch[P[i]] = [i+1]

    for v in range(1,N+1):
        if not(vis[v]):
            dfs(v)

    ans = [0 for i in range(M)]

    S = 10000

    for sim in range(S):
        
        active = ch[0][:]
        weights = [DP[x] for x in active]

        word = ""        

        for i in range(N):
            C = sum(weights)
            #print sim,i,C,active
            #print active, weights
            index = randint(1,C)
            acum = 0
            for j in range(len(weights)):
                if acum <= index and index <= (acum + weights[j]):
                    index = j
                    break
                else:
                    acum += weights[j]
            
            course = active[index]
            word += initial[course-1]
            active.remove(course)
            weights.remove(DP[course])
            if course in ch:
                active += ch[course]
                for x in ch[course]:
                    weights += [DP[x]]

        for j in range(M):
            if cool[j] in word:
                ans[j] += 1

    s = ""
    for j in range(M):
        ans[j] = (ans[j] / (S + 0.0))
        s += str("%.10f" % ans[j])
        if j < M - 1:
            s += " "

    print "Case #" + str(caso) + ": " + s