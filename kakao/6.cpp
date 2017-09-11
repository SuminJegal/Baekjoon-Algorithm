#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int max_with_1[100000];
int max_except_1[100000];

int solution(vector<int> sticker)
{
    int sticker_size = sticker.size();
    int answer=0;
    
    if(sticker_size<=3){
        for(int i=0; i<sticker_size; i++){
            answer = max(answer, sticker[i]);
        }
        return answer;
    }
    
    for(int i=0; i<sticker_size; i++){
        if(i==0){
            max_with_1[i] = sticker[i];
            max_except_1[i] = 0;
        }
        else if(i==1){
            max_with_1[i] = max(sticker[i], max_with_1[i-1]);
            max_except_1[i] = max(sticker[i], max_except_1[i-1]);
        }
        else if(i==(sticker_size -1)){
            max_except_1[i] = max((max_except_1[i-2]+sticker[i]), max_except_1[i-1]);
            answer = max(max_with_1[i-1],max_except_1[i]);
        }
        else {
            max_with_1[i] = max((max_with_1[i-2]+sticker[i]), max_with_1[i-1]);
            max_except_1[i] = max((max_except_1[i-2]+sticker[i]), max_except_1[i-1]);
        }
    }
    
    /*for(int i=0; i<sticker_size; i++){
        printf("%d ", max_with_1[i]);
    }
    printf("\n%d %d", max_with_1[sticker_size-2], max_except_1[sticker_size-1]);*/
	return answer;
}