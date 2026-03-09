#include<stdio.h>
struct time{
	int hours;
	int minutes;
	int seconds;
};
struct time diffrencetime(struct time t1,struct time t2){
	struct time diff;
	if(t2.seconds>t1.seconds){
		t1.minutes--;
			t1.seconds+=60;
	}
	diff.seconds=t1.seconds-t2.seconds;
	if(t2.minutes>t1.minutes){
		t1.hours--;
		t1.minutes+=60;
	}
	diff.minutes=t1.minutes-t2.minutes;
	diff.hours=t1.hours-t2.hours;
	return diff;
}
int main(){
	struct time starttime,endtime,diff;
	printf("Enter Start Time(in hours minutes seconds):");
	scanf("%d%d%d",&starttime.hours,&starttime.minutes,&starttime.seconds);
    printf("Enter End Time(in hours minutes seconds):");
	scanf("%d%d%d",&endtime.hours,&endtime.minutes,&endtime.seconds);
	diff=diffrencetime(starttime,endtime);
	printf("\nTime Diffrence: %d:%d:%d",diff.hours,diff.minutes,diff.seconds);	
	return 0;
}
