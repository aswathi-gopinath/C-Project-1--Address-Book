#include<stdio.h>
#include<string.h>
#include "myheader.h"
void create_contact(struct address_book *s)
{
    char str1[50], str2[11], str3[100];
    int valid,i;
    
    printf("Enter the name\n");
    while(1)
    {
        scanf(" %[^\n]", str1);
        valid = name(str1);      //validate the entered name
        if(valid)
        {
            strcpy(s->arr[s->count].name, str1);
            break;
        }
        else
        {
             printf("Invalid format. Try again\n");
        }
    }
    
     printf("Enter the mobile number\n");
    while(1)
    {
        scanf(" %[^\n]", str2);
        valid = mobile(str2);       //validate the entered mobile number
        if(valid)
        {
           int flag1=0;
            for(i=0;i<s->count;i++)
            {
                if(!(strcmp(str2,s->arr[i].mobile)))
                {
                    printf("Number already exist. Enter the correct number\n");   //chexk if its already taken
                    flag1=1;

                }
            }

              if(flag1==0) 
              {
                   strcpy(s->arr[s->count].mobile, str2);
                    break;
              }    
        }
         else
        {
             printf("Invalid format. Try again\n");
        }
    }
    printf("Enter the mail address\n");
    while(1)
    {
        scanf(" %[^\n]", str3);
        valid = mail(str3);       //validate the entered mail address
        if(valid)
        {
            int flag=0;
            for(i=0;i<s->count;i++)
            {
                if(!(strcmp(str3,s->arr[i].mail)))
                {
                    printf("Mail id already taken. Try another\n");   //chexk if its already taken
                    flag=1;

                }
            }

              if(flag==0) 
              {
                   strcpy(s->arr[s->count].mail, str3);
                    printf("Contact saved succesfully\n");
                    s->count++;
                    break;
              }    
        }
         else
        {
             printf("Invalid format. Try again\n");
        }
    }
    

}