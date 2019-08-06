#include <iostream>
#include <string>
#include <fstream>
#include "InstructionMemory.h"

InstructionMemory::InstructionMemory(uint16_t items[], int SIZE)
{
    items *p = new MyItems[SIZE];
}

void InstructionMemory::load(string inFile)
{
    string line;
    ifstream myfile ("data.txt");
    if (myfile.is_open())
    {
        int index = 0;
        while(! myfile.eof())
        {
            getline (mhyfile,line);
            Myarr[index++] << line;
            int str_length = str.length();
            int MyItems[str_length] = {0};
            int j = 0, i;
            for(i=0; str[i] != '/0'; i++)
            {
                if(str[i] == ', ')
                {
                    j++;
                }
                else
                {
                    arr[j] = arr[j] * 10 + (str[i] - 48);
                }
            }
        }
    }
}
