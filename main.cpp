#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_STR 128 //max string length
#define STAR '*' //star
/*
The program read the number of rows and columns,
create a matrix (vector of vectors of characters) to hold the stars
then prints out a corresponding matrix of stars (using the * character).
*/

int readInt(); //read an integer
void readString(char *str); //read a string
void createMatrix(int numRows, int numColumns, vector< vector<char> > &matrix);//create matrix of stas
void printMatrix(const vector< vector<char> > &matrix);//print matrix

int main(){

//matrix (vector of vectors of characters) to hold the stars
vector< vector<char> > matrix;

//number of rows
int numRows = 0;

//number of columns
int numColumns = 0;

while (numRows <= 0 || numColumns <= 0)
{
cout << "Enter rows and columns of stars:" << endl;
numRows = readInt();
numColumns = readInt();

if (numRows <= 0 || numColumns <= 0)
{
cout << "Invalid input. The rows and columns of stars must be positive numbers" << endl;
}
}//end while validating rows, columns

//create matrix
createMatrix(numRows, numColumns, matrix);

//print matrix of stars
printMatrix(matrix);

return 0;
}

/*
Function: printMatrix
Purpose: print matrix (vector of vectors of characters) to hold the stars
*/
void printMatrix(const vector< vector<char> > &matrix){

cout << endl;//print a new line

//for each row
for (unsigned int i = 0; i < matrix.size(); i++)
{
//print a row
for (unsigned int j = 0; j < matrix[i].size(); j++)
{
cout << matrix[i][j];
}
cout << endl;//print a new line
}
}

/*
Function: createMatrix
Purpose: create matrix (vector of vectors of characters) to hold the stars
Output: matrix
*/
void createMatrix(int numRows, int numColumns, vector< vector<char> > &matrix){
//for each row
for (int i = 0; i < numRows; i++)
{
vector<char> rows;
//add stars to rows
for (int i = 0; i < numColumns; i++)
{
rows.push_back(STAR);
}
matrix.push_back(rows);
}//end for creating matrix
}

/*
Function: readInt
Purpose: reads an integer from standard input
Return: integer read in from the user
*/
int readInt()
{
int number; //integer number

//a buffer that contains characters
char str[MAX_STR];

//read a string
readString(str);

//convert to int
sscanf(str, "%d", &number);

return number;
}

/*
Function: readString
Purpose: reads a string from standard input
Output: string read in from the user
*/
void readString(char *str)
{
char tmpStr[MAX_STR];

//read a line
fgets(tmpStr, sizeof(tmpStr), stdin);
tmpStr[strlen(tmpStr)-1] = '\0';

//copy to str
strcpy(str, tmpStr);
}


