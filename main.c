#include <stdio.h>
#include <stdlib.h>

int *A;      // created a pointer for storing adress of our array
int sizeArr; // size of array to be used for malloc

void createArr() // creating array of size sizeArr
{
    printf("Enter the size of your array : "); // prompt
    scanf("%d", &sizeArr);

    A = (int *)malloc(sizeArr * sizeof(int)); // Memory allocation for array

    if (A == NULL) // for checking if an memory was sucessfully allocated
        printf("Unable to create array.\n");

    else
        printf("Sucessfully created array.\n");
}

void scanA(int arr[], int sizeArr) // Function for taking input in our array
{
    for (int i = 0; i < sizeArr; i++) // taking input in the array
    {
        printf("Enter Element for position %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void printA(int arr[], int sizeArr) // function for printing an array
{
    printf("[ %d", arr[0]);
    for (int i = 1; i < sizeArr; i++)
    {
        printf(", %d", arr[i]);
    }
    printf(" ] \n");
}

void insert(int arr[], int x)
{ // function for inserting an element to the last of the array.
    A = (int *)realloc(A, ++sizeArr * sizeof(int));
    A[sizeArr - 1] = x;
}

void delete (int arr[])
{ // function for deleting the last element of an array
    A = (int *)realloc(A, --sizeArr * sizeof(int));
}

void linearSearch(int arr[], int sizeArr, int x)
{ // linear searches and prints index number is found
    int found = 0;
    for (int i = 0; i < sizeArr; i++)
    {
        if (arr[i] == x)
        {
            printf("Found at position %d.\n", i);
            found = 1;
        }
    }
    if (found == 0)
        printf("Not Found.\n");
}

int binarySearch(int arr[], int sizeArr, int x, int lBound, int uBound)
{ // for searching from a sorted array
    // ["1 2 3 4 5" 6 7 8 9 10]   size = 10 uBound = 9   x= 3
    if (uBound >= lBound)
    {
        int mid = lBound + (uBound - lBound) / 2;
        if (arr[mid] == x)
        {
            printf("Found at position : %d. \n", mid);
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, sizeArr, x, lBound, mid - 1);
        }
        else
        {
            return binarySearch(arr, sizeArr, x, mid + 1, uBound);
        }
    }
    printf("Not Found ! \n");
    return -1;
}

void insertionSort(int arr[], int sizeArr)
{
    // [1,8,5,3,1,2]
    //  0,1,2,3,4,5
    for (int i = 1; i < sizeArr; i++)
    {
        int key = arr[i]; //3                              // key = arr[i] is being moved
        int j = i - 1;    //2                              // j is the place for checking if key can be moved to j or not.

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // shifts element at j to j+1 position and decrements j
            j--;                 //
        }
        arr[j + 1] = key; // if key is greater than jth element then j+1 th element becomes key
    }
}

void selectionSort(int arr[], int sizeArr)
{
    //[1,5,3,6,4]
    for (int j = 0; j < sizeArr; j++) // j is the selector at which min of arr[j ... sizeArr] will be placed
    {                                 // [ ... sorted array ... j ... unsorted array...]
        int min = arr[j];
        int min_index = j;
        for (int i = j; i < sizeArr; i++) // This loop finds min of unsorted array
        {
            if (arr[i] < min)
            {
                min = arr[i];
                min_index = i;
            }
        }
        int temp = arr[j]; //when min is found it is placed at the end of sorted array.
        arr[j] = arr[min_index];
        arr[min_index] = temp;
    }
}

void bubbleSort(int arr[], int sizeArr)
{
    int i, j;
    for (i = 0; i < sizeArr - 1; i++)

        for (j = 0; j < sizeArr - i - 1; j++) // Last i elements are already in place
            if (arr[j] > arr[j + 1])
            { // if current element is greater than next element then swaps both elements.
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
}

void merge(int arr1[], int size1, int arr2[], int size2)
{ //merges arr2 into arr1
    A = (int *)realloc(A, (size1 + size2) * sizeof(int));     // increases size to accomodate arr2
    sizeArr = size1 + size2 ;
    for (int i = 0; i < size2; i++)
    {
        arr1[size1 + i] = arr2[i];
    }
}

void mergeArrays()                                           
{   
    int size2;
    printf("Arr1 is : ");
    printA(A, sizeArr);
    printf("Enter the size of Arr2 : ");
    scanf("%d", &size2);
    int Arr2[size2];
    scanA(Arr2, size2);
    printf("Arr2 is : ");
    printA(Arr2, size2);
    printf("After merging : ");
    merge(A, sizeArr, Arr2, size2);
    printA(A, sizeArr );
    printf("sorted merged Array: ");
    bubbleSort(A, sizeArr);
    printA(A, sizeArr );
}

int main(int argc, char *argv[])                                 // driver code
{
    int n, x;

    createArr();
    scanA(A, sizeArr);
    printf("arr : ");
    printA(A, sizeArr);

    while (1 == 1)
    {
        printf("______________________________________\n");
        printf("1. Insertion \n");
        printf("2. Deletion \n");
        printf("3. Searching \n");
        printf("4. Sorting \n");
        printf("5. Traversal \n");
        printf("6. Merging two sorted arrays \n");
        printf("______________________________________\n");
        printf("What do you want to do : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("_____Insertion_____ \n");
            printf("What do you want to insert : ");
            scanf("%d", &x);
            insert(A, x);
            printf("Array after inserting : ");
            printA(A, sizeArr);
            break;

        case 2:
            printf("_____Deletion_____ \n");
            delete (A);
            printf("Array after deletion : ");
            printA(A, sizeArr);
            break;

        case 3:
            printf("_____Searching_____ \n");
            printf("What do you want to search : ");
            scanf("%d", &x);

            printf("Enter 1 for linear search, 2 for binary search :");
            scanf("%d", &n);
            (n == 1) ? linearSearch(A, sizeArr, x) : binarySearch(A, sizeArr, x, 0, sizeArr); //using terniary operators for if else
            printf("in Array : ");
            printA(A, sizeArr);
            break;

        case 4:
            printf("_____Sorting_____ \n");
            printf("How do you want to sort?\n ");
            printf("Enter 1 for Insertion sort, 2 for Selection Sort \nand 3 for Bubble Sort : ");
            scanf("%d", &x);
            if (x == 1)
                insertionSort(A, sizeArr);
            if (x == 2)
                selectionSort(A, sizeArr);
            if (x == 3)
                bubbleSort(A, sizeArr);

            printf("Array after sorting : ");
            printA(A, sizeArr);
            break;

        case 5:
            printf("_____Traversal_____ \n");
            printf("Printing array after traversal : ");
            printA(A, sizeArr);
            break;

        case 6:
            mergeArrays();

            break;

        default:
            printf("Wrong choice");
            break;
        }
        printf("\n Press 1 to continue...");
        scanf("%d", &x);
    }
}
