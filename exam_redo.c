#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_LENGTH 20

typedef struct {
	char name[MAX_LENGTH];
	int marks;
}MARKS;


int main() 
{
	int i,j, n;
	MARKS **m;
	printf("Enter the number of students: ");
	scanf("%d", &n);
	m = (MARKS**) calloc(n, sizeof(MARKS*));

	for(i=0; i<n; i++)
	{
		int num;
		char buff_clear;
		printf("Enter the number of subjects for student%d: ", i+1);
		scanf("%d", &num);

		m[i] = (MARKS*) calloc(num, sizeof(MARKS));

		for (int j = 0; j < num; ++j)
		{
			printf("Enter subject%d and marks: ", j+1);
			fgets(m[i][j].name,MAX_LENGTH,stdin);
			scanf("%d", &m[i][j].marks);
		}


	}

	printf("-------------------\n");

	for (i = 0; i < n; ++i)
	{
		int num = sizeof(m[i])/sizeof(MARKS);
		printf("STUDENT%d\n", i+1);
		printf("SUBJECT NAME - MARKS");
		for (j = 0; j < num; ++j)
		{
			printf("%s - %d", m[i][j].name, m[i][j].marks);
		}
	}

	printf("-------------------\n");

	for(i=0; i<n; i++)
	{
		int largest = INT_MIN;
		int num = sizeof(m[i])/sizeof(MARKS);
		for(j=0; j<num; j++)
		{
			if(largest < (m[i][j].marks))
			{
				largest = (m[i][j].marks);
			}
		}

		printf("Highest marks of student%d is %d", i+1, largest);
	}

	return 0;
}