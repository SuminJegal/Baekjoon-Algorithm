#include <iostream>

using namespace std;

int space[111][111];
int robotX[111];
int robotY[111];
char robotD[111];

char go_left(char input){
    switch(input){
        case 'N':
            return 'W';
        case 'W':
            return 'S';
        case 'S':
            return 'E';
        case 'E':
            return 'N';
        default:
            return 'X';
    }

}

char go_right(char input){
    switch(input){
        case 'N':
            return 'E';
        case 'W':
            return 'N';
        case 'S':
            return 'W';
        case 'E':
            return 'S';
        default:
            return 'X';
    }
}

int main(){
    int a, b;
    int n, m;
    cin >> a >> b;
    cin >> n >> m;
    //cout << m << endl;


    for(int i=1; i<=n; i++){
        cin >> robotX[i] >> robotY[i] >> robotD[i];
    }
    for(int i=1; i<=m; i++){
        int target, count;
        char order;
        cin >> target >> order >> count;
        switch(order){
            case 'L':
                for(int j=0; j<count; j++)
                    robotD[target] = go_left(robotD[target]);
                break;
            case 'R':
                for(int j=0; j<count; j++)
                    robotD[target] = go_right(robotD[target]);
                break;
            case 'F':
                if(robotD[target]=='N'){
                    for(int j=1; j<=n; j++){
                        if(robotX[j] == robotX[target]){
                            if(robotY[j] <= robotY[target]+count && robotY[j] > robotY[target]){
                                cout << "Robot " << target << " crashes into robot " << j;
                                return 0;
                            }
                        }
                    }
                    if(robotY[target]+count > b){
                        cout << "Robot " << target << " crashes into the wall";
                        return 0;
                    }
                    robotY[target] = robotY[target] + count;
                    cout << "x = " << robotX[target] << " y = " << robotY[target] << endl;
                }
                else if(robotD[target]=='E'){
                    for(int j=1; j<=n; j++){
                        if(robotY[j] == robotY[target]){
                            if(robotX[j] <= robotX[target]+count && robotX[j] > robotX[target]){
                                cout << "Robot " << target << " crashes into robot " << j;
                                return 0;
                            }
                        }
                    }
                    if(robotX[target]+count > a){
                        cout << "Robot " << target << " crashes into the wall";
                        return 0;
                    }
                    robotX[target] = robotX[target] + count;
                    cout << "x = " << robotX[target] << " y = " << robotY[target] << endl;
                }
                else if(robotD[target]=='S'){
                    for(int j=1; j<=n; j++){
                        if(robotX[j] == robotX[target]){
                            if(robotY[j] >= robotY[target]-count && robotY[j] < robotY[target]){
                                cout << "Robot " << target << "crashes into robot " << j;
                                return 0;
                            }
                        }
                    }
                    if(robotY[target]-count < 0){
                        cout << "Robot " << target << " crashes into the wall ";
                        return 0;
                    }
                    robotY[target] = robotY[target] - count;
                    cout << "x = " << robotX[target] << " y = " << robotY[target] << endl;
                }
                else{
                    for(int j=1; j<=n; j++){
                        if(robotY[j] == robotY[target]){
                            if(robotX[j] >= robotX[target]-count && robotX[j] < robotX[target]){
                                cout << "Robot " << target << " crashes into robot " << j;
                                return 0;
                            }
                        }
                    }
                    if(robotX[target]-count < 0){
                        cout << "Robot " << target << " crashes into the wall";
                        return 0;
                    }
                    robotX[target] = robotX[target] - count;
                    cout << "x = " << robotX[target] << " y = " << robotY[target] << endl;
                }
                break;

        }
        
    }

    cout << "OK";
}