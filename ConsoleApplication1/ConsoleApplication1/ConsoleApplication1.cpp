// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>


int counter(const std::string& source)
{
    int mass[10];
    int max = 0;
    int number = 0;
    char symbol[2];
    for (int i = 0; i < 10;i++)
    {
        mass[i] = 0;
    }
    for (int i = 0; i < source.length(); i++)
    {
        if ((source.at(i) >= 48) && (source.at(i) <= 57)) 
        {
            symbol[0] = source.at(i);
            number = atoi(symbol);
            mass[number]++;
        }
    }
    for(int i = 0 ; i < 10 ; i++)
    {
        if (max < mass[i])max = mass[i];
    }
    return max;
}

int main()
{
    std::string str1 = "228�����0�_�47�_7�0�_4_��_���_���4";
    std::cout<<counter(str1)<<std::endl;
    system("pause");
    return 0;
}

