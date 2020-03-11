#include <iostream>
#include <math.h>
#define g 9.81
#include <algorithm>
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

    }
    

/* Designing of extra widening */

double wm,wps,b,l;
int n;
double v=vel/3.6;
cout<<"Enter the width of the horizontal curve(in meters): ";
cin>>b;
cout<<"Enter the length of wheel base (in meters): ";
cin>>l;
cout<<"Enter the no. of lanes the curve is designed for: ";
cin>>n;
/*mechanical widening is given by*/

wm=l*l/(2*R_rul);
cout<< "The extra mechanical widening is given by: "<<wm<<" meters"<<endl;

/*psychological widening is given by*/

wps= v/(9.5*sqrt(R_rul));
cout<<"The extra psychological widening is given by: "<<wps<<" metres"<<endl;

/* total extra width */

cout<<"The total extra width to be accounted = "<<wm+wps<< " meters"<<endl;
cout<< "Hence total width of horizontal curve ="<<b+wm+wps<<" meters"<<endl;



/*Designing of Transition Curves*/

//accounting reaction time of driver =2.5 sec;
//taking N=150 which is minimum value 
int x;

cout<<"for superelevation about centerline enter 1 or for superelevation about inner edge enter 0 : ";
cin>>x;
double ca,ls1,ls2,ls3,ls,s;

// designing ls1 due to centrifugal force

ca=80/(75+vel);
ls1=v*v*v/(R_rul*ca);

// designing ls2 due to rate of introduction of superelevation

int N;
N=150;

if(x==1 || x==0){
		
		ls2=e*N*(b+wps+wm)/2;
		if(x!=1){
				ls2=ls2/2;
				}
		

}
else{
		cout<<"Wrong input"<<endl;
}
 
// designing ls3 due to minimun length of transition curve 

cout<<"for mountaneous and steep terrain enter 0 and for plain and rolling terrain enter 1: ";
cin>>x;
if(x==1){
	ls3=2.7*vel*vel/R_rul;
}
else if (x==0){
	ls3=vel*vel/R_rul;
}
else{
	cout<< "Wrong input"<<endl;
}


//final length of transition curve 

ls= std::min(ls1,ls2);
ls= std::min(ls,ls3);

cout<<"The length of the transition curve is: "<< ls<<" meters"<<endl;

}

/* Designing of shift of Transition curve*/
/*
s=ls*ls/(24*R_rul);
cout<<"The shift in Transition curve is: "<<s<<" meters";*/
