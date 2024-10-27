#include<iostream>
using namespace std;
double findL(double value , double x[] , int size , int index ){
    double divisor = 1, dividend = 1;

    for(int i = 0 ; i < size ; i++){
        if(i == index)
            continue;
        dividend *= x[i] - value;
        divisor *= x[i] - x[index];
    }
    return dividend/divisor;
}
int main(){
    int size;
    cin >> size;
    double x[size];
    double y[size];
    double value;
    double total;
    
    for (int i = 0; i < size; i++)
    {
        cout << "x ["<<i<<"] :";
        cin >> x[i];
    }
    for (int j = 0; j < size; j++)
    {
        cout << "y ["<<j<<"] :";
        cin >> y[j];
    }
    cout << "X is at : ";
    cin >> value;

    for(int index = 0 ; index < size ; index++){
        total += findL(value,x,size,index) * y[index];
    }
    cout << total <<endl;

    return 0;
}