// c style also a char array main difference is last element is \0
//\0 ascii value is 0
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s1[] = "gfg";
    char s2[] = {'c', 'p', 'p', '\0'}; // these two ways to write a c style string
    cout << strlen(s1) << "\n";        // auto \0 come but dint count in length so 3 is length
    cout << strlen(s2) << "\n";        // if no \0 it dont stop infinite or random value

    char s3[] = "gfg";
    char s4[] = "abcd";
    int res = strcmp(s1, s2); // also compare lexicographically if equal return 0 if s3<s4 return a -ve value
    if (res == 0)
    {
        cout << "same";
    }
    else if (res < 0)
    {
        cout << "smaller";
    }
    else
    {
        cout << "greater";
    }
    //in c++ we can initialize a string and asign a value to it later but not in c have to use strcpy

    char str[5];
    strcpy(str,"gfg");
    cout<<str;
    return 0;
}