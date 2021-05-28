#include <iostream>

using namespace std;

int checkCardinality(char A[]);
bool ismember(char a, char A[]);
void printPowerSet(char[]);

int main()
{

    char A[100], find;
    int choice;
    int count = checkCardinality(A);

input:

    cout << "Select which operation you want to perform. \n"
         << "\t"
         << "1. Check Cardinality of Set. \n"
         << "\t"
         << "2. Check if element is the Member of Set. \n"
         << "\t"
         << "3. Print all the power set of given SET. \n"
         << "\t"
         << "4. Quit the program. \n";

    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Cardinality of Set is : " << count;
        goto input;
        break;

    case 2:

        cout << "Enter the element you want to search : ";
        cin >> find;
        if (ismember(find, A))
        {
            cout << "Element " << find << " is present in the given set.";
        }
        else
            cout << "Element " << find << " is not present in the given set.";

        break;

    case 3:

        printPowerSet(A);

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

int checkCardinality(char A[])
{

    int count = 0;
    int i = 0;
    bool input = true;

    cout << "Enter The Elements in set. \n";
    while (input == true)
    {
        cin >> A[i];
        i++;
        if (A[i] == '\0')
        {

            input = false;
        }
    }

    return count;
}

void printPowerSet(char[])
{
}