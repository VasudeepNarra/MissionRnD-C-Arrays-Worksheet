/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <iostream>
#include <malloc.h>
#include<string.h>

struct student {
	char *name;
	int score;
}st2;
struct student *st = (struct student *)malloc(10 * sizeof(struct student));
struct student ** topKStudents(struct student *students, int len, int K) {
	if (K <= 0 || len <= 0)
		return NULL;
	int i, j, t;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (students[j].score < students[i].score)
			{
				t = students[j].score;
				students[j].score = students[i].score;
				students[i].score = t;

			}
		}
	}
	if (len>K)
		t = len - K;
	j = 0;
	if (len > K)
	{

		for (i = t; i < len; i++)
		{
			st[j].score = students[i].score;
			j++;

		}
		return &st;
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			st[j].score = students[i].score;
			j++;

		}
		return &st;
	}


}