#include <iostream>
#include <math.h>

using namespace std;

int length = 0;

void checkCardinality(char A[]);
bool ismember(char a, char A[]);
void printPowerSet(char *set, int set_size);

int main()
{

    char A[50], find;
    int choice = 0;

    cout << "Enter the number of element in the SET : ";
    cin >> length;

    cout << "Enter the element(s). \n";

    for (int i = 0; i < length; i++)
    {
        cin >> A[i];
    }

    checkCardinality(A);

input:
    cout << "Select which operation you want to perform. \n"
         << "\t"
         << "1. Check Cardinality of SET. \n"
         << "\t"
         << "2. Check if element is the Member of SET. \n"
         << "\t"
         << "3. Print all the power set of given SET. \n"
         << "\t"
         << "4. Quit the program. \n";

    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Cardinality of Set is : " << length << "\n";
        goto input;
        break;

    case 2:

        cout << "Enter the element you want to search : ";
        cin >> find;
        if (ismember(find, A))
        {
            cout << "Element " << find << " is present in the given set. \n";
        }
        else
            cout << "Element " << find << " is not present in the given set. \n";

        goto input;

        break;

    case 3:
        printPowerSet(A , length);
        break;

    case 4:
        exit(0);
        break;

    default:
        exit(0);
        break;
    }

    return 0;
}

bool ismember(char a, char A[])
{
    int i = 0;
    do
    {
        if (A[i] == a)
        {
            return true;
        }
        else
            i++;

    } while (A[i] != '\0');

    return false;
}

void checkCardinality(char A[])
{
    int i, j, l;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length;)
        {
            if (A[i] == A[j])
            {
                for (l = j; l < length - 1; l++)
                    A[l] = A[l + 1];
                --length;
            }
            else
                ++j;
        }
    }
}

void printPowerSet(char *set, int set_size)
{
    int pow_set_size = pow(2, set_size);
    int counter, j;
 
    for(counter = 0; counter < pow_set_size; counter++)
    {
    for(j = 0; j < set_size; j++)
    {   
        if(counter & (1 << j))
            cout <<set[j];
    }
    cout << endl;
    }
}
