#include <iostream>
#include <vector>
#include <string>
#include<map>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int a = 10;
    cin>>a;
    cout<<a<<endl;
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;


    return 0;
}