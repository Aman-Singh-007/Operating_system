#include<iostream>
using namespace std;


        
                 int min_pid=300;
                 int max_pid=5000;
                 int* pids;
		 bool flag=false;

               //fuction to creates and initializes a data structure for representing pids; returns −1 if unsuccessful, 1 if successful
               
               int allocate_map()
                {
                        pids=new int[max_pid-min_pid+1];	// dynamic memory allocation for PIDS
                        if(pids==NULL)
                        {
                                cout<<"memory allocation failed"<<endl;
                                return -1;
                        }
		  	        if(flag==false)
			          {
				              for(int i=0;i<=max_pid-min_pid;i++)
                                              {
                                                pids[i]=0;
                                               }
                                     cout<<"memory allocated successfully"<<endl;
			                  flag=true;
                                         return 1;
			         }
		          	else 
			          {
			           	cout<<"memory already allocated"<<endl;
				          return 1;
			          }
		         }


                // Allocates and returns a pid; returns −1 if unable to allocate a pid (all pids are in use)
                
                 int allocate_pid()
                   {
                        if(pids==NULL)
                        {
                                cout<<"memory is not allocated yet"<<endl;
                                return -1;
                        }
                        int num=-1;
                        for(int i=0;i<=max_pid-min_pid;i++)
                        {
                                if(pids[i]==0)
                                {
                                        pids[i]=1;
                                        num=i+min_pid;
                                        break;
                                }
                        }
                        if(num==-1)
                        {
                                cout<<"unable to allocate PID"<<endl;
                                return 1;
                        }
                        cout<<"allocated pid: "<<num<<endl;
                        return 1;
                }

               // function to releases a pid
                void release_pid(int pid)
                {
                        if(pids==NULL)
                        {
                                cout<<"pid manager is not initialized"<<endl;
                                return ;
                        }
                        if(pid<min_pid||pid>max_pid)
                        {
                                cout<<"given pid is out of bound"<<endl;
                                return ;
                        }
                        int newpid=pid-min_pid;
                        if(pids[newpid]==0)
                        {
                                cout<<"PID"<<" "<<pid<<" is already empty"<<endl;
                                return ;
                        }
                        cout<<"releasing PID: "<<pid<<endl;
                        pids[newpid]=0;
                        return ;
                }

int main()
{
        char k;
	while(true)
	{cout<<"press A: to allocate memory"<<endl;
	cout<<"press B:to allocate PID"<<endl;
	cout<<"press C:to release PID"<<endl;
	cout<<"press other to exit"<<endl;
	cin>>k;
	switch(k)
	{
		case 'A': allocate_map();
			  break;
		case 'B': allocate_pid();
			  break;
		case 'C':int PID;
	           cout<<"enter PID to be free"<<endl;
	           cin>>PID;
	           release_pid(PID);
	           break;
	  default :if(pids!=NULL)
             delete[] pids; //releasing dyanamic memory
		         return -1;
	}
	}	
	
}
