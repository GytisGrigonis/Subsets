#include <stdio.h>

int numbers[256], n = 0, set[256] = {0}, k = 0;
void subset(int, int, int);
void printArray(int *, int );

int main()
{
    FILE *input;
    int i;
    input = fopen("duom.txt", "r");
    fscanf (input, "%d", &numbers[n]);
    n++;
    while (fgetc(input) != EOF){
        fscanf (input, "%d", &numbers[n]);
        n++;
    }
    for (i = 1;i <= n;i++)
        subset(0, 0, i);
    return 0;
}

void subset(int start, int index, int num_sub)
{
    int i, j, sum;
    if (index - start + 1  ==  num_sub)
    {
        if (num_sub  ==  1)
        {
            for (i = 0;i < n;i++)
                if(numbers[i] == 0)
                    printf("Nulinis poaibis: %d\n", numbers[i]);
                else
                    printf("%d\n", numbers[i]);
        }
        else
        {
            for (j = index;j < n;j++)
            {
                sum = 0;
                k = 0;
                for (i = start;i < index;i++){
                    set[k] = numbers[i];
                    k++;
                    sum += numbers[i];
                }
                sum += numbers[j];
                set[k] = numbers[j];
                if(sum == 0){
                    printf("Nulinis poaibis: ");
                    printArray(set, k);
                }
                else
                    printArray(set, k);
            }
            if (start != n - num_sub)
                subset(start + 1, start + 1, num_sub);
        }
    }
    else
    {
        subset(start, index + 1, num_sub);
    }
}

void printArray(int *arr, int n)
{
   int i;
   for (i=0; i <= n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
