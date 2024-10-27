#include<iostream>
using namespace std;

int main(){
    int size;
    cin >> size;
    double x[size];
    double y[size];
    double value;
    double fx[size];
    for(int i = 0 ; i < size ; i++){
        cout << "x["<<i<<"] : ";
        cin >> x[i];
    }
    for(int i = 0 ; i < size ; i++){
        cout << "y["<<i<<"] : ";
        cin >> y[i];
    }
    cout << "X is at :";
    cin >> value;

    for (int i = 0; i < size; i++)
    {
        cout << y[i] << " ";
    }cout << endl;

    for(int index = 0 ; index < size-1 ; index++){

        fx[index] = y[index] + ((y[index+1] - y[index] ) / (x[index+1] - x[index]) )*(value - x[index]); 
            
    }

    for(int index = 0 ; index < size-1 ; index++){
        if(value >= x[index] && value <= x[index+1]){
            cout << fx[index] << endl; 
            break;
        }
    }
 

    return 0;
}