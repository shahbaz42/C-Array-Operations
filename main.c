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

void scanA(int arr[])
{
    for (int i = 0; i < sizeArr; i++)                          // taking input in the array
    {
        printf("Enter Element for position %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void printA(int arr[])
{
    printf("[ %d", arr[0]);
    for (int i = 1; i < sizeArr; i++)                          
    {
        printf(", %d", arr[i]);
    }
    printf(" ] \n");
}

void insert(int arr[], int x){
    A = (int*)realloc(A, ++sizeArr*sizeof(int) );
    A[sizeArr - 1 ] = x;
}

void delete(int arr[]){
    A = (int*)realloc(A, --sizeArr*sizeof(int) );
}

int main(int argc, char *argv[])                            // Driver code
{   
    int n;
    createArr();
    scanA(A);
    printA(A);
    insert(A, 42);
    printA(A);
    delete(A);
    printA(A);

    
}
