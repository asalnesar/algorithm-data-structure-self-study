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
    return str1 == str2;
}

bool checkPermutation2(string str1, string str2)
{
    if(str1.length() != str2.length()) return false;

    int letters[128] = {0};

    for(int i= 0 ; i < str1.length(); i++)
    {
        letters[str1.at(i)]++;
    }
    for(int i= 0 ; i < str2.length(); i++)
    {
        letters[str2.at(i)]--;
        if(letters[str2.at(i)] < 0) return false;
    }
    return true;
}

int countSpace(string str, int start, int end, int target)
{
    int count = 0;
    for(int i= start ; i< end; i++){
        if(str.at(i) == target)
        {
            count++;
        }
    }
    return count;
}

string urlify(string str, int trueLength)
{
    int numberOfSpaces =  countSpace(str, 0, trueLength, ' ');
    int newIndex = trueLength - 1 + (numberOfSpaces * 2);
    cout <<"number of spaces: " << numberOfSpaces << endl;
    cout <<"new index: "<<newIndex <<endl;
    if(newIndex + 1 < str.length()) {
        str.at(newIndex+1)='\0';
    }
    for(int i = trueLength - 1; i >=0 ; i--)
    {
        if(str.at(i) == ' '){
            str.at(newIndex) = '0';
            str.at(newIndex - 1) = '2';
            str.at(newIndex  - 2) = '%';
            newIndex -= 3;
        }
        else{
            str.at(newIndex) = str.at(i);
            newIndex--;
        }
    }
    return str;
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
    bool result = checkPermutation2(str1, str2);
    cout << "for string " << str1 << " and string " << str2 << " result is " << result << endl;
}

void testUrlify()
{
    cout << urlify("asal nesar nobari     ", 17) << endl;
}

int main()
{
    testUrlify();
    return 0;
}

