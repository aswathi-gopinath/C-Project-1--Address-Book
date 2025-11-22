#include<stdio.h>
#include "myheader.h"
#include<string.h>
int search_contact(struct address_book *s)
{
    int choice,i,flag,j,temp;
    char str1[50], str2[11], str3[100];
    printf("           ---------------------SEARCH MENU------------------                          \n");
    printf("1. Search by name\n");
    printf("2. Search by mobile number\n");
    printf("3. Search by mail address\n");
    printf("4. Exit\n");
    printf("Enter your choice : ");
    while(1)
    {
     scanf("%d", &choice);
    //search by name
     if(choice==1)
     {
            printf("Enter the name\n");
            scanf(" %[^\n]", str1);
            printf("Searching by name....\n");
            flag=0;
             for(i=0;i< s->count;i++)
             {
                if(!(strcasecmp(s->arr[i].name, str1)))
                {
                    flag++;
                    temp=i;               //store the index at which the contact is found first,pass this if only one contact found
                    display(s,i,flag);    //passing the found index to print the details.
               }                          //passing flag to ensure that the heading is shown once
            }
            if(flag==1)
            {
                return temp;             //if only one contact found, pass the first found index
            }
            else if(flag>1)
            {
               return -2;                //if more than one contact found, returning a value to tell that more conatcts have been found
            }
            else{
               printf("Not found\n");
               return -1;
            }
    }

    //search by mobile number
    else if(choice==2)
    {
            printf("Enter the mobile number\n");
            scanf(" %[^\n]", str2);
            printf("Searching by mobile number....\n");
            int flag=0,i;
             for(i=0;i< s->count;i++)
             {
                if(!(strcmp(s->arr[i].mobile, str2)))
                {
                    flag++;
                    display(s,i,flag);
                    return i;         // passing the index at which found
                }
            }
             printf("Not found\n");
             return -1;
     }

    //search by maild id
    else if(choice==3)
    {
            printf("Enter the mail id\n");
            scanf(" %[^\n]", str3);
            printf("Searching by mail id.....\n");
            int flag=0,i;
             for(i=0;i< s->count;i++)
             {
                if(!(strcmp(s->arr[i].mail, str3)))
                {
                   flag++;
                   display(s,i,flag);
                    return i;           // passing the index at which found
                }
             }
             printf("Not found\n");
             return -1;
   }
   else if(choice==4)
   {
      printf("Exit\nReturning to main menu\n");
      return -4;
   }
   else{
         printf("Invalid choice.Try again\n");
      }
   }
}
// displaying the found contact details.
void display(struct address_book *s1, int index,int flag)
{

   if(flag==1)
   {
      printf("Found\n");
      printf("------------------------------------------------------------------------------------------------------------------------\n");
      printf("Sl.No.\tName\t\t\t\t\t\tMobile\t\t\tEmail.Id\n");
      printf("-------------------------------------------------------------------------------------------------------------------------\n");
    }
     printf("%-7d %-47s %-23s %s\n", index+1,s1->arr[index].name, s1->arr[index].mobile, s1->arr[index].mail);   
                     
}