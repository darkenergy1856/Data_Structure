#include <iostream>

using namespace std;

int main()
{
    int m = 0 , i = 0;

    cout << "Enter the Value of 'm' : ";
    cin >> m;

    cout << "Enter the value of Internal vertices 'i' : ";
    cin >> i;

    cout << "Total no. of Leaf Nodes = " << ((m-1)*i + 1);
    
    return 0;
}