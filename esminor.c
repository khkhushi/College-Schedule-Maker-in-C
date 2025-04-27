#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int submat[7][100],teamat[7][100];
int size,size1,size2;
struct teacher
{
 char name[20];
 int avail ;
 char sub1[20], sub2[20];
 int sub1code;
 int sub2code;
 int teacode;
 int total_hours;
}t[100];

struct batches
{
 char name[100];
 char subject_current[20];
}b[100];

struct subject
{
 char subject_name[50];
 int subcode;
}s[100];
void display_students()
{
  int dee,khu,timeinc,i,j; 
  for(dee=0;dee<size;dee++)   
  {
      timeinc=9;
      printf("\n%s",b[dee].name);
      for(khu=0;khu<7;khu++)
      {   
          printf("\nTiming :- %d to %d",timeinc,timeinc+1);
          if((submat[khu][dee]>1000) && (submat[khu][dee]<1011)) 
          {
          printf("\nSubject code:-%d",submat[khu][dee]);
          for(i=0;i<size1;i++)
          {
           if(s[i].subcode==submat[khu][dee])
           {
             printf("\nSubject :-%s",s[i].subject_name);
             break;
           }
          }
          }
          else
          {
           printf("\n Break");
           timeinc++;
           continue;
          }
          if((teamat[khu][dee]>0) && (teamat[khu][dee]<11))
          {
          printf("\n Teacher code:-%d",teamat[khu][dee]);
          for(j=0;j<size2;j++)
          {
           if(t[j].teacode==teamat[khu][dee])
           {
             printf("\nTeacher Name:-%s",t[j].name);
             break;
           }
          }
         }
          
          
      //  printf("\t \t");
         timeinc++;
      }
      printf("\n");
  }
}
void display_teacher(int l)
{
 printf("\n The name of the teacher is %s ",t[--l].name);
 int inx,iny;
 for(iny=0;iny<size;iny++)
 {
  for(inx=0;inx<7;inx++)
  {
   if(t[l].teacode==teamat[inx][iny])
   {
    printf("\n Batch:- %s",b[iny].name);
    printf("\n Time:-%d to %d",inx+9,inx+10);
   }
   else
   {
     continue;
   }
  }
 }
}   


