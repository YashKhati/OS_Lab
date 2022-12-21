 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define disk_size 200 
void SCAN ( int tracks[] , int n , int head , char direction[] , int left[] , int right[] , int temp1 , int temp2 )
{
  
    
    // Sorting of left and right array 
    
    for( int i = 0 ; i < temp1-1 ; i++)
    {
        for( int j = 0 ; j < temp1-i-1 ; j++)
        {
            if( left[j] > left[j+1] )
            {
                int temp = left[j] ;
                left[j] = left[j+1];
                left[j+1] = temp ;
            }
        }
    }
    
    for( int i = 0 ; i < temp2-1 ; i++)
    {
        for( int j = 0 ; j < temp2-1-i ; j++)
        {
            if( right[j] > right[j+1] )
            {
                int temp = right[j] ;
                right[j] = right[j+1];
                right[j+1] = temp ;
            }
        }
    }  
    
   int run = 2;
   int  k  = 0 ;
   int cur_track , distance , flag = 0  , seek_count = 0;
    while (run--)
    {
        if ( strcmp( direction , "left") == 0) 
        {
            
            for (int i = temp1-1; i >= 0; i--) 
            {
                
                cur_track = left[i];
 
                tracks[k] = cur_track ;
                k++;
 
                 
                distance = abs(cur_track - head);
 
                 
                seek_count += distance;
 
                 
                head = cur_track;
            }
            if( flag == 0)
            {
                tracks[k] = 0 ;
                seek_count +=  abs( cur_track-0);
                head =  0 ;
                k++ ;
            }
            flag = 1 ;
          
            direction = "right";
        }
        else if ( strcmp( direction , "right" ) == 0 ) 
        {
            for (int i = 0; i < temp2 ; i++)
            {
                cur_track = right[i];
                
                 tracks[k] = cur_track ;
                 k++;
 
               
                distance = abs(cur_track - head);
 
                
                seek_count += distance;
 
                 
                head = cur_track;
            }
            if( flag == 0)
            {
                tracks[k] = disk_size-1 ;
                seek_count += abs(disk_size-1-cur_track) ;
                head = disk_size-1  ;
                k++;
            }
            flag = 1 ;
            direction = "left";
        }
        
    }
 
    printf("Total number of seek operations = %d\n",seek_count);
 
    printf("Seek Sequence is\n");

    for (int i = 0; i < n+1 ; i++) {
        printf("%d\t",tracks[i]);
    }
}
int main()
{
    int n ;
    printf("\nEnter the number of reqested tracks :\n");
    scanf("%d",&n);
    int head ;
    printf("Enter the head position : ");
    scanf("%d",&head);
    int tracks[n] , left[20] , right[20] , temp , temp1 = 0 , temp2 = 0 ;
    printf("Enter the rquested tracks : \n");
    for( int i = 0 ; i < n ; i++)
    {
        scanf("%d",&temp);
        
        if( temp < head )
        {
            left[temp1] = temp ;
            temp1++;
        }
        else
        {
            right[temp2] = temp ;
            temp2++;
        }
    }
    char direction[] = "left";
    SCAN ( tracks , n , head , direction , left , right , temp1 , temp2 );
     
    return 0;
    
}
