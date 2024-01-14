def main():
    # input n and x
    n = int(input())
    # input the list
    v = list(map(int, input().split()))
    curSum = 0
    ans = max(v)
    for i in range(n):
        curSum += v[i]
        ans = max(ans, curSum)
        if curSum < 0:
            curSum = 0

    print(ans)


if __name__ == "__main__":
    main()
