# include <stdio.h>
# include <stdlib.h>

int *A ;
int sizeArr;

void createArr()
{
    printf("Enter the size of your array : ");                // prompt
    scanf("%d", &sizeArr);

    A = (int*) malloc(sizeArr*sizeof(int));

    if (A == NULL){
        printf("Unable to create array.\n");
    }
    else
        printf("Sucessfully created array.\n");
}

void scanA(int arr[], int size)
{
    for (int i = 0; i < size; i++)                          // taking input in the array
    {
        printf("Enter Element for position %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void printA(int arr[], int size)
{
    printf("[ %d", arr[0]);
    for (int i = 1; i < size; i++)                          
    {
        printf(", %d", arr[i]);
    }
    printf(" ] \n");
    arr[0] = 42;
}

int main(int argc, char *argv[])                            // Driver code
{   
    int n;
    createArr();
    scanA(A, sizeArr);
    printA(A, sizeArr);
    
}
