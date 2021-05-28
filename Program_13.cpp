// Write a Program to accept a directed graph G and compute the in-degree and out-degree of each vertex.

#include <iostream>

using namespace std;

void outDegree(int data[][3], int a);
void inDegree(int data[][3], int a);

int vertices = 0;

int main()
{
    int choice = 0;

input:
    cout << "Enter the no. of Vertices you want to have : \n";
    cin >> vertices;

    if (vertices <= 0)
    {
        int choice = 0;
        cout << " !! Operation not possible . Try again. !! \n";
        cout << "Want to continue with program press '1' . Else press any other key \n";
        cin >> choice;

        if (choice == 1)
        {
            goto input;
        }
        else
            exit(0);
    }

    int data[50][3], a, b;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            data[i][j] = 0;
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        data[i][0] = i + 1;
    }

edge:

    cout << "Enter The Edge. (a ->- b) \n";
    cin >> a >> b;
    a--;
    b--;
    if (a >= 0 && a < vertices && b >= 0 && b < vertices)
    {
        inDegree(data, b);
        outDegree(data, a);
    }
    else
    {
        cout << "!! Operation not possible . Try again. !! \n";
    }

    cout << "Want to add more edge. If yes Press 1 . \n";
    choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        goto edge;
    }
    else
    {
        goto printdata;
    }

printdata:

    cout << "Vertices "
         << "\t"
         << "In Degree"
         << "\t"
         << "Out Degree"
         << "\n\n";

    for (int i = 0; i < vertices; i++)
    {

        cout << "    " << data[i][0] << "                " << data[i][1] << "                " << data[i][2] << "\n";
    }

    return 0;
}

void inDegree(int data[][3], int a)
{
    data[a][1]++;
}

void outDegree(int data[][3], int a)
{
    data[a][2]++;
}
