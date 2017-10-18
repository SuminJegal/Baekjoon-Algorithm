#include <iostream>

using namespace std;

int main(){

    int count = 0; 
    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        int tmp = (int)s[i]-65;
        count += (tmp/3) + 3;
        if (tmp==18 || tmp==21 || tmp>=24)
            count -= 1;
    }

    cout << count;
}