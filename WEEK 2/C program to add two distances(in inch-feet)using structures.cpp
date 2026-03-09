#include<stdio.h>
struct distance{
	int feet;
	int inch;
};
typedef struct distance dist;
main(){
	dist d1,d2,res;
	printf("Enter Distance-1:\n");
	printf("Enter feet and inch:");
	scanf("%d%d",&d1.feet,&d1.inch);
	printf("Enter Distance-2:\n");
	printf("Enter feet and inch:");
	scanf("%d%d",&d2.feet,&d2.inch);
	res.feet=d1.feet+d2.feet;
	res.inch=d1.inch+d2.inch;
	if(res.inch>=12){
		res.feet+=res.inch/12;
		res.inch=res.inch%12;
	}
	printf("Resultant Distance:\n");
	printf("%d feet %d inch",res.feet,res.inch);
}
