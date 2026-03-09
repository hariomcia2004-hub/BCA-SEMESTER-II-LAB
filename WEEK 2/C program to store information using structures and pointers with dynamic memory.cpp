#include<stdio.h>
struct playerdata{
	char name[21];
	int runs[11];
	int jerseyno[4];
};
typedef struct playerdata pd;
main(){
	pd*p;
	int i,n;
	printf("Enter no of players:");
	scanf("%d",&n);
	fflush(stdin);
	p=(pd*)malloc(n*sizeof(pd));
	for(i=0;i<n;i++){
		printf("Enter Player-%d details:\n",i+1);
		printf("Enter Name:");
		gets(pd[i].name);
		printf("Enter Runns:");
		scanf("%d",&pd[i].runs);
		printf("Enter Jersey Number:");
		scanf("%d",&pd[i].jerseyno);		
	}
}
