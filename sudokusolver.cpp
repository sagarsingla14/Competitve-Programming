#include <iostream>
using namespace std;

bool koidikkattohnahi(int sudoku[][9],int row,int col,int num)
{
	for(int i = 0;i<9;i++)
	{
		if(sudoku[row][i] == num || sudoku[i][col] == num)
			return false;
	}

	int box_idx_x = (row/3)*3;
	int box_idx_y = (col/3)*3;
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			if(sudoku[box_idx_x+i][box_idx_y+i] == num)
				return false;
		}
	}
	return true;
}

bool rakhkeaaja(int sudoku[][9],int row,int col)
{

	//base case
	if(col>=9)
		return rakhkeaaja(sudoku,row+1,0);
	if(row>=9)
		return true;

	if(sudoku[row][col] != 0)
		return rakhkeaaja(sudoku,row,col+1);
	else
	{
		for(int i = 1;i<=9;i++)
		{
			if(koidikkattohnahi(sudoku,row,col,i) == true)
			{
				sudoku[row][col] = i;
				if(rakhkeaaja(sudoku,row,col+1)==true)
					return true;
				else sudoku[row][col] = 0;
			}
		}
		return false;
	}
}

int main()
{
	int sudoku[9][9] = {{0,5,2,4,0,0,1,0,0},
						{1,0,0,0,0,2,0,3,0},
						{0,0,0,8,1,3,0,2,5},
						{4,0,0,0,0,7,0,1,0},
						{6,8,3,0,0,0,5,9,7},
						{0,7,0,5,0,0,0,0,2},
						{8,9,0,3,6,5,0,0,0},
						{0,1,0,7,0,0,0,0,6},
						{0,0,6,0,0,4,9,7,0}};
	rakhkeaaja(sudoku,0,0);
	for(int i = 0;i<9;i++){
		for(int j = 0;j<9;j++)
		{
			cout<<sudoku[i][j]<<" ";
		}
		cout<<endl;
	}
}
