//  Given a graph G, write a Program to find the number of paths of length n between the source and destination entered by the user.

#include <iostream>

using namespace std;

int rows, col, vertices = 0;
int mulMatrix[50][50];

void addEdge(int a, int b, int matrix[][50]);

void intialize()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            mulMatrix[i][j] = 0;
        }
    }
}

void Display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << mulMatrix[i][j] << "\t";
        }

        cout << "\n";
    }
}

void multiply(int mat1[][50], int mat2[][50])
{

    int temp[50][50];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < rows; k++)
                temp[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            mulMatrix[i][j] = temp[i][j];
        }
    }
}

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
        
    }

    int length;

    rows = vertices;

    cout << "Enter the length of the of Path: ";
    cin >> length;


    intialize();

    multiply(matrix, matrix);
    for (int i = 0; i < length - 2; i++)
    {
        multiply(mulMatrix, matrix);
    }

    int source , destination;

    cout << "Enter Source vertex : ";
    cin >> source;

    cout << "Enter Destination Vertex : ";
    cin >> destination;

    cout << "No. of Path Between " << source << " and " << destination <<" Of length "<<length<< " unit is " << mulMatrix[source-1][destination-1] << "\n";
    Display();

    return 0;
}

void addEdge(int a, int b, int matrix[][50])
{
    matrix[a][b] += 1;
    matrix[b][a] += 1;
}
