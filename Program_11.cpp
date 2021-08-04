/*
Write a Program to store a function (polynomial/exponential), and then evaluate thepolynomial. (For example store f(x) = 4n3 + 2n + 9 in an array and for a given value of n, say
n = 5, evaluate (i.e. compute the value of f(5)). 
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{   
    int coefficient[10] , maxPower , n;
    long result = 0;
    
    cout << "Enter the highest power of your equation : ";
    cin >> maxPower;

    for(int i = maxPower ; i >= 0 ; i--)
    {
        cout << "Enter the Co-efficient of term n^"<<i << ": ";
        cin >> coefficient[i];
    }

    cout << "Provide the value of 'n' : ";
    cin >> n;

    for (int i = 0; i <= maxPower; i++)
    {
        result += pow(n , i) * coefficient[i];  
    }
    

    cout << "Result of equation : " ;

    for (int i = maxPower; i >= 0 ; i--)
    {   
        if (i != 0)
        {
        if(coefficient[i] != 0)
            cout << coefficient[i] <<"n^" << i << " + ";
        }else
            cout << coefficient[i] ;
    }

    cout <<" is " << result;
    

    return 0;
}

