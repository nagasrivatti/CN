#include<stdio.h>
#include<stdlib.h>
void main(){
        int bucketSize,outputRate,n,incoming;
        int stored=0;
        printf("=== Leaky Bucket Algorithm Simulation ===\n");
        printf("Enter bucket capacity (in packets): ");
        scanf("%d",&bucketSize);
        printf("Enter output rate(packets per second): ");
        scanf("%d",&outputRate);
        printf("Enter number of incoming packets (time slots): ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
                printf("\nTime %d: Enter number of incoming packets: ",i);
                scanf("%d",&incoming);
                printf("Incoming Packets: %d\n",incoming);
                if(incoming +stored>bucketSize){
                        int dropped=(incoming+stored)-bucketSize;
                        stored=bucketSize;
                        printf("Bucket overflow! Dropped packets: %d\n",dropped);
                }
                else
                        stored=stored+incoming;
                if(stored>outputRate){
                        stored=stored-outputRate;
                        printf("Transmitted: %d | Packets left in bucket:%d\n",outputRate,stored);
                }
                else{
                        printf("Transmitted: %d |Packets left in bucket: 0\n",stored);
                        stored=0;
                }
        }
        while(stored>0){
                if(stored>outputRate){
                        stored=stored-outputRate;
                        printf("\nTransmitted: %d |packets left in bucket :%d\n",outputRate,stored);
                }
                else{
                        printf("Transmitted: %d |packets left in bucket : 0\n",stored);
                        stored=0;
                }
        }
        printf("\nAll packets transmitted successfully!\n");
}
o/p:
=== Leaky Bucket Algorithm Simulation === 
Enter bucket capacity (in packets): 3 
Enter output rate(packets per second): 2 
Enter number of incoming packets (time slots): 3 
Time 1: Enter number of incoming packets: 2 
Incoming Packets: 2 
Transmitted: 2 |Packets left in bucket: 0 
Time 2: Enter number of incoming packets: 3 
Incoming Packets: 3 
Transmitted: 2 | Packets left in bucket:1 
Time 3: Enter number of incoming packets: 3 
Incoming Packets: 3 
Bucket overflow! Dropped packets: 1 
Transmitted: 2 | Packets left in bucket: 1 
Transmitted: 1 |packets left in bucket : 0 
All packets transmitted successfully!
