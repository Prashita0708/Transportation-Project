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

// stopping sight distance
cout<<"Assuming the reaction time of driver to be 2.5 sec and frition between road and tyres as per indian standards be 0.15"<<endl;
double ssd;
double f = 0.15, t = 2.5;
ssd = vel*t + ((vel*vel)/(f*g));
cout<<"stopping sight distance is "<<ssd<<" meters"<<endl;

// overtaking sight distance







// space for osd


// designing of vertical curve
cout<<"Firtly we need to know the elevation of ascending and descending gradient, since it primarilary describes our vertical curve"<<endl;
cout<<"Note : Gradients are to be mentioned with signs. Positive sign indicates ascending gradient and negative sign indicates descending gradient"<<endl;

double n1,n2
cin>>n1;
cin>>n2;

double N = n1 - n2;
 
/* if N is positive then our vertical curve is designed as summit curve and if N is negative then it is designed as valley curve*/
/*The only problem in designing of vertical curves is to provide an adequate sight distance*/

if(N > 0)
{
// "Determining the length of vertical curve for stopping sight distance"
cout<<"As per indian standards, assuming height of driver's eye level to be 1.2 m and height of obstacle to be 0.15 m"<<endl;	

double LOVC1 = 0;

	LOVC1 = 2*SSD - (4.4/N);
	if(LOVC1 > SSD)
	{
		LOVC1 = N*S*S/4.4;
	}
	else
	{
		LOVC1 = LOVC1;
	}
	
	cout<<"Length of vertical curve i.e; summit curve for safety against stopping sight distance is "<<LOVC1<< "" meters""<<endl;

// "Dtermining the length of vertical curve for overtaking sight distance"
	
double LOVC2 = 0;
	
	LOVC2 = 2*OSD - (9.6/N);
	if(LOVC2 > OSD)
	{
		LOVC2 = N*S*S/9.6;
	}
	else
	{
		LOVC2 = LOVC2;
	}
	
	cout<<"Length of vertical curve i.e; summit curve for safety against overtaking sight distance is "<<LOVC2<< "" meters""<<endl;
}
else
{
	// Length of vertical curve or valley cuvre for head light sight distance 
cout<<"As per indian standards, assuming the allowable rate of change of centrifugal accleration be 0.06 m/sec^2, average heigth of head be 0.75 m and beam angle be 1 degree"<<endl;
	
	double C = 0.06;
	double LOVC = 0,L1,L2;
	
	L1 = 2*sqrt(N*v*v*v/C);
	
	L2 = 2*SSD - ((1.5 + 0.035*SSD)/N);
	if(L2 > SSD)
	{
		L2 = (N*S*S/(1.5 + 0.035*SSD));
	}
	else
	{
		L2 = L2;
	}	
	
	LOVC = std::max(L1,L2);
		
	cout<<"Length of vertical curve i.e; valley curve for safety against head light sight distance is "<<LOVC<< "" meters""<<endl;	
}	
