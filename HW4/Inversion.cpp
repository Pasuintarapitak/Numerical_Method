#include<iostream>
using namespace std;
void Inversion(double m[3][6]){
    double temp_10 = m[1][0];
    double temp_20 = m[2][0];
    // กำจัด (1,0) และ (2,0)
    // ด้านล่าง
    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 6; j++)
        {
            if(i == 1){
                m[1][j] -=  (temp_10* (m[i-1][j] / m[0][0]));
                
            }
            else if(i == 2){
                m[2][j] -=  (temp_20 * (m[i-2][j] / m[0][0]));
            }
            else{
                continue;
            }
        }
    }
    double temp_21 = m[2][1];
    // กำจัด (2,1)
    for (int j = 1; j < 6; j++)
    {
        m[2][j] -=  (temp_21 * (m[1][j] / m[1][1]));
    }
        
    
    
   // ด้านบน
    double temp_12 = m[1][2];
    double temp_02 = m[0][2];
    for (int i = 1 ; i >= 0 ; i--){
        for (int j = 0; j < 6; j++)
        {
            if(i == 1){
                m[1][j] -= (temp_12*(m[i+1][j] / m[2][2]));
            }
            else if(i == 0){
                m[0][j] -= (temp_02*(m[i+2][j] / m[2][2]));
            }
        }
        
    }

    double temp_01 = m[0][1];
    for (int i = 0; i < 6; i++)
    {
        m[0][i] -= (temp_01*(m[1][i] / m[1][1]));
    }
    
    for (int i = 0; i < 3; i++)
    {
        double temp = m[i][i];
        for (int j  = 0; j < 6; j++)
        {
            m[i][j] = m[i][j] /temp;
        }
        
    }
    // for (int i = 0; i < 3; i++)
    //     {
    //     for (int j  = 0; j < 6; j++)
    //     {
    //             cout<< m[i][j]<<" ";
    //     }cout << endl;
        
    // }
    double A_inverse[3][3] = {
        {m[0][3] , m[0][4] , m[0][5]},
        {m[1][3] , m[1][4] , m[1][5]},
        {m[2][3] , m[2][4] , m[2][5]}
    };
    double B[3][1] = {{9},{0},{-4}};
    cout<< "x1 : "<< A_inverse[0][0]*B[0][0] + A_inverse[0][1]*B[1][0] + A_inverse[0][2]*B[2][0] <<endl;
    cout<< "x2 : "<< A_inverse[1][0]*B[0][0] + A_inverse[1][1]*B[1][0] + A_inverse[1][2]*B[2][0] <<endl;
    cout<< "x3 : "<< A_inverse[2][0]*B[0][0] + A_inverse[2][1]*B[1][0] + A_inverse[2][2]*B[2][0] <<endl;
    
}
int main(){
    double m[3][6] = {
        {-2 , 3 , 1 , 1 , 0 , 0},
        {3 , 4 , -5 , 0 , 1 , 0},
        {1 , -2 , 1 , 0 , 0 , 1}
    };
    Inversion(m);

    return 0;
}