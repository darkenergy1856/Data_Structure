// Create a class RELATION, use Matrix notation to represent a relation. Include functions
// to check if the relation is Reflexive, Symmetric, Anti-symmetric and Transitive. Write a
// Program to use this class

#include <iostream>

using namespace std;

class RELATION
{

   int matrix[50][50], choice = 0, row ,a, b;
   int transpose[50][50];

bool checkTransitive()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<row;j++)
        {
            if(matrix[i][j]==1)
            {
                for(int k=0;k<row;k++)
                {
                    if((matrix[j][k]==1)&&(matrix[i][k]!=1))
                    return false;
                }
            }
        }
    }
    return true;
}

   bool checkAnti_symmetric()
   {
      for (int i = 0; i < row; i++)
         for (int j = 0; j < row; j++)
            if (matrix[i][j] != -transpose[i][j])
               return false;
      return true;
   }

   bool checkSymmetric()
   {
      int i, j;
      for (i = 0; i < row; i++)
         for (j = 0; j < row; j++)
            transpose[i][j] = matrix[j][i];

      for (i = 0; i < row; i++)
         for (j = 0; j < row; j++)
            if (matrix[i][j] != transpose[i][j])
               return false;

      return true;
   }
   void printMatrix()
   {
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < row; j++)
         {
            cout << matrix[i][j] << "\t";
         }
         cout << "\n";
      }
   }

   void assignValue(int a, int b)
   {
      matrix[a][b] = 1;
   }

   bool checkReflexive()
   {
      for (int i = 0; i < row; i++)
      {
         if (matrix[i][i] != 1)
         {
            return false;
         }
      }

      return true;
   }

public:
   void inputall()
   {

      cout << "Enter the dimension. \n";
      cin >> row;
      
      for (int i = 0; i < row; i++)
      {
         for (int j = 0; j < row; j++)
         {
            matrix[i][j] = 0;
         }
      }
   input:
      cout << "Enter the relation form element of first set to element of second set : (1 -> 2)\n";
      cin >> a;
      cin >> b;

      a -= 1;
      b -= 1;

      if (a >= 0 && a < row && b >= 0 && b < row)
      {
         assignValue(a, b);
         cout << "Want to add more relation . Press 1 : ";
         cin >> choice;
         if (choice == 1)
         {
            goto input;
         }
      }
      else
      {
         cout << "Invalid Input."
              << "Want to add more if 'yes' Press 1 . else program will continue. :";
         cin >> choice;
         if (choice == 1)
         {
            goto input;
         }
      }

      printMatrix();

      if (checkReflexive())
         cout << "Give relation is Reflexive.\n";
      else
         cout << "Given relation is not Reflexive.\n";

      if (checkSymmetric())
         cout << "Give relation is Symmetric.\n";
      else
         cout << "Given relation is not Symmetric.\n";

      if (checkAnti_symmetric())
         cout << "Give relation is Anti_Symmetric.\n";
      else
         cout << "Given relation is not Anti_Symmetric.\n";

      if (checkTransitive())
         cout << "Give relation is transitive.\n";
      else
         cout << "Given relation is not transitive\n";
   }
};

int main()
{
   RELATION relation;
   relation.inputall();
   return 0;
}