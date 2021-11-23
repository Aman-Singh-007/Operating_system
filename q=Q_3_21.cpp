#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main()
{
	
        int n=0;
	pid_t child_pid;

		do
		{
			cout<<"Please enter a number greater than 0 to run the Collatz Conjecture"<<endl; 
  			cin>>n;	
		}while (n <= 0);	//enter number greater than 0

		child_pid = fork();	//creating child process
		
		
		if(child_pid<0)		//child process failed to create
		{
			cout<<"child process failed to create"<<endl;
			return -1;
		}

		else if (child_pid == 0)	//child process running
		{
			cout<<"child process is running"<<endl;
			while (n!=1)	// colatz conjecture alogorithm
			{
				cout<<n<<" ";
				if (n%2 == 0) //n is even
				{
					n= n/2;
				}
				else if (n%2 == 1) // n is odd
				{
					n= 3 * (n) + 1;
				}	
			
				
			}
		 
			cout<<1<<endl;
			cout<<"child process complete"<<endl;
		}
		// child process is created and parent is running
		else
		{
			cout<<"Parents is waiting on child process...."<<endl;
			wait(NULL);	//parent process waiting for child process
		        cout<<"parent process completed"<<endl;
		}
	return 0; 
}
