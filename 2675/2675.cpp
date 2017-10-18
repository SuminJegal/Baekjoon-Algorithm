#include <iostream>

using namespace std;

int main(){
    int repeat;
    int num;
    string s;
    cin >> repeat;
    for(int i=0; i<repeat; i++){
        cin >> num;
        cin >> s;
        for(int j=0; j<s.size(); j++)
            for(int k=0; k<num; k++)
                cout << s[j];
        cout << endl;
    }

}