#include<stdio.h>
#include "myheader.h"
#include<string.h>

int edit_contact(struct address_book *s)
{
  int index1,result,j;
  while(1)
  {
         result = search_contact(s);
         // if multiple contacts are present, we need to ask the user which one should want to edit
        if(result == -2)    
        {
          printf("Which contact you want to edit\n");
          scanf("%d",&j);
          index1=j-1;    
        }
        if(result>=0)
        {
           //passing the found index to edit
           index1=result;  
        }
        //if user want to exit menu or invalid choice, exit the function and returning to main menu
        if(result == -4 )
        {
            return 0;  
        }
         //if no contact is found , again go to search menu.
        if(result==-1)
        {
          index1 = -1;     
          printf("Returning to search menu...\n");
        }
         if(index1>=0)          
       {
        //function exit when user press exit option
         while(1)            
         { 
            int choice1;
            char str4[50], str5[11], str6[100];
             //Menu3
             printf("           ---------------------EDIT MENU------------------                          \n");
    
             printf("Choose from the option what you want to edit\n");
             printf("1. Edit by name\n");
             printf("2. Edit by mobile number\n");
             printf("3. Edit by mail address\n");
             printf("4. Exit\n");
             printf("Enter your choice : ");
             scanf("%d", &choice1);
            //edit by name
             if(choice1 == 1)
            {
              printf("Enter the new name\n");
              while(1)             // until entering the valid name
              {
                 scanf(" %[^\n]", str4);
                 if(name(str4))    //  calling the function to validate the name
                 {
                     strcpy(s->arr[index1].name, str4);
                     edit(s, index1); // to print the edited contact details.
                     break;           // if valid , edit the contact and come out of the loop
                 } 
                 else
                {
                    printf("Invalid format.Try again.\n");
                }
              }
            }
              //edit by number
            else if(choice1 == 2)
            {
                printf("Enter the new mobile number\n");
                while(1)                //until enetring the valid number
                {
                    int flag1 = 0,i;
                    scanf(" %[^\n]", str5);
                    if(mobile(str5))    //calling the function to validate the number
                    {
                        for(i=0;i<s->count;i++)   // after validation check whether the number already exist , avoiding wrong number.
                        {
                            if(!(strcmp(s->arr[i].mobile, str5)))
                            {
                                printf("Number already exist. Enter the correct number\n");
                                flag1 = 1;
                                break;    
                            }
                        }
                        if(flag1==0)
                        {
                              strcpy(s->arr[index1].mobile, str5);
                              edit(s, index1); // to print the edited contact details.
                              break;           // if valid , edit the contact and come out of the loop
                        }
                    }
                    else
                    {
                        printf("Invalid Format. Try Again\n");
                    }
                }
            }
            //edit by mail id
            else if(choice1 == 3)
            {
                printf("Enter the new mail id\n");
                while(1)              //until user enters the valid email id
                {
                    scanf(" %[^\n]", str6);
                    int i,flag2=0;
                    if(mail(str6))   //calling the function to validate the number
                    {
                        for(i=0;i<s->count;i++)
                        {
                            if(!(strcmp(s->arr[i].mail, str6))) // after validation check whether the mail already exist.
                            {
                                printf("Mail address already exist.Try again \n");
                                flag2 = 1;
                                break;
                            }
                        }
                        if(flag2==0)
                        {
                            strcpy(s->arr[index1].mail, str6);
                            edit(s,index1);
                            break;           // if valid , edit the contact and come out of the loop
                        }
                    }
                    else
                    {
                        printf("Invalid Format. Try Again\n");
                    }
                }
            }
            else if(choice1 == 4)
            {
               printf("Returning to main menu...\n");
               return 0;           //if user want to exit the function, returning to main menu
            }
            else{
                printf("Invalid choice.Try again\n");
               // return 0;          //if user enters an invalid choice, returns to the main menu
            }
        }
      }
  }
}
//to print the edited contact details
void edit(struct address_book *s, int index1)
{
      char option[5];
      printf("Do you want to see the edited contact.(Yes/No)\n");
      scanf("%s",option);
      if(!(strcasecmp(option, "Yes")))
      {
         printf("------------------------------------------------------------------------------------------------------------------------\n");
         printf("Sl.No.\tName\t\t\t\t\t\tMobile\t\t\tEmail.Id\n");
         printf("-------------------------------------------------------------------------------------------------------------------------\n");
         printf("%-7d %-47s %-23s %s\n", index1+1,s->arr[index1].name, s->arr[index1].mobile, s->arr[index1].mail);
      }
}

       