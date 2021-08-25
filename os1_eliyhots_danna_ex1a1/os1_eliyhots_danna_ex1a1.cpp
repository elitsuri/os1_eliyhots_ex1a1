/*
* ex1.cpp - Windows (Father file)
*
*  Created on: Nov 5, 2017
*      Author: eliyho tsuri ,dan narkisi
*       Login: eliyhots, danna
*
* On this file the father begets 3 children who perform bubble
* sort and quicksort hogral number search by serial search
*/
// --------------------- Include Section -----------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <process.h>
#include <Windows.h>
#include <string.h>
// ------------------------- Define ----------------------------
#define SIZE 100
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define NUM_OF_CHILD 3
// ------------------------ Prototype --------------------------
void set_names (char child_names[][SIZE]);
// -------------------------- Main -----------------------------
int main ()
{
	char child_names[NUM_OF_CHILD][SIZE];
	char value_array[SIZE + 300] = "\0";
	char new_argv[SIZE * NUM_OF_CHILD + 300] = "\0";
	PROCESS_INFORMATION pif[NUM_OF_CHILD];
	char value[SIZE];
	int index;


	srand ((unsigned)time (NULL));
	for (index = 0; index < SIZE; index++)
	{
		sprintf_s (value, "%d ", rand () % SIZE);
		strcat_s (value_array, value);
	}
	set_names (child_names);
	for (index = 0; index < NUM_OF_CHILD; index++)
	{
		new_argv[0] = '\0';
		strcat_s (new_argv, child_names[index]);
		strcat_s (new_argv, value_array);
		STARTUPINFO soninf;
		ZeroMemory (&soninf, sizeof (soninf));
		soninf.cb = sizeof (soninf);
		BOOL isborn = CreateProcessA (NULL, new_argv, NULL, NULL, false, 0, NULL, NULL, &soninf, &pif[index]);
		if (!isborn)
		{
			puts ("Create Process failed");
			exit (EXIT_FAILURE);
		}
		else
		{
			WaitForSingleObject (pif[index].hProcess, INFINITE);
			CloseHandle (pif[index].hProcess);
			CloseHandle (pif[index].hThread);
		}
	}
	getchar ();
	return (EXIT_SUCCESS);
}
// -------------------------------------------------------------
void set_names (char child_names[][SIZE])
{
	strcpy_s (child_names[0], "os_eliyhots_danna_ex1a2.exe ");
	strcpy_s (child_names[1], "os_eliyhots_danna_ex1a3.exe ");
	strcpy_s (child_names[2], "os_eliyhots_danna_ex1a4.exe ");
}