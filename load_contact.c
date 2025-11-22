#include<stdio.h>
#include "myheader.h"

int load_contact(struct address_book *s)
{
    FILE *fptr;
    fptr = fopen("contacts.csv", "r");
    if(fptr == NULL)
    {
        return -1;  
    }
    fscanf(fptr,"#%d\n", &s->count);
    int i;
    for(i=0; i<s->count; i++)
    {
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n",s->arr[i].name, s->arr[i].mobile, s->arr[i].mail);
    }
    fclose(fptr);
    return 0;
}