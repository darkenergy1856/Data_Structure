// Given an adjacency matrix of a graph,
// write a program to check whether a given set of vertices {v1,v2,v3.....,vk} forms an Euler path / Euler Circuit (for circuit assume vk=v1).

#include <iostream>

using namespace std;

int matrix[][50] = {{2, 4, 6, 2},
                    {2, 2, 10, 4},
                    {2, 6, 8, 2 },
                    {8, 2, 6, 10}};

int row = sizeof(matrix) / sizeof(matrix[0]);
int oddElement = 0;
int evenElement = 0;

void countAll()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row ; j++)
        {
            if (matrix[i][j] > 0)
            {
                if (matrix[i][j] % 2 == 0 )
                {
                    evenElement ++ ;
                }
                else
                    oddElement ++ ;
            }
            
        }
        
    }
    
}


int main()
{   

    countAll();

    if (evenElement == (row*row))
    {
       cout << "It is a Euler Circuit.";
    }
    else{
        if (oddElement == 2)
        {
            if(oddElement+evenElement == (row*row))
            {
                cout <<"It is a Euler Path . ";
            }
        }
        else{
            cout << "It is neither a Euler Circuit nor Euler Path. ";
        }
        
    }
    
}