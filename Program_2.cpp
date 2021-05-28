#include <iostream>

using namespace std;

class SET
{
private:
    int primary[50], primary_length, secondary[50], secondary_length;

    void subset()
    {
    }

    void Union_Intersection()
    {
    }

    void complement()
    {
    }

    void setDifference()
    {
    }

    void cartesianProduct()
    {
    }

    void input()
    {
        int primary[50], primary_length, secondary[50], secondary_length, choice = 0;
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
