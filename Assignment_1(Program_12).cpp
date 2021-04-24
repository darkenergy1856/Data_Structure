// Write a Program to represent Graphs using the Adjacency Matrices and check if it is a
// complete graph.

#include <iostream>

using namespace std;

int vertices = 0;

void addEdge(int a, int b, int matrix[][50]);

int main()
{
    int choice = 0;

input:
    cout << "Enter the no. of Vertices you want to have : \n";
    cin >> vertices;

    if (vertices <= 0)
    {
        int choice = 0;
        cout << " !! Adjacency Matrix not possible . Try again. !! \n";
        cout << "Want to continue with program press '1' . Else press any other key \n";
        cin >> choice;

        if (choice == 1)
        {
            goto input;
        }
        else
            exit(0);
    }

    int matrix[50][50], a, b;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }

addedge:
    cout << "Input the edges \n";
    cin >> a >> b;
    a = a - 1;
    b = b - 1;
    if (a >= 0 && a < vertices && b >= 0 && b < vertices)
    {
        addEdge(a, b, matrix);
        cout << "Want to add More : (Press 1.) \n";
        choice = 0;
        cin >> choice;

        if (choice == 1)
        {
            goto addedge;
        }
        else
            goto print;
    }
    else
    {
        cout << "!! Out of range . Try again .(Press 1) !!\n";
        choice = 0;
        cin >> choice;

        if (choice == 1)
        {
            goto addedge;
        }
        else
            goto print;
    }

print:

    cout << "Adjacency Matrices produced is : \n \n \n \n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}

void addEdge(int a, int b, int matrix[][50])
{
    matrix[a][b] += 1;
    matrix[b][a] += 1;
}
