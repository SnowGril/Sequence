#include<iostream>
#include<fstream>
#include"Sequence.h"
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    Sequence a("dna.txt");
    
    a.length();
    a.numberOf('A');
    a.longestConsecutive();
    a.longestRepeated();
    return 0;
}

