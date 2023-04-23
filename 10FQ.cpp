#include <stdio.h>

struct shape{
	double height;
	double radius;
	double areacylinder;
};

int main(){
	long long int t;
	struct shape s;
	double pi = 3.14;
	
	scanf("%lld",&t);
	for(int i = 1; i <= t; i++){
		scanf("%lf %lf", &s.radius, &s.height);
		
		//area cylinder
		s.areacylinder = (double)2*pi*s.radius*(s.radius+s.height);
		printf("Case #%lld: %.2lf\n", i,s.areacylinder);
	}
		
	return 0;
}
//#include <stdio.h>
//
//struct shape{
//	float height;
//	float radius;
//	float areacircle;
//	float areacylinder;
//};
//
//int main(){
//	int t;
//	struct shape s;
//	float pi = 3.14;
//	
//	scanf("%d",&t);
//	for(int i = 1; i <= t; i++){
//		scanf("%f %f", &s.radius, &s.height);
//		//area od circle
//		s.areacircle = pi*s.radius*s.radius;
//		//area cylinder
//		s.areacylinder = (float)2*pi*s.radius*s.height + 2 * s.areacircle;
//		printf("Case #%d: %.2f\n", i,s.areacylinder);
//	}
//		
//	return 0;
//}

