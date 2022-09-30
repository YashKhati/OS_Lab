 #include<stdio.h>
 #include<unistd.h>
 int main()
 {
	printf("Current Process id : %d\n",getpid());
 	int n,sum=0;
 	printf("Enter number of elements in array : ");	
	scanf("%d",&n); 
	int arr[n];
	printf("Enter array Elements : \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
 	int pid=fork();
 	if(pid==0)
 	{
 		sum=0;		
  		for(int i = 0 ; i < n; i++)
  		{
          	if(arr[i]%2 == 0)
 				sum += arr[i];
   		}
		printf("\nChild Process---------\n EvenSum : %d and ppid : %d\n",sum,getppid()); 
	}
	else
	{
		sum=0;		
  		for(int i = 0 ; i < n; i++)
  		{
          	if(arr[i]%2 != 0)
 				sum += arr[i];
   		}
		printf("\nParent Process---------\n OddSum : %d and pid : %d\n",sum,getpid()); 
	}
	return 0;
}
