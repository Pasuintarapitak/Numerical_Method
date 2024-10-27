// 2.2
#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
int main(){
    double x , n;
    cin >>x;
    cin>>n;
    double xL = 0 , xR = 1000000 , xM = 0 ,xM_old = 0,xM_new = 0 ,fxR , fxM , e;
    cout << setprecision(4) << fixed;
    for(int i = 1 ; i <= 100 ;i++){
        xM = (xL + xR) / 2.0;
        fxR = pow(xR,1/n); fxM = pow(xM,1/n);
        // cout << "i = "<<i<<"  ->  "<< "xL = "<<xL<<" xR = "<<xR<<" xM = "<<xM<<endl;
        xM_old = xM_new;
        if(fxR * fxM > 0){
            xR = xM;
            xM_new = xM;
        }
        else{
            xL = xM;
            xM_new = xM;
        }
        cout <<xM<<endl;
        if(i > 1){
            e = (xM_new - xM_old)/xM_new ;
            cout<<" Error = "<<fabs(e)<<endl;
        }
    }
    return 0;
}

