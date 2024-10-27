#include<iostream>
using namespace std;
void GaussJordan(double m[3][4]){
    double temp_10 = m[1][0];
    double temp_20 = m[2][0];
    // กำจัด (1,0) และ (2,0)
    // ด้านล่าง
    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 4; j++)
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
    for (int j = 1; j < 4; j++)
    {
        m[2][j] -=  (temp_21 * (m[1][j] / m[1][1]));
    }
        
    
    
    // ด้านบน
    double temp_12 = m[1][2];
    double temp_02 = m[0][2];
    for (int i = 1 ; i >= 0 ; i--){
        for (int j = 0; j < 4; j++)
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
    for (int i = 0; i < 4; i++)
    {
        m[0][i] -= (temp_01*(m[1][i] / m[1][1]));
    }
    
    for (int i = 0; i < 3; i++)
    {
        double temp = m[i][i];
        for (int j  = 0; j < 4; j++)
        {
            m[i][j] = m[i][j] /temp;
        }
        
    }
    // for (int i = 0; i < 3; i++)
    //     {
    //     for (int j  = 0; j < 4; j++)
    //     {
    //             cout<< m[i][j]<<" ";
    //     }cout << endl;
        
    // }
    double x3 = m[2][3] / m[2][2];
    double x2 = (m[1][3] - m[1][2]*x3)/ m[1][1];
    double x1 = (m[0][3] - m[0][1]*x2 - m[0][2]*x3 ) / m[0][0];
    cout<< "x1 : "<< m[0][3] <<endl;
    cout<< "x2 : "<< m[1][3] <<endl;
    cout<< "x3 : "<< m[2][3] <<endl;
    
}
int main(){
    double m[3][4] = {
        {-2 , 3 , 1 , 9},
        {3 , 4 , -5 , 0},
        {1 , -2 , 1 , -4}
    };
    GaussJordan(m);

    return 0;
}