#include <stdio.h>
#include <stdlib.h>
int place(int box[], int k, int j)
{
    for (int i = 0; i < k; i++)
    {
        if (box[i] == j || (abs(box[i] - j) == abs(i - k)))
        return 1;
    }
    return 0;
}
void Nqueens(int box[], int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (place(box, k, i) == 0)
        {
            box[k] = i;
            if (k == n - 1)
            {
                printf("solution : \n");
                for (int a = 0; a < n; a++)
                printf("queen %d is placed at column %d\n", a + 1, box[a] + 1);
                printf("\n");
            }
            else
                Nqueens(box, k + 1, n);
        }
    }
}
int main()
{
    int box[100],n;
    scanf("%d",&n);
    Nqueens(box, 0, n);
    return 0;
}
