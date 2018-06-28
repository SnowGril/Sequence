#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Sequence
{
public:
    Sequence(string FileName);
    
    int length();
    int numberOf();
    string longestConsecutive();
    string longestRepeated();
private:
    ifstream infile;   
    string obj; 
};

#endif
