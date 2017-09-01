#include <iostream>

using namespace std;


int main(){
    string s;
    while(getline(cin,s)){
        int a, b;
        a = atoi(s.substr(0,1).c_str());
        b = atoi(s.substr(1,2).c_str());
        if (a==0 && b==0)
            return 0;
        printf("%d\n", a+b);
    }
}