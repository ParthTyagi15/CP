def main():
    # input n
    n = int(input())
    # input the list
    v = list(map(int, input().split()))
    j = 0
    ans = 0
    mp = {}
    for i in range(n):
        if(v[i] in mp):
            ans = max(ans,i - j - 1)
            j = max(j, mp[v[i]])
            mp[v[i]] = i
        else:
            ans = max(ans, i - j)
            mp[v[i]] = i
    ans = max(ans, n - j - 1)
    print(ans)



if __name__ == "__main__":
    main()
