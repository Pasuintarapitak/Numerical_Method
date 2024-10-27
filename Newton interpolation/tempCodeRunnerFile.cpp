#include<iostream>
using namespace std;
double *x;
double *y;
double findC(int x1 , int x0 , int i = 0){
    if(i == 0){
        return y[x0];
    }
    else if(i == 1){
        return (y[x1] - y[x0])/(x[x1] - x[x0]);
    }
    return ( findC(x1,x0,i-1) - findC(x1-1,x0,i-1) ) / (x[x1] - x[x0]);
}
int main(){
    int size , temp , result;
    x = new double[size];
    y = new double[size];
    int stdID = 40462;
    for (int i = 0; i < size; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> y[i];
    }
    for (int i = 0; i < size; i++)
    {
        temp = 1;
        for(int j = 0 ; j < i ; j++){
            temp *= (stdID - x[i]);
        }
        result += findC( i , 0 , i) * temp;
    }
    cout << "Result: " << result;
    
}