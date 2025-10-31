#include<stdio.h>
#include<string.h>
#define FLAG '$'
#define ESC '&'
void charStuff(char data[])
{
        char stuff[100];
        int i, j=0;
        stuff[j++]=FLAG;
        for (i=0;i<strlen(data);i++)
        {
                if(data[i]==FLAG || data[i]==ESC )
                {
                        stuff[j++]=ESC;
                }
                stuff[j++]=data[i];
        }
        stuff[j++]=FLAG;
        stuff[j]='\0';
        printf("Stuffed Frsme: %s\n", stuff);
}
void main()
{
        char data[100];
        printf("Enter Input data(eg:ABCD):");
        scanf("%s", data);
        charStuff(data);
}
o/p:
Enter input data(eg.,AEFG):Hello
stuffed frame :$hello$
