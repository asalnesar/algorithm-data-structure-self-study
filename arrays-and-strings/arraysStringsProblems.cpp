#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isUnique(string str)
{
    if(str.length() > 128) return false;

    bool charSet[128] = {0};
    for(int i=0 ; i< str.length() ; i++)
    {
        char curChar = str.at(i);
        if(charSet[curChar]) return false;
        charSet[curChar] = true;
    }
    return true;
}

void sortString(string &str)
{
    sort(str.begin(), str.end());
}

bool checkPermutation(string str1, string str2)
{
    if(str1.length() != str2.length()) return false;

    //we sort the strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    cout << "First  string: " << str1 << endl;
    cout << "Second string: " << str2 << endl;
    return str1 == str2;
}

void  testIsUniques()
{
    cout << "Check if a string has unique characters." << endl;
    cout << "Put in the string:";
    string str;
    cin >> str;
    bool result = isUnique(str);
    cout << "for string " << str << " result is " << result << endl;
}

void  testPermutation()
{
    cout << "Check permutation of two strings:" << endl;
    string str1, str2;
    cout << "Put in the first string:";
    cin >> str1;
    cout << "Put in the second string:";
    cin >> str2;
    bool result = checkPermutation(str1, str2);
    cout << "for string " << str1 << " and string " << str2 << " result is " << result << endl;
}

int main()
{
    testPermutation();
    return 0;
}

