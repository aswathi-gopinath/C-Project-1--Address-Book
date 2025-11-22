#include<stdio.h>
#include "myheader.h"
 
void list_contact(struct address_book *s)
{
    int i;
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Sl.No.\tName\t\t\t\t\t\tMobile\t\t\tEmail.Id\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<s->count;i++)
    {
        printf("%-7d %-47s %-23s %s\n", i+1,s->arr[i].name, s->arr[i].mobile, s->arr[i].mail);
    }
}
