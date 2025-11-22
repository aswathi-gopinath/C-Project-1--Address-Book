#include<stdio.h>
#include "myheader.h"
#include<string.h>
int delete_contact(struct address_book *s)
{
                int index2,result2,k;
                result2 = search_contact(s);
                if(result2==-2)
                {
                    printf("Which contact you want to delete\n");
                    scanf("%d",&k);
                    index2=k-1;
                }
                if(result2>=0)
                {
                    index2=result2;
                }
                if(result2==-1)
                {
                  return 0;
                }
               if(result2 == -5)
               {
                return 0;
               }
               int i;
               for(i=index2; i<s->count-1;i++)
               {
                 s->arr[i] = s->arr[i+1];
               }
               s->count--;
               printf("Contact deleted\n");

              char option1[5];
              printf("Do you want to see the list after deletion (Yes/No)\n");
              scanf("%s",option1);
              if(!(strcasecmp(option1, "Yes")))
                    {
                      list_contact(s);
                      return 0;
                    }
              else{
                printf("Request cancelled\n");
                return 0;
              }
            }