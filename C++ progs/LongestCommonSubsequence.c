#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char s1[], char s2[], int m, int n)
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int main()
{
    char s1[100];
    char s2[100];

    scanf("%s", &s1);
    scanf("%s", &s2);

    int m = strlen(s1);
    int n = strlen(s2);

    printf("The length of LCS is : %d", lcs(s1, s2, m, n));

    return 0;
}