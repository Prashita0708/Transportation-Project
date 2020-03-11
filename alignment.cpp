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
    if(c=='Y'||c=='y'){ //Ask weather to provide R_rul or not
        cout << "Give the R_rul (in meters):";
        cin >> R_rul;
    }
    else{
        R_rul = (vel*vel)/27.94; //Calculating R_rul if not provided
    }
    cout << "R_rul = " << R_rul << " m" << endl;
    double e=0,f=0;
    if((e = (vel*vel)/(225*R_rul))>0.07){ //Calculating the value of e with the given parameters
        if((f = (vel*vel)/(127*R_rul) - 0.07 ) > 0.15){ //Calculating the value of f with the given parameters if e value exceeds 0.07
            cout << "Velocity exceeds the allowable speed (" << sqrt(0.22*g*R_rul) << " m/s)" << endl;
        }
        else
        {
            cout << "Velocity is safe" << endl;
            cout << "e = "<< e << endl;
            cout << "f = " << f << endl;
        }
        
    }
    else
    {
        cout << "Velocity is safe" << endl;
        cout << "e = "<< e << endl;
        cout << "f = " << f << endl;
    }
    


}
