#include "change.h"

void zdvig_left(int a[][4])
{
	for(int i = 0; i < 4; i++)
	{
		int ji = 0;
		for (int j = 0; j < 4; j++)
			if(a[i][j])
				a[i][ji++] = a[i][j];
		for (int j = ji; j < 4; j++)
			a[i][j] = 0;
		for (int j = 0; j < 3; j++)
			if (a[i][j] == a[i][j + 1])
			{
				a[i][j] += a[i][j];
				a[i][j + 1] = 0;
			}
		ji = 0;
		for (int j = 0; j < 4; j++)
			if(a[i][j])
				a[i][ji++] = a[i][j];
		for (int j = ji; j < 4; j++)
			a[i][j] = 0;
	}
}


void zdvig_right(int a[][4])
{
	for(int i = 0; i < 4; i++)
	{
		int ji = 3;
		for(int j = 3; j >= 0; j--)
	 		if (a[i][j])
				a[i][ji--] = a[i][j];
		for (int j = ji; j >= 0; j--)
			a[i][j] = 0;
		for(int j = 3; j > 0; j--)
			if (a[i][j] == a[i][j - 1])
			{
				a[i][j] += a[i][j];
				a[i][j - 1] = 0;
			}
		ji = 3;
		for(int j = 3; j >= 0; j--)
	 		if (a[i][j])
				a[i][ji--] = a[i][j];
		for (int j = ji; j >= 0; j--)
			a[i][j] = 0;
	}
}


	

void zdvig_up(int a[][4])
{
	for (int i = 0; i < 4; i++)
	{
		int ji = 0;
		for(int j = 0; j < 4; j++)
			if (a[j][i])
				a[ji++][i] = a[j][i];
		for(int j = ji; j < 4; j++)
			a[j][i] = 0;
		for(int j = 0; j < 3; j++)
			if (a[j][i] == a[j + 1][i])
			{
				a[j][i] += a[j][i];
				a[j + 1][i] = 0;
			}
		ji = 0;
		for(int j = 0; j < 4; j++)
			if (a[j][i])
				a[ji++][i] = a[j][i];
		for(int j = ji; j < 4; j++)
		        a[j][i] = 0;
	}
}



void zdvig_down(int a[][4])
{
	for (int i = 0; i < 4; i++)
	{
		int ji = 3;
		for(int j = 3; j >= 0; j--)
			if(a[j][i])
				a[ji--][i] = a[j][i];
		for (int j = ji; j >= 0; j--)
			a[j][i] = 0;
		for(int j = 3; j > 0; j--)
			if (a[j][i] == a[j - 1][i])
			{
				a[j][i] += a[j][i];
				a[j - 1][i]  = 0;
			}
		ji = 3;
		for(int j = 3; j >= 0; j--)
			if(a[j][i])
				a[ji--][i] = a[j][i];
		for (int j = ji; j >= 0; j--)
			a[j][i] = 0;
	}
}



void rando(int a[][4])
{
        int prid = 0;	
	struct pair{ 
	       int first;
               int second;
	}s[16];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (!a[i][j])
			{
				s[prid].first = i;
				s[prid++].second = j;
  	  		}
        if (prid){
		prid = rand() % prid;
		a[s[prid].first][s[prid].second] = 2;
	}
}
