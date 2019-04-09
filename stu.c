#include<stdio.h>
#include<string.h>
#include <emscripten.h>
int ns=0;
struct student
 { 
  	int rollno,tot;
  	char name[20],grade;
  	//int mark[20][3];
  	float per;
 }s[20];

extern "C" int valid(char* p,char* u)
        {
            return strcmp(p,u);
        }



EMSCRIPTEN_KEEPALIVE int  add(int rno,char* name,int m1,int m2,int m3)
{
 		s[ns].rollno=rno;
		strcpy(s[ns].name,name);		
		s[ns].tot = m1+m2+m3; 
		s[ns].per=s[ns].tot/3;
		if(s[ns].per<=100 && s[ns].per>90)
		{
			s[ns].grade='S';
		}
		else if(s[ns].per<90 && s[ns].per>80)
		{
			s[ns].grade='A';			
		}
		else  if(s[ns].per<=80 && s[ns].per>70)
		{
			s[ns].grade='B';
		}
		else if(s[ns].per<=70 && s[ns].per>60)
		{
			s[ns].grade='C';
		}
		else if(s[ns].per<=60 && s[ns].per>=50)
		{
			s[ns].grade='D';	
		}
		else
		{
			s[ns].grade='F';
		}		
	
	ns=ns+1;
	return ns;
   }
   EMSCRIPTEN_KEEPALIVE char* view(int r)
   {
	int rno,i,tot=0;
	rno= r;
	
	//res[0][0]=0;
	for(i=0;i<ns;i++)
	{
	   if(rno==s[i].rollno)
	  {
	  	printf("\tRollno : %d\n\tName : %s\n\tTotal Marks : %d\n\tPercentage:%.2f\n\tGrade : %c\n",s[i].rollno,s[i].name,s[i].tot,s[i].per,s[i].grade);
		/*res[0][0]=1;
		res[1][0]=s[i].rollno;
		strcpy(res[2][0],s[i].name);
		res[3][0]=s[i].tot;
		res[4][0]=s[i].grade;*/
		tot=i;
	   }  	
	}
	return s[tot].name;
}
