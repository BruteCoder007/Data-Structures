#include<iostream>
#include<cmath>
using namespace std;
void eqnsolver(int ,int ,int,float&,float&);
int main()
{ 
    int a,b,c;
    float x1=0,x2=0;
	cout<<"enter the coefficient of x^2:\n";
	cin>>a;
	cout<<"enter the coefficent x:\n";
	cin>>b;
	cout<<"enter the constant:\n";
	cin>>c;
	cout<<"the equation is:";
	cout<<a<<"x^2+"<<b<<"x+"<<c<<"\n";
	eqnsolver(a,b,c,x1,x2);
	cout<<"the solution is:\n";
	cout<<"x="<<x1<<"\t x="<<x2;
	return 0;
}
void eqnsolver(int a,int b,int c,float& x1,float& x2 )
{
	x1=-b+sqrt(b*b-4*a*c)/2*a;
	x2=-b-sqrt(b*b-4*a*c)/2*a;
	
}
