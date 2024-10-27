#include<iostream>
#include<cmath>
using namespace std;
void choleskyDecom(double m[3][4]){
    double A[3][3] = {
        {m[0][0],m[0][1],m[0][2]},
        {m[1][0],m[1][1],m[1][2]},
        {m[2][0],m[2][1],m[2][2]}
    };
    // Find L
    double l_11 = sqrt(m[0][0]);
    double l_21 = m[0][1] / l_11;
    double l_31 = m[0][2] / l_11;
    double l_22 = sqrt(m[1][1] - pow(l_21,2));
    double l_32 = (m[2][1] - l_21*l_31)/l_22;
    double l_33 = sqrt(m[2][2] - pow(l_31,2) - pow(l_32,2));


    double L[3][3] = {
        {l_11 , 0 , 0},
        {l_21 , l_22 , 0},
        {l_31 , l_32 , l_33}
    };
    double LT[3][3]={
        { l_11, l_21  , l_31},
        { 0, l_22 , l_32 },
        { 0 , 0  , l_33  }

    };
    //find Y --> LY = B
    double B[3][1] = { {m[0][3]},{m[1][3]},{m[2][3]} };
    double y1 = B[0][0] / L[0][0];
    double y2 = (B[1][0] - l_21*y1) / l_22;
    double y3 = (B[2][0] - l_31*y1 - l_32*y2)/l_33;
    cout <<"y1 : "<<y1<<endl;
    cout <<"y2 : "<<y2<<endl;
    cout <<"y3 : "<<y3<<endl;

    //find x --> Ux = Y
    double x3 =y3 / LT[2][2]  ;
    double x2 = ( y2 - LT[1][2]*x3 )/ LT[1][1];
    double x1 = (y1 - LT[0][2]*x3 - LT[0][1]*x2 )/ LT[0][0];
    cout <<"x1 : "<<x1<<endl;
    cout <<"x2 : "<<x2<<endl;
    cout <<"x3 : "<<x3<<endl;

}
int main(){
    double m[3][4]={
        {4 , 3 , 1 , 3125},
        {3 , 5 , 2 , 3650},
        {1 , 2 , 6 , 2800}
    };
    choleskyDecom(m);
    return 0;
}