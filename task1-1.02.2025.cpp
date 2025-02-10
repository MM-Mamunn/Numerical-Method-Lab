#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    vector<int>v;
    string  temp = "";
    s += ' ';
    for( int i = 0 ; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            int x = stoi(temp);
            v.push_back(x);
            temp = "";
            continue;
        }
        temp += s[i];

    }
      cout<<v.size()<<endl;
    for(auto a : v)cout<<a<<' ';cout<<endl;

    return 0;
}
