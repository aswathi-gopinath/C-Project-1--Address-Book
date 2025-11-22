// headerfile
#include<stdio.h>
 struct contact_details
 {
    char name[50];
    char mobile[11];
    char mail[100];
 };

 struct address_book
 {
    struct contact_details arr[100];
    int count;
 };
int name(char str1[]);
int mobile(char str2[]);
int mail(char str3[]);
void create_contact(struct address_book *s);
void list_contact(struct address_book *s);
int search_contact(struct address_book *s);
int edit_contact(struct address_book *s);
void display(struct address_book *s1, int index,int flag);
void edit(struct address_book *s, int index1);
int delete_contact(struct address_book *s);
void save_contact(struct address_book *s);
int load_contact(struct address_book *s);