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
                
            }
        }
    }

    for(int i=0; i<city_size; i++){
        for(int j=0; j<city_size; j++){
            cout << drink_milk[i][j].count << " ";
        }
        cout << endl;
    }

}