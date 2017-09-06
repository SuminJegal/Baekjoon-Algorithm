#include <iostream>

using namespace std;

int alphabet[26];

int char_to_int(char c){
    if((int)c < 97)
        return c-65;
    else
        return c-97;
}

int main(){
    
    int max=0;
    int max_num=0;
    int max_count=0;
    string s;
    cin >> s;
    
    for(int i=0; i<s.size(); i++){
        alphabet[char_to_int(s[i])] += 1;
    }

    for(int j=0; j<26; j++){
        if(alphabet[j]>max){
            max = alphabet[j];
            max_num = j;
            max_count = 1;
        }
        else if(alphabet[j]==max){
            max_count++;
        }
    }
    if(max_count==1)
        cout << (char)(max_num+65) << endl;
    else{
        cout << "?" << endl;
    }
}