// Basic of Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Display(char str[]);
void StringLength(char str[])
{
    int i;
    for (i = 0; str[i]!='\0'; i++)
    {
    }
    cout << "The length is " << i << endl;
}

void ChangeCase(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }  
    cout<< str;
}

void CompareStrings(char str1[], char str2[])
{
    int i;
    for (i = 0; (str1[i] != '/0') && (str2[i] != '/0'); i++)
    {
        if (str1[i] != str2[i])
        {
            cout << endl<<"strings are not equal";
            break;
        }
        else if (str1[i] == '/0' && str2[i] == '/0')
        {
            cout << endl << "strings are equal";
        }
    }
}


void Display(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        cout << str[i];
}


int main()
{
    int size = 10;
    char name[] = { 'J','O','H','N','\0' };
    char student[] = "jordan";
    char player[] = "jordan";

    StringLength(name);
    StringLength(student);
    ChangeCase(name);
    CompareStrings(student, player);

}

