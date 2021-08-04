/*Write a Program to generate all the permutation of a given set of 
 digits , with or without repitition.(For Example , if given set is {1,2},
 the permutation are 12 and 21). (One methode is given in Liu).      
*/

#include <iostream>
#include <conio.h>

using namespace std;

void permrep(int A[], int B[], int b, int n)
{
    if (b == n)
    {
        for (int i = 0; i < b; i++)
        {
            cout << B[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            B[b] = A[i];
            permrep(A, B, b + 1, n);
        }
    }
}

void unique(int set[10], int &size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;)
        {
            if (set[i] == set[j])
            {
                for (int l = j; l < size - 1; l++)
                    set[l] = set[l + 1];
                --size;
            }
            else
                ++j;
        }
    }
}

void permutation(int array[], int start, int end)
{
    int temp;

    if (start == end)
    {

        for (int i = 0; i <= end; i++)
        {
            cout << array[i];
        }
        cout << "\n";
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            temp = array[start];
            array[start] = array[i];
            array[i] = temp;

            permutation(array, start + 1, end);

            temp = array[start];
            array[start] = array[i];
            array[i] = temp;
        }
    }
}

int main()
{
    int set[100] , tempSet[100];
    int size;

    cout << "Enter no. of Element you want to have in SET. : ";
    cin >> size;

    if (size <= 0 || size >= 10)
    {
        cout << "Enter number bigger than 0 and less than 10 ";
    }

    cout << "Enter the element .\n";
    for (int i = 0; i < size; i++)
    {
        cin >> set[i];
    }

    unique(set, size);

    int choice = 0;

    cout << "Choose the methode . \n"
         << "(1) Repetation allowed .\n"
         << "(2) Repetation not allowed .\n";

    cin >> choice;

    int tempSize = size;

    if (choice == 1)
    {
        permrep(set , tempSet , 0 , size);
    }
    else{

    if (choice == 2)
        permutation(set, 0, size - 1);
    else
        exit(0);
    }
    return 0;
}
