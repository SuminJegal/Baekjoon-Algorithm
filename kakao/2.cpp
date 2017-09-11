#include <cstdio>
#include<vector>
using namespace std;

int check[100001];

bool solution(vector<int> arr)
{
    int arr_size = arr.size();
    int count = 0;
    int max = 0;   
    bool answer = false;
    for(int i=0; i<arr_size; i++){
        int arr_num = arr[i];
        if (arr_num>arr_size){
            return false;
        }
        int temp = check[arr_num];
        if (temp==1){
            return false;
        }
        check[arr_num] = 1;
        count++;
    }
    if (count==arr_size)
        answer = true;
	return answer;
}