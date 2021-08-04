/*
  Write a Program to implement Insertion Sort. Find the number of comparisons during each pass and display the intermediate result.
   Use the observed values to plot a graph to analyse the complexity of algorithm. 
*/

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, temp, j , count = 0;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            count ++;
        }
        arr[j + 1] = temp;
        cout << "Comparison in " << i << " : " << count << "\n";
        count = 0; 
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
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

    insertionSort(arr, length);

    cout << "Sorted Array is : \n";

    printArray(arr, length);

    return 0;
}