#include "stdio.h"
int main()
{
    printf("INPUT THROUGH SPACE NUMBERS AND SIGNS\n");
    int s[1000];
    int n = 0;  /*array index for a new number*/
    while (!feof(stdin))
    {
        int c = getchar();
        int x;
        switch (c)
        {
            case  ' ':
                break;
            case '\n':
                printf("RESULT\n%d\n\n", s[n - 1]);
                n--;
                break;
            case '+':
                s[n-2] = s[n-2] + s[n-1];
                n--;
                break;
            case '-':
                s[n-2] = s[n-2] - s[n-1];
                n--;
                break;
            case '*':
                s[n-2] = s[n-1] * s[n-2];
                n--;
                break;
            case '/':
                s[n-2] = s[n-2] / s[n-1];
                n--;
                break;
            default:
                ungetc (c, stdin);  /*return symbol back*/
                if(scanf("%d", &x) != 1)
                {
                    printf("CAN'T READ INTEGER\n");
                    return 1;
                }
                else
                {
                    s[n] = x;
                    n++;
                }
        }
    }
    return 0;
 }
