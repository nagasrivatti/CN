#include<stdio.h>
void main()
{
        int total_frames, window_size;
        int sent = 0, lost_frame, i;
        printf("Enter total number of frsmes to send: ");
        scanf("%d", &total_frames);
        printf("Enter window size: ");
        scanf("%d", &window_size);
        printf("\n--- GO-Back-N Sliding Window Protocol Simulation ---\n\n");
        while(sent < total_frames)
        {
                printf("Sender: Sending frame ");
                for(i = sent; i<sent + window_size && i<total_frames; i++)
                        printf("%d ", i);
                printf("\n");
                printf("Enter the frame number to be lost (or -1 if none lost): ");
                scanf("%d", &lost_frame);
                if(lost_frame >= sent && lost_frame < sent + window_size && lost_frame < total_frames)
                {
                        printf("Receiver: Frame %d lost! Go back and resend from %d\n\n", lost_frame, lost_frame);
                        sent = lost_frame;
                }
                else
                {
                        int ack = sent + window_size;
                        if(ack > total_frames)
                                ack = total_frames;
                        printf("Receriver: Acknowledged up to frame %d\n\n", ack-1);
                        sent = ack;
                }
        }
        printf("All frames sent successfully using Go-Back-N!\n");
}
o/p:
        Enter total number of frames to send: 10  
Enter window size: 4  
--- GO-Back-N Sliding Window Protocol Simulation --- 
Sender: Sending frame 0 1 2 3  
Enter the frame number to be lost (or -1 if none lost): 2  Receiver: Frame 2 lost! Go back and resend from 2  
Sender: Sending frame 2 3 4 5  
Enter the frame number to be lost (or -1 if none lost): -1  Receiver: Acknowledged up to frame 5  
Sender: Sending frame 6 7 8 9  
Enter the frame number to be lost (or -1 if none lost): -1  Receiver: Acknowledged up to frame 9  
All frames sent successfully using Go-Back-N!   

