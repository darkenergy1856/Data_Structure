// Write a Program to calculate Permutation and Combination for an input value n and r
// using recursive formula of nCr and nPr .

#include <iostream>
#include <conio.h>

using namespace std;


int factorial(int term)
{   
    if (term >=1)
    {
       return term*factorial(term-1);
    }else
    {
        return 1;
    }
}

double combination(int n, int r)
{
    int numerator = factorial(n);
    int denominator1 = factorial(n-r);
    int denominator2 = factorial(r);

    double finalValue = numerator/(denominator1*denominator2);

    return finalValue;
}

double permutation(int n, int r)
{
    int numerator = factorial(n);
    int denominator1 = factorial(n-r);

    double finalValue = numerator/denominator1;

    return finalValue;


}

int main()
{

    int n, r;

    cout << "Enter the value of 'n' : ";
    cin >> n;

    cout << "Enter the value of 'r' : ";
    cin >> r;

    if (n < 0 || r < 0)
    {
       cout << "Invalid value for the operation !!!";
       exit(0);
    }
    

    if (r > n)
    {
        cout << "Invalid value for the operation !!!";
        exit(0);
    }

    cout << "Result of combintion is : " << combination(n, r) << "\n";
    cout << "Result of permutation is : " << permutation(n, r);

    getch();


    return 0;
}