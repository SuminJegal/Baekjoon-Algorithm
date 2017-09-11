#include<cstdio>
#include<vector>
using namespace std;

int check[1000][1000];

int solution(vector<vector<int>> board)
{
    int max = 0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == 1){
                if(i==0 || j==0){
                    check[i][j] = 1;
                    if(max <1)
                    max = 1;
                }
                else {
                    int a,b,c;
                    a = check[i-1][j-1];
                    if(a==0){
                        check[i][j] = 1;
                        //break;
                    }
                    b = check[i][j-1];
                    if(b==0){
                        check[i][j] = 1;
                        //break;
                    }
                    c = check[i-1][j];
                    if(c==0){
                        check[i][j] = 1;
                        //break;
                    }
                    if(a==b && b==c){
                        check[i][j] = a+1;
                    }
                    else{
                        int min = (a<b ? a : b);
                        min = (min<c ? min : c);
                        check[i][j] = min+1;
                    }
                    if(max < check[i][j])
                            max = check[i][j];
                }
            }
        }
    }
    
    int answer = max*max;
    return answer;
}