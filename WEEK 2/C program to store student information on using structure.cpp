#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct students{
	char name[21];
	char roll[11];
	char enroll[11];
};
typedef struct students stu;
main(){
	stu *s;
	char name[21],n,i;
	printf("Enter number of students: ");
	scanf("%d",&n);
	fflush(stdin);
	s=(stu*)malloc(n*sizeof(stu));
	for(i=0;i<n;i++){
		printf("DETAILS OS STUDENT-%d\n",i+1);
		printf("Enter Name:");
		gets(s[i].name);
		printf("Enter roll no:");
		gets(s[i].roll);
		printf("Enter Enrollment No:");
		gets(s[i].enroll);
	}
	for (i=0;i<n;i++){
		printf("\t%s\t%s\t%s",s[i].name,s[i].roll,s[i].enroll);
	}
	free(s);
}
