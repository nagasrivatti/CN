#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void main()
{
        int totalFrames,windowSize;
        int frameStatus[MAX];
        int i,choice,resend;
        printf("\n --- Selective Repeat ARQ Simulation ---\n");
        printf("Enter total number of frames to send: ");
        scanf("%d",&totalFrames);
        printf("Enter window size: ");
        scanf("%d",&windowSize);
        for(i=0;i<totalFrames;i++)
                frameStatus[i]=0;
        int sent=0;
        while(sent<totalFrames){
                printf("\n---Sending Window of Frames ---\n");
                for(i=sent; i<sent+windowSize && i<totalFrames; i++){
                        if(frameStatus[i]==0)
                                printf("Frame %d sent.\n",i);
                }
                for(i=sent; i<sent+windowSize && i<totalFrames; i++){
                        if(frameStatus[i]==0){
                                printf("Did frame %d get ACK? (1=yes,0=lost); ",i);
                                scanf("%d",&choice);
                                if(choice==1){
                                        printf("ACK for frame %d received.\n",i);
                                        frameStatus[i]=1;
                                }
                                else
                                        printf("Frame %d lost / not acknowledged.\n",i);
                        }
                }
                printf("\n DO you want to resend any lost frame? (Enter frame number, -1 to stop): ");
                scanf("%d",&resend);
                while(resend!=-1){
                        if(resend>=sent && resend<totalFrames && frameStatus[resend]==0)
                        {
                                printf("Resending frame %d...\n",resend);
                                printf("ACK for frame %d received now.\n",resend);
                                frameStatus[resend]=1;
                        }
                        else
                                printf("Invalid frame number or already ACKed.\n");
                        printf("Enter next frame to resend (-1 to stop): ");
                        scanf("%d",&resend);
                } 
                while(sent<totalFrames && frameStatus[sent]==1)
                        sent++;
        }
        printf("\nAll frames sent and acknowledged successfully!\n");
}
o/p:
        --- Selective Repeat ARQ Simulation ---  
Enter total number of frames to send: 6  
Enter window size: 3  
---Sending Window of Frames ---  
Frame 0 sent.  
Frame 1 sent.  
Frame 2 sent.  
Did frame 0 get ACK? (1=yes,0=lost): 1  
ACK for frame 0 received.  
Did frame 1 get ACK? (1=yes,0=lost): 0  
Frame 1 lost / not acknowledged.  
Did frame 2 get ACK? (1=yes,0=lost): 1  
ACK for frame 2 received. 
DO you want to resend any lost frame? (Enter frame number, -1 to stop): 1  Resending frame 1...  
ACK for frame 1 received now.  
Enter next frame to resend (-1 to stop): -1  
---Sending Window of Frames ---  
Frame 3 sent.  
Frame 4 sent.  
Frame 5 sent.  
Did frame 3 get ACK? (1=yes,0=lost): 1  
ACK for frame 3 received.  
Did frame 4 get ACK? (1=yes,0=lost): 1  
ACK for frame 4 received.  
Did frame 5 get ACK? (1=yes,0=lost): 1  
ACK for frame 5 received.  
DO you want to resend any lost frame? (Enter frame number, -1 to stop): -1  All frames sent and acknowledged successfully! 

