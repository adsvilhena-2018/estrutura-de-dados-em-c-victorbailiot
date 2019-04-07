#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10], no,  i, j, c, heap, temp;
    printf("Digite a quantidade de itens no Heap: ");
    scanf("%d", &no);
    printf("\nInsira os valores: ");
    for (i = 0; i <  no; i++)
        scanf("%d", &arr[i]);
    for (i = 1; i <  no; i++)
    {
        c = i;
        do
        {
            heap  = (c - 1) / 2;
            if  (arr[heap] < arr[c])
            {
                temp =  arr[heap];
                arr[heap] = arr[c];
                arr[c]  = temp;
            }
            c =  heap;
        } while (c !=  0);
    }

    printf("Numeros digitados : ");
    for (i = 0; i <  no; i++)
        printf("%d\t ", arr[i]);
    for (j = no - 1; j  >= 0; j--)
    {
        temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
        heap = 0;
        do
        {
            c = 2 *  heap + 1;
            if  ((arr[c] < arr[c + 1]) && c < j-1)
                c++;
            if  (arr[heap]<arr[c] && c<j)
            {
                temp =  arr[heap];
                arr[heap] = arr[c];
                arr[c]  = temp;
            }
            heap = c;
        } while (c  < j);
    }
    printf("\nEm Max heap : ");
    for (i = 0; i <  no; i++)
        printf("\t%d", arr[i]);
    printf("\n");
}
