// 문제

/*
Question

The current selected programming language is C. We emphasize the submission of a fully working code over partially correct but efficient code. Once submitted, you cannot review this problem again. You can use printff to debug your code. The printf) may not work in case of syntax/runtime error. The version of GCC being used is 5.5.0.
Max does not like any line segment that he sees on the X-axis.
Today, his brother drew N line segments on it. Max has a magical marker that can erase all the line segments that pass through a point on the X-axis when he places the marker on that point. For example, he wishes to erase two line segments - one with endpoints (1,0) and (4,0), and another with endpoints (3,0) and (7,0). He can clear both lines at once by placing the marker either at point (3,0) or (4,0) but he cannot do so if he places the marker anywhere else.
Write an algorithm to find the minimum number of times Max must use the marker to clear the X-axis.

Input
The first line of the input consists of an integer
- nums, representing the number of starting X-coordinates of line segments on the X-axis (N).
The second line consists of N space-separated integers - startXo startXy, ..startX-1, representing the X-coordinates of the starting points of line segments.
The third line consists of an integer - numE, representing the number of ending X-coordinates of line segments on the X-axis (M=N always).
The last line consists of M space-separated integers - endXo endxy, , endX-1, representing the X- coordinates of the ending points of the line segments

Output
Print an integer representing the minimum number of times Max must use the marker to clear all the line segments on the X-axis.

Constraints
0 ≤ numS = numEs 106
- 10° ≤ startx, endX,s10° 0 si< nums


Example
Input:
0 2 4-8
45 6-9

Output:
2


Explanation:
Placing the marker at point 4 on the X-axis will erase the first three line segments.
The remaining line segment must be erased by placing the marker at any point on -9 or -8.
So, the number of times the marker must be placed on the X-axis is 2.


*/



// 답안 코드  테케 1번 틀림

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

typedef struct array_single_int array_single_int;
struct array_single_int
{
	int *data;
	int size;
};


/*
 * Starting X-coordinates of the line segments
 */
int  markerPlaced(array_single_int startX, array_single_int endX)
{
    int  answer = 1;
    // Write your code here
    int cnt = 1;
    int i = 1, j = 0;
    int n = startX.size;

    while(i < n && j < n)
    {
        if(startX.data[i] <= endX.data[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }

        answer = (answer < cnt) ? cnt : answer;
    }

    return answer;
}

int main()
{
    array_single_int startX;
	array_single_int endX;
	
    //input for startX
	scanf("%d", &startX.size);
	startX.data = (int *)malloc(sizeof(int) * startX.size);
	for ( int idx = 0; idx < startX.size; idx++ )
	{
	    scanf("%d", &startX.data[idx]);
	}
	
	//input for endX
	scanf("%d", &endX.size);
	endX.data = (int *)malloc(sizeof(int) * endX.size);
	for ( int idx = 0; idx < endX.size; idx++ )
	{
	    scanf("%d", &endX.data[idx]);
	}
	
	
    int result = markerPlaced(startX, endX);
	printf("%d", result);
	
    return 0;
}
