// 2023.04.05(Wed) SAP Korea C++ engineer coding test

// 문제
/*
Question

The current selected programming language is C. We emphasize the submission of a fully working code over partially correct but efficient code. Once submitted, you cannot review this problem again. You can use printff) to debug your code. The printff) may not work in case of syntax/runtime error. The version of GCC being used is 5.5.0.
There are N soldiers standing in a line, with IDs from 1 to N, in ascending order. They are participating in an exercise consisting of Q actions. During the ith action, the Major calls S numbers row; and col. The soldiers at the row; th and colth positions swap places; then the soldiers at (row +1)th and (col-1)th positions swap places, and so on until (row +m)< (col-m). Each of the soldier's IDs will be covered in the range (row, col] for at most * one action.
Write an algorithm to find the ID of the soldier at Kth position in the line after all the actions are completed.

Input
The first line of the input consists of an integer- num, representing the number of soldiers (N).
The second line consists of two space-separated integers- actions and numSoldiers, representing the number of actions (Q) and number of soldiers called by the Major (S), respectively
The next Q lines consist of S space-separated integers - row; and col;, representing the positions of the soldiers initially called for the ith action.
The last line consists of an integer- posSoldier, representing the position of the soldier whose ID is requested to be found after Q actions (K).

Output
Print an integer representing the ID of the Kth position soldier in the line after Q actions.

Constraints
1 5 posSoldiers num s 10°
1 s actions s 105
1 s row;s cols num
1 sis actions
Example

Input:
10
22
610
option

Output:
5

Explanation:
Step1: After the 1st action, the position of soldiers is in the order:
5432 1 678 9 10.
Step2: After the 2nd action, the position of soldiers is in the order:
543 2 1 10 9 8 7 6.
Step3: The ID of the soldier at position 1 is 5.
so, the output is 5


*/


// 답안


//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/* only used in string related operations */
typedef struct String string;
struct String
{
    char *str;
};

char *input(FILE *fp, int size, int has_space)
{
    int actual_size = 0;
    char *str = (char *)malloc(sizeof(char)*(size+actual_size));
    char ch;
    if(has_space == 1)
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    else
    {
        while(EOF != (ch=fgetc(fp)) && ch != '\n' && ch != ' ')
        {
            str[actual_size] = ch;
            actual_size++;
            if(actual_size >= size)
            {
                str = realloc(str,sizeof(char)*actual_size);
            }
        }
    }
    actual_size++;
    str = realloc(str,sizeof(char)*actual_size);
    str[actual_size-1] = '\0';
    return str;
}
/* only used in string related operations */


//my custom fun begin

/*
typedef struct {
    int row;
    int col;
    int **data;
} array_double_int;
*/

typedef struct array_double_int array_double_int;
struct array_double_int
{
	int **data;
	int row;
	int col;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void soldierSwap(int *soldiers, int row, int col) {
    int m = (col - row) / 2;
    for (int i = 0; i <= m; i++) {
        swap(&soldiers[row+i-1], &soldiers[col-i-1]);
    }
}

void performActions(int *soldiers, int n, array_double_int actions) {
    for (int i = 0; i < actions.row; i++) {
        int row = actions.data[i][0];
        int col = actions.data[i][1];
        soldierSwap(soldiers, row, col);
    }
}

int findSoldierID(int *soldiers, int n, int k) {
    return soldiers[k-1];
}

// my custom fun end

/* origin def
typedef struct array_double_int array_double_int;
struct array_double_int
{
	int **data;
	int row;
	int col;
};
*/ 

//origin def end

int soldierAtK(int num, array_double_int soldierPosition, int posSoldier) {
    // Initialize soldiers
    int *soldiers = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        soldiers[i] = i + 1;
    }

    // Perform actions
    performActions(soldiers, num, soldierPosition);

    // Find soldier ID
    int soldierID = findSoldierID(soldiers, num, posSoldier);

    // Free memory
    free(soldiers);
    for (int i = 0; i < soldierPosition.row; i++) {
        free(soldierPosition.data[i]);
    }
    free(soldierPosition.data);

    return soldierID;
}

/*
 * 
 */

 /*
int  soldierAtK(int num, array_double_int soldierPosition, int posSoldier)
{
    int  answer;
    // Write your code here


    return answer;
}
*/


int main()
{
    int num;
	array_double_int soldierPosition;
	int posSoldier;
	
    //input for num
	scanf("%d", &num);
	
	//input for soldierPosition
	scanf("%d", &soldierPosition.row);
	scanf("%d", &soldierPosition.col);
	soldierPosition.data = (int **)malloc(sizeof(int *) * soldierPosition.row);
	for ( int idx = 0; idx < soldierPosition.row; idx++ )
	{
	    soldierPosition.data[idx] = (int *)malloc(sizeof(int) * soldierPosition.col);
	    for ( int jdx = 0; jdx < soldierPosition.col; jdx++ )
	    {
	        scanf("%d", &soldierPosition.data[idx][jdx]);
	    }
	}
	
	//input for posSoldier
	scanf("%d", &posSoldier);
	
	
    int result = soldierAtK(num, soldierPosition, posSoldier);
	printf("%d", result);
	
    return 0;
}
