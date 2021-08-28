# include <stdio.h>
# include <stdlib.h>

int *A ;    // created a pointer for storing adress of our array
int sizeArr;    // size of array to be used for malloc

void createArr()             // creating array of size sizeArr
{
    printf("Enter the size of your array : ");                 // prompt
    scanf("%d", &sizeArr);

    A = (int*) malloc(sizeArr*sizeof(int));                   // Memory allocation for array

    if (A == NULL){                                           // for checking if an memory was sucessfully allocated
        printf("Unable to create array.\n");
    }
    else
        printf("Sucessfully created array.\n");
}

void scanA(int arr[])                                         // Function for taking input in our array
{
    for (int i = 0; i < sizeArr; i++)                         // taking input in the array
    {
        printf("Enter Element for position %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void printA(int arr[])                                        // function for printing an array
{
    printf("[ %d", arr[0]);
    for (int i = 1; i < sizeArr; i++)                          
    {
        printf(", %d", arr[i]);
    }
    printf(" ] \n");
}

void insert(int arr[], int x){                               // function for inserting an element to the last of the array.
    A = (int*)realloc(A, ++sizeArr*sizeof(int) );
    A[sizeArr - 1 ] = x;
}

void delete(int arr[]){                                      // function for deleting the last element of an array
    A = (int*)realloc(A, --sizeArr*sizeof(int) );
}

void linearSearch(int arr[], int x){                         // linear searches and prints index number is found
    int found = 0;
    for (int i = 0; i < sizeArr; i++)
    {
        if (arr[i]==x){
            printf("Found at position %d.\n", i);
            found = 1;
        } 
    }  
    if (found == 0)
        printf("Not Found.");
}

void insertionSort(int arr[]){
    // [1,8,5,3,1,2]
    //  0,1,2,3,4,5
    for (int i = 1; i < sizeArr; i++)
    {
        int key = arr[i]; //3                                // key = arr[i] is being moved
        int j = i-1;      //2                                // j is the place for checking if key can be moved to j or not. 

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];                                 // shifts element at j to j+1 position and decrements j
            j--;                                             // 
        }
        arr[j+1]=key;                                        // if key is greater than jth element then j+1 th element becomes key 
    }
    
}


int main(int argc, char *argv[])                            
{   
    int n;
    createArr();
    scanA(A);
    printA(A);
    insertionSort(A);
    printA(A);
}
