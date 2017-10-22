#include "stdio.h"
int main()
{
    printf("INPUT THROUGH SPACE NUMBERS AND SIGNS\n");
    int stack[1000];
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
                printf("RESULT\n%d\n", stack[n - 1]);
                n--;
                break;
            case '+':
                stack[n-2] = stack[n-2] + stack[n-1];
                n--;
                break;
            case '-':
                stack[n-2] = stack[n-2] - stack[n-1];
                n--;
                break;
            case '*':
                stack[n-2] = stack[n-1] * stack[n-2];
                n--;
                break;
            case '/':
                stack[n-2] = stack[n-2] / stack[n-1];
                n--;
                break;
            default:
                ungetc (c, stdin);  /*return symbol back*/
                if(scanf("%d", &x) != 1)
                {
                    printf("CAN'T READ INTEGER\n");
                    return 0;
                }
                else
                {
                    stack[n] = x;
                    n++;
                }
        }
    }
    return 0;
 }
