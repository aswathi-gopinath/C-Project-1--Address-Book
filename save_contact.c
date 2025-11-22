#include<stdio.h>
#include "myheader.h"

void save_contact(struct address_book *s)
{
    FILE *fp;
    fp = fopen("contacts.csv", "w");
    fprintf(fp, "# %d\n", s->count);
    int i;
    for(i=0; i<s->count; i++)
    {
        fprintf(fp, " %s,%s,%s\n",s->arr[i].name, s->arr[i].mobile, s->arr[i].mail);
    }
    fclose(fp);
}