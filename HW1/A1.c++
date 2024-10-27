#include<iostream>
// #include<math.h>
using namespace std;
#define MAX 10
int main(){
    int num_pos = 0 , num_neg = 0;
    double y , z , result,fx;
    double positive_num[MAX] , negative_num[MAX];
    for (int x = 0; x <= 10; x++) //find range since 0<=x<=10 that closed to zero
    {
        result = (43*x) - 180;
        if(result > 0){
            positive_num[num_pos++] = result;
        }
        else{
            negative_num[num_neg++] = result;
        }
    }
    z = positive_num[0];
    y = negative_num[0];

    for(int j = 1; j<num_neg; j++){//find y that closed to zero by negative
        if(y < negative_num[j]){
            y = negative_num[j];
        }
    } 
    for(int i = 1; i<num_pos; i++){ //find y that closed to zero by positive
        if(z > positive_num[i]){
            z = positive_num[i];
        }
    }
    
    /*หาตัวดักอยู่*/
    // for (double k = y; k <= z ; k+=0.000001)
    // {
    //     result = (43*k) - 180;
    //     if(fabs(result) == 0.000001){
    //         cout<<result;
    //         return 0;
    //     }
    // }
    return 0;
}


