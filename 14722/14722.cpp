#include <iostream>
#include <algorithm>

using namespace std;

struct Milk{
    int count;
    int type;
};

struct Milk drink_milk[1000][1000];
struct Milk not_drink[1000][1000];

int main(){
    int city_size;
    scanf("%d", &city_size);

    int city[city_size][city_size];

    for(int i=0; i<city_size; i++){
        for(int j=0; j<city_size; j++){
            cin >> city[i][j];
        }
    }
    
    for(int i=0; i<city_size; i++){
        for(int j=0; j<city_size; j++){
            if(i>0 && j>0){
                int expect = (city[i][j]+2)%3;
                if(expect == drink_milk[i-1][j].type){
                    drink_milk[i][j].count = drink_milk[i-1][j].count+1;
                    drink_milk[i][j].type = (expect+1)%3;
                }
                else{
                    drink_milk[i][j].count = drink_milk[i-1][j].count;
                    drink_milk[i][j].type =  drink_milk[i-1][j].type;
                }
                if(expect == drink_milk[i][j-1].type){
                    drink_milk[i][j].count = max(drink_milk[i][j-1].count+1, drink_milk[i][j].count);
                    drink_milk[i][j].type = (expect+1)%3;
                }
                else{
                    drink_milk[i][j].count = max(drink_milk[i][j-1].count, drink_milk[i][j].count);
                    if(drink_milk[i][j].count == drink_milk[i][j-1].count)
                        drink_milk[i][j].type = drink_milk[i][j-1].type;
                }
            }
            else if(i>0){
                int expect = (city[i][j]+2)%3;
                if(expect == drink_milk[i-1][j].type){
                    drink_milk[i][j].count = drink_milk[i-1][j].count+1;
                    drink_milk[i][j].type = (expect+1)%3;
                }
                else{
                    drink_milk[i][j].count = drink_milk[i-1][j].count;
                    drink_milk[i][j].type =  drink_milk[i-1][j].type;
                }
            }
            else if(j>0){
                int expect = (city[i][j]+2)%3;
                if(expect == drink_milk[i][j-1].type){
                    drink_milk[i][j].count = drink_milk[i][j-1].count+1;
                    drink_milk[i][j].type = (expect+1)%3;
                }
                else{
                    drink_milk[i][j].count = drink_milk[i][j-1].count;
                    drink_milk[i][j].type =  drink_milk[i][j-1].type;
                }
            }
            else{
                if(city[i][j] == 0){
                    drink_milk[i][j].count = 1;
                    drink_milk[i][j].type = 0;
                }
                else{
                    drink_milk[i][j].count = 0;
                    drink_milk[i][j].type = 2;
                }
            }
        }
    }

    for(int i=0; i<city_size; i++){
        for(int j=0; j<city_size; j++){
            cout << drink_milk[i][j].count << " ";
        }
        cout << endl;
    }

    cout << drink_milk[city_size-1][city_size-1].count << endl;
}