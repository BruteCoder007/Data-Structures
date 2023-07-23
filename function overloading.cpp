#include<iostream>
using namespace std;
float volume (float radius)
{
float volume=1.33*3.14*radius*radius*radius;
return volume;
}
float volume(int radius,int height)
{
float volume=0.33*3.14*radius*radius*height;
return volume;
}
float volume( int side)
{
float volume=side*side*side;
return volume;
}
float volume(float radius,int height)
{
float volume=3.14*radius*radius*height;
return volume;
}
int main()
{
	float volume_sphere,volume_cylinder,volume_cone;
	float volume_cube;
	volume_sphere=volume(1.5f);
	volume_cone=volume(1,2);
	volume_cube=volume(1);
	volume_cylinder=volume(1.5f,5);
	cout<<"volume of the sphere:"<<volume_sphere<<"\n";
	cout<<"volume of the cylinder:"<<volume_cylinder<<"\n";
	cout<<"volume of the cube:"<<volume_cube<<"\n";
	cout<<"volume of the cone:"<<volume_cone<<"\n";
	return 0;
}
