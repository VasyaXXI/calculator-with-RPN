#include "stdio.h"
int main()
{
    printf("input through space numbers and signs\n");
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
                printf("result\n%d\n\n", s[n - 1]);
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
                    printf("can't read integer try again\n");
                    fflush(stdin);

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
