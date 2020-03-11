#include <iostream>
#include <math.h>
#define g 9.81
using namespace std;

int main(){
    double vel;
    cout << "Give the velocity in km/hr: ";
    cin >> vel;
    cout << "Do you want to provide R_rul(Y/N):";
    char c;
    cin >> c;
    double R_rul ;
    if(c=='Y'||c=='y'){
        cout << "Give the R_rul (in meters):";
        cin >> R_rul;
    }
    else{
        R_rul = (vel*vel)/27.94;
    }
    cout << "R_rul = " << R_rul << endl;
    double e,f;
    if((e = (vel*vel)/(225*R_rul))>0.07){
        if((f = (vel*vel)/(127*R_rul) - 0.07 ) > 0.15){
            cout << "Allowable speed = " << sqrt(0.22*g*R_rul) << endl;
        }
        else
        {
            cout << "Velocity is safe" << endl;
        }
        
    }
    else
    {
        cout << "Velocity is safe" << endl;
    }
    


}