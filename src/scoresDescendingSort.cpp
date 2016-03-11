/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

struct student * scoresDescendingSort(struct student *students, int len) {
	int i = 0, j = 0, temp = 0;
	struct student  s;
	if (len <= 0 || students == NULL) return NULL;
	for (i = 0; i < len - 1; i++)
	{
		temp = students[i].score;
		for (j = i + 1; j < len; j++)
		{
			if (students[j].score>temp)
			{
				s = students[j];
				students[j] = students[i];
				students[i] = s;
			}
		}
	}
	return students;
}