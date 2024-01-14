def main():
    # input n and x
    n, x = map(int, input().split())
    # input the list
    values = list(map(int, input().split()))
    # define a map
    mp = {}

    for i in range(n):
        if x - values[i] in mp:
            print(i + 1, mp[x - values[i]])
            return
        mp[values[i]] = i + 1

    print("IMPOSSIBLE")


if __name__ == "__main__":
    main()
