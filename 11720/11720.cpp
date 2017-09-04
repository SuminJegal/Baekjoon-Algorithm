#include <cstdio>

int main(){
    int n;
    int sum=0;
    scanf("%d", &n);
    int num[n];
    for(int i=0; i<n; i++){
        scanf("%1d", &num[i]);
        sum = sum + num[i];
    }
    printf("%d\n",sum);
}