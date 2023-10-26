#include<stdio.h>
#include<stdlib.h>

void Swap_Elements(int* e1, int* e2)
{
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

int Partition(int* A, int low, int high)
{
    int pivot_element = A[high], i, j;
    i = (low - 1);
    for(j=low; j<=high-1; j++)
    {
        if(A[j] <= pivot_element)
        {
           i++;
           Swap_Elements(&A[i], &A[j]);
        }
    }
    Swap_Elements(&A[i+1], &A[high]);
    return (i+1);
}

void quick_sort(int *A, int low, int high)
{
    if(low < high)
    {
        int k = Partition(A,low,high);
        quick_sort(A,low,k-1);
        quick_sort(A,k+1,high);

    }

}

void print_array(int *A,int N)
{
    int i;
    for( i=0; i<N; i++)
       printf("%d \t", A[i]);
    printf("\n");

}


int main()
{
    int i, N;

    printf("Name : RAJAT JAIN\nREG. No. : 200913010\n");
    printf("***QUICK SORT IMPLEMENTATION ON A LIST OF N INTEGERS***\n");

    printf("Enter the size of the Array:\n");
    scanf("%d", &N);
    int *A = malloc(N*sizeof(*A));

    printf("\nEnter the elements of the Array:\n");
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    printf("The given array is: \n");
    for(i=0; i<N; i++) printf("%d \t ", A[i]);

    quick_sort(A, 0, N-1);

    printf("\n\nSorted Array using Quick sort:\n", N);
    print_array(A,N);

    return 0;
}
