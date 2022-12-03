/*
* Filename: f8.cpp
* Project: Focused8
* By: Brian Nguyen
* Date: December 2 2022
* Description:a program to give you practice at working with C-style strings, files, command-line
arguments, and structs
*/

#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyData
{
	int howMany;
	char theText[21];
	char directoryPath[80];
	char filename[80];
};

int main(int argc, char* argv[])
{
	struct MyData myArgs; 
	char fullname[100];
	FILE* f; 
	int i; 

	if (argc != 4)
	{
		printf("Error: Invalid Arguments passing");
		return 0;
	}
	else
	{
		myArgs.howMany = atoi(argv[1]);
		strcpy(myArgs.theText, argv[2]); 
		strcpy(myArgs.directoryPath, argv[3]); 
		strcpy(myArgs.filename, argv[4]); 
		strcat(fullname, "\\");
		strcat(fullname, myArgs.filename); 

		f = fopen(fullname, "w");
		if (f!= NULL)
		{
			for (i = 0; i < myArgs.howMany; i++)
			{
				fputs(myArgs.theText, f);
				fputs("\n", f);
			}
			fclose(f);
		}
	}
	return 0;
}