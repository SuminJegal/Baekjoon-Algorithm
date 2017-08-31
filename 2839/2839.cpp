#include <cstdio>

int main(){
    int weight;
    scanf("%d",&weight);
    int num_five = weight/5;

    if(weight%5 == 0)
        printf("%d\n", num_five);
    else if (weight%5 == 3)
        printf("%d\n", num_five+1);
    else {
        while(num_five > 0){
            num_five = num_five-1;
            if((weight - (5*num_five)) % 3 == 0){
                printf("%d\n", num_five + ((weight-(5*num_five))/3));
                return 0;
            }
        }
        printf("-1\n");
    }
}