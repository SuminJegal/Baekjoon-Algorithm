#include <iostream>

char s[1000];

int main() {    
    while(scanf("%[^\n]\n",s)==1){
        printf("%s\n", s);
    }
    return 0;
}

