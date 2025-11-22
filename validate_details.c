#include<stdio.h>
#include<string.h>
#include<ctype.h>

//validate name
int name(char str1[])
{
    int i=0,count=0;
    if(isalpha(str1[0])) // first letter should not be space
    {
         for(i=1;str1[i]!='\0';i++)
         {
             if(!(isalpha(str1[i]) || str1[i]==' ')) // name should only contains alphabets and space
            {
                return 0;
            }
        }
         return 1;
    }
    return 0;
}

// validate mobile number
int mobile(char str2[])
{
    int i,count=0;
    if(strlen(str2)==10) // mobile number should contain 10 digits
    {
        for(i=0;str2[i]!='\0';i++)
        {
            if(!(isdigit(str2[i]))) // characters should only be digits
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// validate mail address
int mail(char str[])
{
    int i;
    int arr[7]={0,0,0,0,0,0,0}; // array flag to check all conditons are met
    for(i=0;str[i]!='\0';i++) // should contain '@' and '.'
    {
        if(str[i]=='@') arr[0]=1;
        else if(str[i]=='.') arr[1]=1;
    }
    if(arr[0]==1 && arr[1]==1) //if contain need to check other conditions
    {
        int count=0;
        for(i=0;str[i]!='@';i++)
        {
            if(isupper(str[i])) return 0;
            if(isalpha(str[i])) arr[2]=1; //atlest username contain one alpha character
            if(str[i]=='@'|| str[i]==' ')        // username can contain alpha, 
            //   numeric and special characters bt not space and '@' again 
            {
                count=1;
                return 0;
            }
            if(ispunct(str[i]) && ispunct(str[i+1]))
            {
                count=1;
                return 0;
            }

        }
        if(count==0) arr[3]=1;  //check username comdtion met
        int j=i;
        count=0;
        for(i=j+1;str[i]!='.';i++)
        {
            if(isalpha(str[i])) arr[4]=1; // atleast one alpha character
            if((!(isalnum(str[i]))) || str[i]=='.')  //no more '.' and should contain only alpha and num
            {
                count++;
                return 0;
            }
        }
        if(count==0) arr[5]=1;
        j=i+1;
        count=0;
        for(i=j;str[i]!='\0';i++)
        {
            if(!(isalpha(str[i]))) 
            {
                 count++;
                 return 0;
            }
        }
        if(count==0) arr[6]=1;
        for(i=0;i<7;i++)
        {
            if(arr[i]!=1) return 0;
        }
        return 1;
    }
    return 0;
}


