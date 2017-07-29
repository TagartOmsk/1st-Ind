// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

std::string shuffle(const std::string& source) {
    std::string str1 = source;
    std::string strResult = "";
    int n = 0;
    while (strResult.length() != source.length())
    {
        n = rand() % str1.length();
        strResult += str1.at(n);
        str1.erase(n, 1);
    }
    return strResult;
}

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
        if (isdigit(source[i])) 
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

std::string generator(char pref,int numONom,int length)
{
    int numbers = 0;
    int prenum = 0;
    int j = 0;
    std::string result="";
    char buffer = 0;
    for (int i = 0; i < length; i++)
    {
        do
        {
            buffer = rand() % 127;
        } while (!isprint(buffer));
        result += buffer;
        if (isdigit(buffer))
        {
            numbers++;
            if (buffer == pref)prenum++;
        }
    }
    while(numbers < numONom) 
    {
        if(!isdigit(result.at(j)))
        {
            result[j] = char(rand() % 10 + 48);
            numbers++;
            if (result.at(j) == pref)prenum++;
        }
        j=rand()%length;
    }
    int max = counter(result);
    if (prenum < max) {
        for (int i = 0; i < length; i++) {
            if((isdigit(result.at(i)))&&(result.at(i)!=pref))
            {
                result[i] = pref;
                prenum++;
            }
        }
    }
    return result;
}

int main()
{
    srand(time(0));
    /*std::string str1 = "64574rd, fuck y0ur m07h3r, why d0 n07 y0u g0 d0g 55 h3r3, d3c1d3d t0 c0me t0 m3?";
    std::cout<<counter(str1)<<std::endl;*/
    std::cout << generator(0, 15, 25)<<std::endl;

    system("pause");
    return 0;
}

