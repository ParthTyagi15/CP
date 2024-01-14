def main():
    # input n
    n = int(input())
    # input the list
    v = list(map(int, input().split()))
    v.sort()
    x = v[int((n - 1) / 2)]
    ans = 0
    for i in range(n):
        ans+=abs(x - v[i])
    print(ans)


if __name__ == "__main__":
    main()
