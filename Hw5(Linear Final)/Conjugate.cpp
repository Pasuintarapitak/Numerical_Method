#include<iostream>
using namespace std;
#define max_iter 100
void findResidual(double **a ,double **b , double **residual ,double **x ,int n){
    
}




int main(){
    int n;
    cout << "Matrix size: ";
    cin >> n; // size of matrix
    double** a = new double*[n];
    double** b = new double*[n];
    double** x = new double*[n];
    double** residual = new double*[n];
     for (int i = 0; i < n; i++) {
        a[i] = new double[n];
        b[i] = new double[n];
        x[i] = new double[n];
        residual[i] = new double[n];
    }
    double  x_old[n] ,p[n];
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
    
    







    return 0;
}