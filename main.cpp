#include<iostream>
#include<fstream>
#include"Sequence.h"
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    Sequence a("A.txt");
    
    a.length();
    a.numberOf();
    a.longestConsecutive();
    a.longestRepeated();
    return 0;
}

