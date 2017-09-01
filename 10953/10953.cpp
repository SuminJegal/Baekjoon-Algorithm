#include <cstdio>

int main(){
    int test_case;
    scanf("%d", &test_case);
    
    for(int i=0; i<test_case; i++){
        int a, b;
        scanf("%d,%d", &a, &b);
        printf("%d\n", a+b);
    }
}