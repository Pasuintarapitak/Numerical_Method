#include<iostream>
using namespace std;
double findDet(double m[3][3]){
    double lower = ( (m[0][0] * m[1][1] * m[2][2] ) + (m[0][1]*m[1][2]*m[2][0]) + (m[0][2]*m[1][0]*m[2][1]) );
    double upper = ( (m[2][0] * m[1][1] * m[0][2] ) + (m[2][1]*m[1][2]*m[0][0]) + (m[2][2]*m[1][0]*m[0][1]) );
    return lower-upper;
}
void cramerFunc(double m[3][4]){

    double mA[3][3] = { {m[0][0] , m[0][1] , m[0][2]}, 
                        {m[1][0] , m[1][1] , m[1][2]} , 
                        {m[2][0] , m[2][1] , m[2][2]}};
    
    double a1[3][3] = { {m[0][3] , m[0][1] , m[0][2]}, 
                        {m[1][3] , m[1][1] , m[1][2]} , 
                        {m[2][3] , m[2][1] , m[2][2]}};

    double a2[3][3] = { {m[0][0] , m[0][3] , m[0][2]}, 
                        {m[1][0] , m[1][3] , m[1][2]} , 
                        {m[2][0] , m[2][3] , m[2][2]}};

    double a3[3][3] = { {m[0][0] , m[0][1] , m[0][3]}, 
                        {m[1][0] , m[1][1] , m[1][3]} , 
                        {m[2][0] , m[2][1] , m[2][3]}};

    double detA = findDet(mA);;    
    double det_a1 = findDet(a1);
    double det_a2 = findDet(a2);
    double det_a3 = findDet(a3);
    
    if(detA != 0){
        cout << "x1: "<< det_a1/detA<<endl;
        cout << "x2: "<< det_a2/detA<<endl;
        cout << "x3: "<< det_a3/detA<<endl;
    }
    else{
        cout << "Can't find because detA = 0";
    }

}
int main(){
    double m[3][4] = {
        {-2 , 3 , 1 , 9},
        {3 , 4 , -5 , 0},
        {1 , -2 , 1 , -4}
    };
    cramerFunc(m);

    return 0;
}


