// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
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
    std::string str1 = "228ублюд0к_м47ь_7в0ю_4_ну_иди_сюд4";
    std::cout<<counter(str1)<<std::endl;
    system("pause");
    return 0;
}

