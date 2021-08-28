# include <stdio.h>

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
    int size;
    printf("Enter the size of an array : ");                // prompt
    scanf("%d", &size);

    int arr[size];                                          // creating array of required size
    
    scanA(arr, size);
    printf("Enter elements of your array__ \n");
    

    printA(arr, size);

}
