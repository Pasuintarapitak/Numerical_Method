#include<iostream>
#include<cmath>
using namespace std;
#define n 9
double x[n] = {10,15,20,30,40,50,60,70,80};
double fx[n] = {5,9,15,18,22,30,35,38,43};
double sumFunc(int row , int col){
    double total = 0;
    if(row == 0 && col == 0){
        return n; 
    }
    else{
        for (int i = 0; i < n; i++)
        {
            total += pow(x[i],row+col);
        }
        return total;   
    }
}
int main(){
   
    int order;
    cin >> order;
    double m[order+1][order+1];
    for(int i = 0 ; i < order+1 ; i++){
        for(int j = 0 ; j < order+1 ; j++){
            m[i][j] = sumFunc(i,j);
        }
    }
    for(int i = 0 ; i < order+1 ; i++){
        for(int j = 0 ; j < order+1 ; j++){ 
            cout << m[i][j] <<" ";
        }cout << endl;
    }

    return 0;
}