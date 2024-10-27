#include<iostream>
using namespace std;
void luDecompostion(double m[3][4]){
    double A[3][3] = {
        {m[0][0],m[0][1],m[0][2]},
        {m[1][0],m[1][1],m[1][2]},
        {m[2][0],m[2][1],m[2][2]}
    };
    // Find L and U
    double l_11 = m[0][0];
    double u_12 = m[0][1] / l_11;
    double u_13 = m[0][2] / l_11;
    double l_21 = m[1][0];
    double l_22 = m[1][1] - l_21*u_12;
    double u_23 = (m[1][2] - l_21*u_13)/l_22;
    double l_31 = m[2][0];
    double l_32 = m[2][1] - l_31*u_12;
    double l_33 = m[2][2] - l_31*u_13 - l_32*u_23;

    double L[3][3] = {
        {l_11 , 0 , 0},
        {l_21 , l_22 , 0},
        {l_31 , l_32 , l_33}
    };
    double U[3][3]={
        {1 , u_12 , u_13},
        {0 , 1 , u_23 },
        {0 , 0 , 1 }

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
    double x3 =y3 / U[2][2]  ;
    double x2 = ( y2 - U[1][2]*x3 )/ U[1][1];
    double x1 = (y1 - U[0][2]*x3 - U[0][1]*x2 )/ U[0][0];
    cout <<"x1 : "<<x1<<endl;
    cout <<"x2 : "<<x2<<endl;
    cout <<"x3 : "<<x3<<endl;

}
int main(){
    double m[3][4]={
        {-2 , 3 , 1 , 9},
        {3 , 4 , -5 , 0},
        {1 , -2 , 1 , -4}
    };
    luDecompostion(m);
    return 0;
}