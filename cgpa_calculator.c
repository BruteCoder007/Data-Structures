#include"stdio.h"
#include "stdlib.h"
int n;
int subjects_credit[15];
char subjects[15];
float credits[15],cgpa;
void getdetail()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the grade\ncapital for '+' grades:");
        scanf("%s",&subjects[i]);
        printf("\nenter the credit of the subject:");
        scanf("%f",&credits[i]);
    }
}
void grade_point()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(subjects[i]=='o')
           subjects_credit[i]=10;
        else if(subjects[i]=='A')
           subjects_credit[i]=9;
        else if(subjects[i]=='a')
           subjects_credit[i]=8;
        else if(subjects[i]=='B')
           subjects_credit[i]=7;
        else if(subjects[i]=='b')
           subjects_credit[i]=6;
        else
        {
            printf("sorry! you have an arrear\n");
            exit(0);
        }
    }
}
void calculator()
{
    int i;
    float sumofcredits=0;
    cgpa=0.0;
    for(i=0;i<n;i++)
    {
        cgpa+=subjects_credit[i]*credits[i];
        sumofcredits+=credits[i];
    }
    printf("%f\n",cgpa);
    printf("%f\n",sumofcredits);
    cgpa/=sumofcredits;
    printf("congradulations! you have got a good result:\n");
    printf("your cgpa:%f\n",cgpa);
}
int main()
{
    printf("enter the number of subjects:\n");
    scanf("%d",&n);
    getdetail();
    grade_point();
    calculator();
    return 0;    
}