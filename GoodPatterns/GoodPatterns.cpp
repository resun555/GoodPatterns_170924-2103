// GoodPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>


struct Pattern
{
	size_t length;
	char **matrix;
};


int main()
{
	int n = -1;
	scanf("%d", &n);
	if (n < 0)
	{
		exit(EOF);
	}
	else
	{
		struct Pattern pattern;
		pattern.length = n;
		pattern.matrix = (char **)malloc(sizeof(char *) * pattern.length);
		for (size_t i = 0; i < pattern.length; i++)
		{
			pattern.matrix[i] = (char *)malloc(sizeof(char) * pattern.length);
		}
		for (size_t i = 0; i < pattern.length; i++)
		{
			memset(pattern.matrix[i], 95, pattern.length);
		}
		size_t subLength = pattern.length + 2;
		while (subLength > 2)
		{
			subLength -= 2;
			for (size_t i = (pattern.length - subLength) / 2; i < (pattern.length + subLength) / 2; i++)
			{
				memset(pattern.matrix[i] + (pattern.length - subLength) / 2, !((pattern.matrix[i][(pattern.length - subLength) / 2] - 95) / (-53)) * (-53) + 95, subLength);
			}
		}
		for (size_t i = 0; i < pattern.length; i++)
		{
			for (size_t j = 0; j < pattern.length; j++)
			{
				printf("%c", pattern.matrix[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

