#include <iostream>

using namespace std;

class SET
{
private:
    char primary[50], secondary[50];
    int primary_length, secondary_length, choice = 0;

    void subset()
    {
        int count = 0;
        cout << "Do you want to check B for subset of A . If yes press '1' or '2' for vice-versa: ";
        cin >> count;

        if (count == 1)
        {
            count = 0;
            for (int i = 0; i < secondary_length; i++)
            {
                if (ismember(secondary[i], primary))
                {
                    count++;
                }
            }

            if (count == secondary_length)
                cout << "Set B is a Subset of A";
            else
                cout << "Set B is not a Subset of A";
        }

        if (count == 2)
        {
            count = 0;

            for (int i = 0; i < primary_length; i++)
            {
                if (ismember(primary[i], secondary))
                {
                    count++;
                }
            }

            if (count == primary_length)
                cout << "Set A is a Subset of B";
            else
                cout << "Set A is not a Subset of B";
        }
    }

    void Union_Intersection()
    {
        char temp[100];
        int length = primary_length + secondary_length;

        for (int i = 0; i < primary_length; i++)
        {
            temp[i] = primary[i];
        }

        for (int i = primary_length, j = 0; i < length; i++, j++)
        {
            temp[i] = secondary[j];
        }

        cout << "Union of the Set is : \n";
        length = checkCardinality(temp, length);

        cout << "{";
        for (int i = 0; i < length; i++)
        {
            cout << temp[i] << ",";
        }
        cout << "} \n";

        cout << "Intersection of set is : \n"
             << "{";
        for (int i = 0; i < secondary_length; i++)
        {
            if (ismember(secondary[i], primary))
            {
                cout << secondary[i] << ",";
            }
        }
        cout << "}";
    }

    void complement()
    {
        cout << "Complement of set is : \n";

        if (primary_length > secondary_length)
        {   
            cout << "{";
            for (int i = 0; i < primary_length; i++)
            {
                if(!ismember(primary[i], secondary))
                    cout << primary[i]<<",";
            }
            cout << "}";
            
        }
        else 
        {
            cout << "{";
            for (int i = 0; i < secondary_length; i++)
            {
                if(!ismember(secondary[i], primary))
                    cout << secondary[i]<<",";
            }
            cout << "}"; 
        }

    }

    void setDifference()
    {
        cout << "Set DIfference A -> B . \n";
        cout <<"{";
        for (int i = 0; i < primary_length; i++)
        {
            if (!ismember(primary[i] , secondary))
            {
                cout << primary[i] << ",";
            }
            
        }
        cout << "}\n";

        cout << "Set DIfference B -> A . \n";
        cout <<"{";
        for (int i = 0; i < secondary_length; i++)
        {
            if (!ismember(secondary[i] , primary))
            {
                cout << secondary[i] << ",";
            }
            
        }
        cout << "}\n";


        cout << "Symmetric difference between SET . \n";

        cout <<"{";
        for (int i = 0; i < primary_length; i++)
        {
            if (!ismember(primary[i] , secondary))
            {
                cout << primary[i] << ",";
            }
            
        }
         for (int i = 0; i < secondary_length; i++)
        {
            if (!ismember(secondary[i] , primary))
            {
                cout << secondary[i] << ",";
            }
            
        }
        cout << "}\n"; 
    }

    void cartesianProduct()
    {
        cout << "{";
        for (int i = 0; i < primary_length; i++)
        {
            for (int j = 0; j < secondary_length; j++)
            {
                cout << "(" << primary[i] << "," << secondary[j] << ")"
                     << " , ";
            }
        }
        cout << "}";
    }

    int checkCardinality(char A[], int length)
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
        return length;
    }

    bool ismember(char ar, char A[])
    {
        int i = 0;
        do
        {
            if (A[i] == ar)
            {
                return true;
            }
            else
                i++;

        } while (A[i] != '\0');

        return false;
    }

    void input()
    {

        cout << "Enter the length of First Set.\n";
        cin >> primary_length;
        cout << "Enter the Element of SET 1.\n";

        for (int i = 0; i < primary_length; i++)
        {
            cin >> primary[i];
        }
        cout << "Enter thr length of Second Set.\n";
        cin >> secondary_length;

        cout << "Enter the Element of SET 2.\n";

        for (int i = 0; i < secondary_length; i++)
        {
            cin >> secondary[i];
        }

        primary_length = checkCardinality(primary, primary_length);
        secondary_length = checkCardinality(secondary, secondary_length);

    inputChoice:

        cout << "(1) Check for the subset.\n"
             << "(2) List Union and Intersection of provided SETS.\n"
             << "(3) Complement of the SET.\n"
             << "(4) Set Difference and Symmetric Difference between two SETS.\n"
             << "(5) Cartesian Product of two SETS.\n"
             << "(6) Exit.\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            subset();
            break;

        case 2:
            Union_Intersection();
            break;

        case 3:
            complement();
            break;

        case 4:
            setDifference();
            break;

        case 5:
            cartesianProduct();
            break;

        case 6:
            exit(0);

        default:
            cout << "Try again !!.";
            goto inputChoice;
            break;
        }
    }

public:
    void start()
    {
        input();
    }
};

int main()
{
    SET input;
    input.start();

    return 0;
}
