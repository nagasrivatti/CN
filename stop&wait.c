#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
void sender(int totalFrames); 
void receiver(int frame); 
void main(){ 
 int totalFrames; 
 printf("===Stop-and-Wait Protocol Simulation ===\n"); 
 printf("Enter total number of frames to send: "); 
 scanf("%d",&totalFrames); 
 sender(totalFrames); 
} 
void sender(int totalFrames) 
{ 
 int i,ack,choice; 
 srand(time(NULL)); 
 for(i=1;i<=totalFrames;i++){ 
 printf("\nSender: Sending Frame %d",i); 
 printf("\nReceiver: Do you want to ACK Frame %d? 1=yes, 0=No): ",i);  scanf("%d",&choice); 
 if(choice==1){ 
 receiver(i); 
 printf("Sender: ACK %d Received \n",i); 
 } 
 else{ 
 printf("Sender: ACK %d lost. Retransmitting... \n",i);
 i--; 
 } 
 } 
 printf("\nAll %d frames sent successfully!\n",totalFrames); } 
void receiver(int frame){ 
 printf("Receiver:Frame %d received. Sending ACK %d...\n",frame,frame); } 
Output: 
===Stop-and-Wait Protocol Simulation === 
Enter total number of frames to send: 3 
Sender: Sending Frame 1 
Receiver: Do you want to ACK Frame 1? (1=yes, 0=No): 1 
Receiver: Frame 1 received. Sending ACK 1... 
Sender: ACK 1 Received 
Sender: Sending Frame 2 
Receiver: Do you want to ACK Frame 2? (1=yes, 0=No): 1 
Receiver: Frame 2 received. Sending ACK 2... 
Sender: ACK 2 Received 
Sender: Sending Frame 3 
Receiver: Do you want to ACK Frame 3? (1=yes, 0=No): 0 
Sender: ACK 3 lost. Retransmitting... 
Sender: Sending Frame 3 
Receiver: Do you want to ACK Frame 3? (1=yes, 0=No): 1 
Receiver: Frame 3 received. Sending ACK 3... 
Sender: ACK 3 Received 
All 3 frames sent successfully!
