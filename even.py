T = int(raw_input())

def check(M):
    bad = "13579"
    ms = str(M)
    for let in bad:
        if let in ms:
            return False

    return True

for caso in range(1,T+1):
    N = int(raw_input())
    li = map(int,str(N))
    
    ans = 10**18
    need = False
    
    #print N, li

    for i in range(len(li)):
        d = li[i]
        if d % 2 != 0:
            # plus
            carry = 0
            pl = []
            for j in range(len(li)-1,i,-1):
                pl += [0]
            
            pl += [(li[i]+1) % 10]
            
            ind = i-1
            
            if li[i] == 9:
                cur = li[ind] + 1
                while ind >= 0 and cur == 9:
                    pl += [0]
                    ind -= 1 
                    cur = 1 + li[ind]
                if ind < 0:
                    pl += [2]
                else:
                    pl += [cur+1]
            for j in range(ind,-1,-1):
                pl += [li[j]]
            
            cnd_pl = 0
            pot = 1
            for j in range(len(pl)):
                cnd_pl += (pl[j] * pot)
                pot *= 10
            cnd_pl = cnd_pl - N
            
            # less
            le = []
            for j in range(len(li)):
                if j < i:
                    le += [li[j]]
                if j == i:
                    le += [(li[j] - 1)]
                if j > i:
                    le += [8]
            le = le[::-1]
            cnd_le = 0
            pot = 1
            for j in range(len(le)):
                cnd_le += (le[j] * pot)
                pot *= 10
            cnd_le = N - cnd_le
            
            ans = min(cnd_pl, cnd_le)
            
            need = True
            
            #print pl,cnd_pl,le,cnd_le
            break
    
    #posta = 0

    #for k in range(N+1):
    #    if(check(N-k) or check(N+k)):
    #        posta = k
    #        break

    if not(need):
        ans = 0
    
    #if ans != posta:
    #    print "CACA", ans, posta, N

    print "Case #" + str(caso) + ": " + str(ans)