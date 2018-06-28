#include "Sequence.h"
#include"stdlib.h"
#include<fstream>
#include<cstring>
#include<string>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

Sequence::Sequence(string FileName)
{
  	infile.open(FileName.c_str());

}


int Sequence::length()
{
	string  obj0;
	getline(infile, obj0);
	while (obj0.length()!= 0)
	{
		obj += obj0;
		getline(infile, obj0);
	}
	cout<< obj.length()<<endl;;
}

 int Sequence::numberOf()
{
	int a = 0; int b = 0; int c = 0; int d = 0;

	int l = obj.length();
	for (int m = 0; m<l; m++)
	{
		if (obj[m] == 'A')
			a++;
		else if (obj[m] == 'C')
			b++;
		else if (obj[m] == 'T')
			c++;
		else if (obj[m] == 'G')
			d++;
	}
	cout << "A=" << a << endl;
	cout << "C=" << b << endl;
	cout << "T=" << c << endl;
	cout << "G=" << d << endl;
	return 0;
}

string Sequence::longestConsecutive()
{      
	
	int l = obj.length();
	int len = 1;
	int max = 1;
	int n = 0;
	int mn = 0;
	int i = 1;

	while (i != l)
	{
		if (obj[i] == obj[i - 1])
		{
			len = i + 1 - n;
			if (len>max)
			{
				max = len;
				mn = n;
			}
		}
		else
		{
			n = i;
		}
		++i;
	}

	cout<< obj.substr(mn, max)<<endl;
}

int comlen(char *p, char*q)
{
	int len = 0;
	while (*p++ == *q++)
		++len;
	return len;
}

int pstrcmp(const void *p, const void *q)
{
	return strcmp( *(char* const*)p , *(char* const*)q);
}

string Sequence::longestRepeated()
{
	int len = obj.length();
	char *A = new char[len];
	char **B = new char*[len];
	ifstream fin("A.txt", ios::in);

	int n = 0;
	int l;
	int longest = 0;
	int index = 0;

	while (!fin.eof())
	{
		B[n] = &A[n];
		if (fin.peek() != '\n')
			A[n++] = fin.peek();
		fin.get();
	}

	A[n] = '\0';
	fin.close();
	qsort(B, n, sizeof(char*), pstrcmp);

	for (int i = 0; i<n - 1; i++)
	{
		l = comlen(B[i], B[i + 1]);
		if (l>longest)
		{
			longest = l;
			index = i;
		}
	}
	string longestrepeated = B[index];
	cout<< longestrepeated.substr(0, longest)<<endl;
}
