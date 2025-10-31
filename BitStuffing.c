#include<stdio.h>
#include<string.h>
void bitStuffing(char data[])
{
        char stuffed[100];
        int i, j, count=0;
        for(i=0;i<strlen(data);i++)
        {
                stuffed[j++]=data[i];
                if(data[i]=='1')
                {
                        count++;
                        if(count==5)
                        {
                                stuffed[j++]='0';
                                count=0;
                        }
                }
                else
                {
                        count=0;
                }
        }
        stuffed[j]='\0';
        printf("stuffed data: %s\n", stuffed);
}
void main()
{
        char data[50];
        printf("Enter binary data(ex:1011110):");
        scanf("%s", data);
        bitStuffing(data);
}
o/p:
Enter binary data(e.g.,01111110111): 01111110011
        stuffed data:0111110110011
