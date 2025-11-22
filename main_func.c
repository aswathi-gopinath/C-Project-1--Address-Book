#include<stdio.h>
#include "myheader.h"
int main()
{
    struct address_book s;
    s.count=0;
    load_contact(&s);
    int option;
    printf(" ----------------------------------------------------------------------------------------\n");
    printf("|                                  ADDRESS BOOK                                           |\n");
    printf(" ----------------------------------------------------------------------------------------\n");
    
    do
    {
       printf("           -----------------------MAIN MENU------------------                          \nOptions : \n1. Create Contact\n2. Display Contact\n3. Search Contact\n4. Edit Contact\n5. Delete Contact\n6. Save and Exit\n");
       printf("Enter the option : ");
       scanf("%d", &option);
       switch(option)
       {
        case 1 : 
            printf("Create Contact\n");
            create_contact(&s);
            break;
        case 2:
            printf("Contact List\n");
            list_contact(&s);
            break;
        case 3:
            {
                int value;
                do
                {
                    value= search_contact(&s);
                }while(value!=-4);
                break;
                
            }
        case 4:
            {    
                edit_contact(&s);
                break;
            }
        case 5:
                
                delete_contact(&s);
                break;
        case 6:
                printf("Save and Exit\n");
                save_contact(&s);
                break;
        default:
            printf("Invalid opiton\n");
            break;
        }
    }while(option!=6);
   
    return 0;
}