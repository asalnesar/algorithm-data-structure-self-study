#include <iostream>
#include <string>

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

int main()
{
    cout << "Put in the string:";
    string str;
    cin >> str;
    bool result = isUnique(str);
    cout << "for string " << str << " result is " << result << endl;
    return 0;
}