void calling_function()
{
 int f=0,i,j,k,f1=0,p,p1,x,av=0,arr[100],v;
 int choice=1,inx=0,iny=0,view,l,li;
 
 for(i=9;i<=15;i++) //timing
  {
      iny=0;
      for(x=0;x<size;x++)  //batches
      {
        U1: p1= rand()%size2;                  // srand(time(0));
      
       strcpy(b[x].subject_current,s[p1].subject_name);
       k= s[p1].subcode;
       for(j=0;j<size2;j++)
       {
      
       if((k==t[j].sub1code||k==t[j].sub2code) && t[j].avail==0)
       {
        if(i==13)
        {
         submat[inx][iny]=13;
         teamat[inx][iny]=13;
         continue;
        }
        printf("\n");
        int S,Z=0;
        S=inx;
        while(S>=0)
        {
          if(k==submat[--S][iny])
          {Z=1;

           break;
          }
        }
        if(Z==1)
        {
         goto U1;
        }
        submat[inx][iny]=k;
        teamat[inx][iny]=t[j].teacode;
        t[j].avail=1;
        t[j].total_hours++;
        arr[av]=j;
        av++;
        f=1;
        break;
        }
        else
        { continue;
           
        }
        if(j==9 && f==0)
        {
         goto U1;
        }
      
      }
      iny++;
         
    }
    for(v=0;v<av;v++)
    {
        t[v].avail=0;
    }
    printf("\n \n");
    inx++;
  }
 printf("You want the time table in 1.student view or 2.teacher view 3.None ");
 scanf("%d",&view);
 if(view==1)
 {
  display_students();  
 }
 if(view==2)
 {
  for(li=0;li<size2;li++)
         {
          printf("\n %d.%s",li+1,t[li].name);
         }
         scanf("%d",&l);
  display_teacher(l); 
 } 
}
  
 
int main()
{
 printf("\nEnter the number of batches you want time table for");
 scanf("%d",&size);
 printf("\nEnter the number of subjects you want time table for");
 scanf("%d",&size1);
 printf("\nEnter the number of teachers you want time table for");
 scanf("%d",&size2);
 FILE *fptr;
 int l;
 char input1[50];
 fptr=fopen("teacher_name.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size2;l++)
 {
  fscanf(fptr,"%s",input1);
  strcpy(t[l].name,input1);
 
 }
 fclose(fptr);

 fptr=fopen("teacher_sub1.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size2;l++)
 {
  fscanf(fptr,"%s",input1);
  strcpy(t[l].sub1,input1);
  //printf("\n %s",t[l].sub1);
 }
 fclose(fptr); 

fptr=fopen("teacher_sub2.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size2;l++)
 {
  fscanf(fptr,"%s",input1);
  strcpy(t[l].sub2,input1);
  //printf("\n %s",t[l].sub2);
 }
 fclose(fptr);

int input;
fptr=fopen("teacher_sub1_code.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size2;l++)
 {
  fscanf(fptr,"%d",&input);
  t[l].sub1code=input;
  //printf("\n %d",t[l].sub1code);
 }
 fclose(fptr);

fptr=fopen("teacher_sub2_code.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size2;l++)
 {
  fscanf(fptr,"%d",&input);
  t[l].sub2code=input;
 //  printf("\n %d",t[l].sub2code);
 }
 fclose(fptr);

fptr=fopen("teacher_code.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size2;l++)
 {
  fscanf(fptr,"%d",&input);
  t[l].teacode=input;
  //printf("\n %d",t[l].teacode);
 }
 fclose(fptr);

 for(l=0;l<size2;l++)
 {
  t[l].avail=0;
 }
 fptr=fopen("batch_name.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size;l++)
 {
  fscanf(fptr,"%s",input1);
  strcpy(b[l].name,input1);
  //printf("\n %s",b[l].name);
 }
 fclose(fptr);

fptr=fopen("subject_name.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size1;l++)
 {
  fscanf(fptr,"%s",input1);
  strcpy(s[l].subject_name,input1);
  //printf("\n %s",s[l].subject_name);
 }
 fclose(fptr);

fptr=fopen("subject_code.txt","r");
 if(fptr==NULL)
 {
  printf("ERROR");
 }
 for(l=0;l<size1;l++)
 {
  fscanf(fptr,"%d",&input);
  s[l].subcode=input;
  //printf("\n %d",s[l].subcode);
 }
 fclose(fptr);
 int f=0,i,j,k,f1=0,p,p1,x,av=0,arr[100],v;
 int choice=1,inx=0,iny=0;
 int khu, dee,week,choice2;
 printf("\n WELCOME TO TIMETABLE GENERATION");
 printf("\n Please select the operation you wish to perform");
 printf("\n1. View The time table for all the batches for monday");
 printf("\n2.View The time table for all the batches for tuesday");
 printf("\n3.View The time table for all the batches for wednesday");
 printf("\n4.View The time table for all the batches for thrusday");
 printf("\n5.View The time table for all the batches for friday");
 printf("\n6.View The time table for all the batches for all the day");
 printf("\n7.View the number of hours of a teacher"); 
 scanf("%d",&choice); 
   switch(choice)
  {
    case 1:
       calling_function();
       break;
    case 2:
        calling_function();
        break;
    case 3:
        calling_function();   
        break;
    case 4:
        calling_function();
        break;
    case 5:
        calling_function();  
        break;
    case 6:
         printf("\n For Monday:-");
         calling_function();
        // printf("\n \n");  
         printf("\n For Tuesday:-");
         calling_function();
        // printf("\n \n");  
         printf("\n For Wednesday:-");
         calling_function(); 
         //printf("\n \n");   
         printf("\n For Thrusday:-");
         calling_function();
         //printf("\n \n");  
         printf("\n For Friday:-");
         calling_function();
         //printf("\n \n");  
         break;
     case 7:
         printf("\n For Monday:-");
         calling_function();
        // printf("\n \n");
         printf("\n For Tuesday:-");
         calling_function();
        // printf("\n \n");
         printf("\n For Wednesday:-");
         calling_function();
         //printf("\n \n");
         printf("\n For Thrusday:-");
         calling_function();
         //printf("\n \n");
         printf("\n For Friday:-");
         calling_function();
         //printf("\n \n");
         printf("\nSelect the teacher you wish to see their no of hours");
         for(i=0;i<10;i++)
         {
          printf("\n %d.%s",i+1,t[i].name); 
         }
         scanf("%d",&choice2);
         printf("\nThe No of hours of that given teacher is %d",t[choice2].total_hours);
         break;
         
    default:
        printf("SORRY THIS CHOICE IS NOT AVAILABLE");
        break;
 }
 return 0;
}
