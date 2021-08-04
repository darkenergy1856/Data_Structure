/*Write a Program to accept the truth values of variables x and y, and print the truth table
of the following logical operations:
a) Conjunction     f) Exclusive NOR
b) Disjunction     g) Negation
c) Exclusive OR    h) NAND
d) Conditional     i) NOR
e) Bi-conditional
*/

#include <iostream>

using namespace std;

int main()
{
    int x = 0, y = 0;
    bool temp[10];
    string result[10];

    cout << "Provide true value for 'x': ";
    cin >> x;

    cout << "Provide true value for 'y': ";
    cin >> y;

    temp[0] = x * y;
    temp[1] = x + y;
    if (temp[1] == 2)
    {
        temp[1] = 1;
    }

    if (x != y)
    {
        temp[2] = 1;
        temp[4] = 0;
        temp[5] = 0;
    }
    else
    {
        temp[2] = 0;
        temp[4] = 1;
        temp[5] = 1;
    }

    if (x == 0)
    {
        temp[6] = 1;
    }
    else
    {
        temp[6] = 0;
    }

    if (y == 0)
    {
        temp[9] = 1;
    }
    else
    {
        temp[9] = 0;
    }

    if (x == 1)
    {
        if (y == 0)
        {
            temp[3] = 0;
        }
    }
    else
    {
        temp[3] = 1;
    }

    if (x == 1 && y == 1)
    {
        temp[7] = 0;
    }
    else
    {
        temp[7] = 1;
    }

    if (x == 0 && y == 0)
    {
        temp[7] = 1;
    }
    else
    {
        temp[7] = 0;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (temp[i] == 0)
        {
            result[i] = "False";
        }

        else
            result[i] = "True";
    }

    cout << "\n\n";

    cout << "Truth Table generated : \n\n"
         << "Conjuction : " << result[0]
         << "\nDisjunction : " << result[1]
         << "\nExclusive OR : " << result[2]
         << "\nConditional : " << result[3]
         << "\nBi-Conditional : " << result[4]
         << "\nExclusive NOR : " << result[5]
         << "\nNegation(x) : " << result[6]
         << "\nNAND : " << result[7]
         << "\nNOR : " << result[8]
         << "\nNegation(y) : " << result[9];

    return 0;
}