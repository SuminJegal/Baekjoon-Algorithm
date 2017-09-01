#include <iostream>

using namespace std;


int main(){
    string s;
    int a, b;
    /*while(getline(cin,s)){
        a = atoi(s.substr(0,1).c_str());
        b = atoi(s.substr(1,2).c_str());
        printf("%d\n", a+b);
    }*/
    while(cin>>a>>b){
        printf("%d\n", a+b);
    }
}