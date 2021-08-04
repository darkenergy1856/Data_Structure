/* Write a Program to implement Bubble Sort. Find the number of comparisons during each pass and display the intermediate result.
   Use the observed values to plot a graph to analyse the complexity of algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j , count = 0;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            count ++ ;
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
        cout << "No. of Comparison in " << i+1 << " pass = " << count <<"\n";
        count = 0;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int length, arr[100];

    cout << "Enter the length of array : ";
    cin >> length;

    cout << "Provide elements for array.\n";

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, length);
    cout << "Sorted array: \n";
    printArray(arr, length);
    return 0;
}
