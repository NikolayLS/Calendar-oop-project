#pragma once
#include<iostream>
#include<cstring>
//function that makes integer from char*
int fromCharToInt(const char* oth)
{
	int sum = 0;
	int pow = 1;
	for (int i = strlen(oth) - 1; i >= 0; i--)
	{
		sum = sum + (oth[i] - 48) * pow;
		pow = pow * 10;
	}

	return sum;
}
//function that makes char* from integer
char* fromIntToChar(int oth)
{
	static char a[100];
	int i = 0;

	if (oth < 10)
	{
		a[0] = char(oth) + 48;
		a[1] = '\0';
	}

	while (oth != 0)
	{
		a[i] = char(oth % 10) + 48;

		oth = oth / 10;
		i++;
	}

	a[i + 1] = '\0';
	char swapHelper;

	for (int i = 0; i < strlen(a) / 2; i++)
	{

		swapHelper = a[i];
		a[i] = a[strlen(a) - 1 - i];
		a[strlen(a) - 1 - i] = swapHelper;
	}
	return a;
}
//function for finding (if the sentense contains keyword)
bool cmpFunction(const char* word, const  char* sentence)
{
	int lenWord = strlen(word);
	int lenSentence = strlen(sentence);

	for (int i = 0;i < lenSentence;i++)
	{
		if (sentence[i] == word[0])
		{
			int k = i;
			int j = 0;
			for (j = 0;j < lenWord;j++)
			{
				if (sentence[k] != word[j]) { j = lenWord + 10; }
				k++;
			}
			if (j == lenWord) return 1;
		}
	}
	return 0;
}
