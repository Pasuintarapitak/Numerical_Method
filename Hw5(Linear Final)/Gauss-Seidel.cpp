#include<iostream>
using namespace std;
#define max_iter 100

int main(){
    int n;
    cout << "Matrix size: ";
    cin >> n; // size of matrix
    double a[n][n] ,x[n] ,x_old[n], b[n] ,p[n];
    double e[n];
    int count = 0;
    bool converged = false;
    
    //input Matrix A
    cout << "Input Matrix: "<<endl;
    for(int i = 0 ; i<n ; i++){
        for (int j = 0; j < n; j++)
        {
                cin >> a[i][j];
        }
    }
    // input B
    cout << "Input b: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    // x 's at start
    cout << "Input x(start): "<<endl;
    for(int i = 0; i <n ; i++){
        cin >> x[i];
         
    }

    //Gauss-Seidel method
    for(int r = 0 ; r <max_iter ; r++){

        for(int i = 0; i < n ; i++){
            p[i] = b[i];
            for(int j = 0 ; j < n ; j++){
                if( i == j){
                    continue;
                } 
                else{
                    p[i] -= a[i][j] * x[j];
                }
            }
            x_old[i] = x[i];
            x[i] = p[i]/a[i][i];
        }count++;

        //error
        converged = true;
        for(int l = 0; l < n ; l++){
            e[l] = abs((x[l] - x_old[l])/ x[l]);
            if(e[l] >= 0.000001){
                converged = false;
            }
        }
        if(converged){
            break;
        }

    }
    if(!converged){
        cout << "Disconverged" <<endl;
    }else{
        for (int i = 0; i < n; i++)
        {
            cout << "X"<<"["<<i<<"]" <<" : " << p[i]<<endl;
        }
        cout <<"Count : "<<count<<endl;;
    }

    return 0;
}