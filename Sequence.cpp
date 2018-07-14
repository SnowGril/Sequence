#include "Sequence.h"
#include"stdlib.h"
#include<fstream>
#include<cstring>
#include<string>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

Sequence::Sequence(string filename)
{
        Filename=filename;
        infile.open(filename.c_str());
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
        return obj.length();
}

 int Sequence::numberOf(char base)
{
	int a = 0; 
        int l=obj.length();
        
        for(int m=0;m<l;m++)
        {
          if(obj[m]==base)
              a++;}
	cout<<a<<endl;
          return a;
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
		{	n = i;	}
		++i;
	}

	cout<< obj.substr(mn, max)<<endl;
        return  obj.substr(mn, max);
}

int pstrcmp(const void *p, const void *q)
    {    return strcmp( *(char* const*)p , *(char* const*)q);}

int pointlen(char *a, char*b)
{	int len = 0;
	while (*a++ == *b++)
		++len;
	return len;
}

string Sequence::longestRepeated()
{
  
	int len = obj.length();
	char *A = new char[len];
	char **B = new char*[len];
	ifstream fin;
         fin.open(Filename.c_str());
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
		l = pointlen(B[i], B[i + 1]);
		if (l>longest)
		{
			longest = l;
			index = i;
		}
	}
	string longestrepeated = B[index];
	cout<< longestrepeated.substr(0, longest)<<endl;
        return  longestrepeated.substr(0, longest);
}
