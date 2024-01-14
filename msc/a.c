#include <stdio.h>

int main()
{
    char *ptr;
    char m[] = "The LNMIIT Jaipur";
    ptr = m;
    ptr += 5;
    printf("%d\n",ptr);
    printf("%s", ptr + ptr[6] - ptr[3]);
}
