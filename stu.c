//emcc stu.c -s WASM=1 -O3 -s "EXPORTED_FUNCTIONS=['_main']" -o stu.js -o stu.html
//sample inputs : 1 1 101 lenin 98 95 74 2 101 1 1 102 kumar 67 45 76 2 101 2 102 3 2 102  
#include<stdio.h>
#include<string.h>
#include <emscripten.h>
struct student
 { 
  	int rollno,tot;
  	char name[20],grade;
  	int mark[20][3];
  	float per;
 }s[20];

EMSCRIPTEN_KEEPALIVE int  valid(char uname[20],char pword[20])
{
   int x;
   if(strcmp(uname,"admin"))
   {
      if(strcmp(pword,"admin"))
      {
           x=1;
       }
   }
   else
  {
     x=0;
   }
  return x;
} 

EMSCRIPTEN_KEEPALIVE int  add(int no,int nos,int rno,char name[20],int marks[3])
{
 int n,ns,i,j;
  n=no;
  ns=nos;
 for(i=ns;i<n+ns;i++)
	{
		s[i].rollno=rno;
		strcpy(s[i].name,name);		
		for(j=0;j<3;j++)
		{                
			
			s[i].mark[i][j]=marks[j];
			s[i].tot += s[i].mark[i][j]; 
		}
		s[i].per=s[i].tot/3;
		if(s[i].per<=100 && s[i].per>90)
		{
			s[i].grade='S';
		}
		else if(s[i].per<90 && s[i].per>80)
		{
			s[i].grade='A';			
		}
		else  if(s[i].per<=80 && s[i].per>70)
		{
			s[i].grade='B';
		}
		else if(s[i].per<=70 && s[i].per>60)
		{
			s[i].grade='C';
		}
		else if(s[i].per<=60 && s[i].per>=50)
		{
			s[i].grade='D';	
		}
		else
		{
			s[i].grade='F';
		}		
	}
	ns+=n;
	return ns;
   }
   EMSCRIPTEN_KEEPALIVE void view(int nos,int r)
   {
	int rno,check,i,ns;
	ns=nos;
	rno= r;
	check=0;
	for(i=0;i<ns;i++)
	{
	   if(rno==s[i].rollno)
	  {
	  	printf("\tRollno : %d\n\tName : %s\n\tTotal Marks : %d\n\tPercentage:%.2f\n\tGrade : %c\n",s[i].rollno,s[i].name,s[i].tot,s[i].per,s[i].grade);
		check=1;
	   }  	
	}
	if(check==0){printf("\nNo such a Student.....\n");}
}
 