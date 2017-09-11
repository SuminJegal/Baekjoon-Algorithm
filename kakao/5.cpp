#include<cstdio>
#include<vector>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
    int row = land.size();
    int size_land[row][4];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<4; j++){
            size_land[i][j] = land[i][j];
            if( i > 0 ){
                int a, b, c;
                a = size_land[i-1][(j+1)%4];
                b = size_land[i-1][(j+2)%4];
                c = size_land[i-1][(j+3)%4];
                int max = (a>b ? a : b);
                max = (max>c ? max : c);
                size_land[i][j] = size_land[i][j] + max;
            }
            if( i==(row-1) && answer < size_land[i][j])
                answer = size_land[i][j];
        }
    }
    
	return answer;
}