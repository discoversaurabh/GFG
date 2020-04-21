#if 1
/*
Rotate a matrix by 90 degree anticlockwise without using any extra space
THERE ARE TWO APPROACHES FOR SOLVING THIS PROBLEM

Approach 1:
Approach:The idea is to find the transpose of the matrix and then reverse the columns of the transposed matrix.

Algorithm:
To solve the given problem there are two tasks. 1st is finding the transpose and second is reversing the columns without using extra space
A transpose of a matrix is when the matrix is flipped over its diagonal, i.e the row index of an element becomes the column index and vice versa. So to find the transpose interchange the elements at position (i,j) with (j,i). Run two loops, the outer loop from 0 to row count and inner loop from 0 to index of the outer loop.
To reverse the column of the transposed matrix, run two nested loops, the outer loop from 0 to column count and inner loop from 0 to row count/2, interchange elements at (i,j) with (i, row count-1-j), where i and j are indices of inner and outer loop respectively.

*******************************************

Approach2: 
To solve the question without any extra space, rotate the array in form of squares, dividing the matrix into squares or cycles. For example,
A 4 X 4 matrix will have 2 cycles. The first cycle is formed by its 1st row, last column, last row and 1st column. The second cycle is formed by 2nd row, second-last column, second-last row and 2nd column. The idea is for each square cycle, swap the elements involved with the corresponding cell in the matrix in anti-clockwise direction i.e. from top to left, left to bottom, bottom to right and from right to top one at a time using nothing but a temporary variable to achieve this.

Demonstration:

First Cycle (Involves Red Elements)
 1  2  3 4
 5  6  7 8
 9 10 11 12
 13 14 15 16

Moving first group of four elements (First
elements of 1st row, last row, 1st column
and last column) of first cycle in counter
clockwise.
 4  2  3 16
 5  6  7 8
 9 10 11 12
 1 14  15 13

Moving next group of four elements of
first cycle in counter clockwise
 4  8  3 16
 5  6  7  15
 2  10 11 12
 1  14  9 13

Moving final group of four elements of
first cycle in counter clockwise
 4  8 12 16
 3  6  7 15
 2 10 11 14
 1  5  9 13
 
Second Cycle (Involves Blue Elements)
 4  8 12 16
 3  6 7  15
 2  10 11 14
 1  5  9 13

Fixing second cycle
 4  8 12 16
 3  7 11 15
 2  6 10 14
 1  5  9 13
Algorithm:

There is N/2 squares or cycles in a matrix of side N. Process a square one at a time. Run a loop to traverse the matrix a cycle at a time, i.e loop from 0 to N/2 – 1, loop counter is i
Consider elements in group of 4 in current square, rotate the 4 elements at a time. So the number of such groups in a cycle is N – 2*i.
So run a loop in each cycle from x to N – x – 1, loop counter is y
The elements in the current group is (x, y), (y, N-1-x), (N-1-x, N-1-y), (N-1-y, x), now rotate the these 4 elements, i.e (x, y) <- (y, N-1-x), (y, N-1-x)<- (N-1-x, N-1-y), (N-1-x, N-1-y)<- (N-1-y, x), (N-1-y, x)<- (x, y)
Print the matrix.
*/

//APPROACH 1 is used here: SAURABH
// C++ program for left rotation of matrix by 90 degree w/o using extra space 
#include"AllHeader.h"
#define R 4 
#define C 4 

// After transpose we swap elements of column 
// one by one for finding left rotation of matrix 
// by 90 degree 
void myswap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void reverseColumns(int arr[R][C])
{
	for (int i = 0; i < C; i++)
		for (int j = 0, k = C - 1; j < k; j++, k--)
			myswap(arr[j][i], arr[k][i]);
}

// Function for do transpose of matrix 
void transpose(int arr[R][C])
{
	for (int i = 0; i < R; i++)
		for (int j = i; j < C; j++)
			myswap(arr[i][j], arr[j][i]);
}

// Function for print matrix 
void printMatrix(int arr[R][C])
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}

// Function to anticlockwise rotate matrix 
// by 90 degree 
void rotate90(int arr[R][C])
{
	transpose(arr);
	reverseColumns(arr);
}

// Driven code 
int main()
{
	int arr[R][C] = { { 1, 2, 3, 4 },
					  { 5, 6, 7, 8 },
					  { 9, 10, 11, 12 },
					  { 13, 14, 15, 16 } };
	rotate90(arr);
	printMatrix(arr);
	return 0;
}
#endif


#if 0
//APPROACH 2 - SAURABH - STUCK SOMEWHERE 
#include"AllHeader.h"
class solution
{
	public:
		int rowSize, colSize;
		//int newRowSize, newColSize;	//required because if matrix is npt NXN then we need to reside dimensions
		//gave another thought for above but we cannot do that without taking extra space
	void printMat(vector<vector<int>> &mat)
	{

		for (int i = 0; i < rowSize; ++i)
		{
			for (int j = 0; j < colSize; ++j)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}

	void rotate90AntiClock(vector<vector<int>> &mat)
	{
		int tmp = 0;
		for (int r = 0; r < rowSize / 2; ++r)	//as only N/2 rotations will be there 
		{
			for (int i = r; i < rowSize - r - 1; i++)
			{
				//SAURABH - FOR THIS SHIFTING THINK IN TERMS OF WHICH INDEX WILL VARY AT EVERY ITERATION AND WHICH INDEX WILL VARY AFTER INTERNAL LOOP
				tmp = mat[r][r];
				mat[r][i] = mat[i][rowSize-r-1]; // shift right to top
				mat[i][rowSize - r-1] = mat[rowSize - r-1][rowSize-i-1];	//shift bottom to right
				mat[rowSize - r-1][rowSize-i-1] = mat[rowSize-i-1][r];	//shift from left to bottom
				// mat[rowSize-i-1][r] = mat[r][i];	//shift from top to left
				mat[rowSize-i-1][r] = tmp;	//shift from top to left
			}
			//mat[r][rowSize - r-1] = tmp;
		}
	}
};

int main()
{
	//vector<vector<int>> matrix = {
	//				{1,2,3},
	//				{4,5,6},
	//				{7,8,9}
	//				};
	vector<vector<int>> matrix = {
					{1,2,3,4},
					{5,6,7,8},
					{9,10,11,12},
					{13,14,15,16}
	};

	solution s;
	s.rowSize = matrix.size();
	if (s.rowSize)
		s.colSize = matrix[0].size();
	cout << "BEFORE :" << endl;
	s.printMat(matrix);
	s.rotate90AntiClock(matrix);
	cout << "AFTER :" << endl;
	s.printMat(matrix);
	return 0;
}
#endif