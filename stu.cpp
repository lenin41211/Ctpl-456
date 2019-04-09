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

extern "C" EMSCRIPTEN_KEEPALIVE int valid(char* p,char* u)
        {
            return strcmp(p,u);
        }


extern "C" EMSCRIPTEN_KEEPALIVE char* add(int rno,char* name,int m1,int m2,int m3)
{
		char * c;
 		s[ns].rollno=rno;
		strcpy(s[ns].name,name);		
		s[ns].tot = m1+m2+m3; 
		s[ns].per=s[ns].tot/3;
		if(s[ns].per<=100 && s[ns].per>90)
		{
			c="S";
		}
		else if(s[ns].per<90 && s[ns].per>80)
		{
			c="A";			
		}
		else  if(s[ns].per<=80 && s[ns].per>70)
		{
			c="B";
		}
		else if(s[ns].per<=70 && s[ns].per>60)
		{
			c="C";
		}
		else if(s[ns].per<=60 && s[ns].per>=50)
		{
			c="D";	
		}
		else
		{
			c="F";
		}		
	
	ns=ns+1;
	return c;
   }
 extern "C" EMSCRIPTEN_KEEPALIVE int view(int r)
   {
	
	return ns;
   }
