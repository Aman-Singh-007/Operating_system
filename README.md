# Operating_system
# problem statement Q_3.20
An operating system’s pid manager is responsible for managing process
identifiers. When a process is first created, it is assigned a unique pid
by the pid manager. The pid is returned to the pid manager when the
process completes execution, and the manager may later reassign this
pid. Process identifiers are discussed more fully in Section 3.3.1. What
is most important here is to recognize that process identifiers must be
unique; no two active processes can have the same pid.\
Use the following constants to identify the range of possible pid
values:\
#define MIN PID 300\
#define MAX PID 5000\
You may use any data structure of your choice to represent the availability of process identifiers. One strategy is to adopt what Linux has
done and use a bitmap in which a value of 0 at position i indicates that a process id of value i is available and a value of 1 indicates that the
process id is currently in use.\
Implement the following API for obtaining and releasing a pid:\
• int allocate map(void)—Creates and initializes a data structure for representing pids; returns −1 if unsuccessful, 1 if successful\
• int allocate pid(void)—Allocates and returns a pid; returns −1 if unable to allocate a pid (all pids are in use)\
• void release pid(int pid)—Releases a pid
# code_explanation Q_3.20
min_pid=300;\
max_pid=5000;\
Pid manager length= max_pid-min_pid+1;\
functions explanation-:\
1.int allocate_map()-  creates an array with length equals  "max_pid-min_pid+1",and initialize each element with 0;\
return 1 on successful creation and -1 if failed.\
2.int allocate_pid()- it checks for the first element in the array which is zero and puts a 1 there meaning the current pid is now in use,after adding a buffer of 300 to the index it returns the value on successful allocation,and returns -1 on faliure.\
3.void release_pid():- it first ask for a pid which is to be released,if the pid lies beteen min_pid and max_pid it goes and subtract the buffer 300 to get the real index in the array and puts a zero at that index indicating that the given pid is released.\
In the main fuction we are asking the user to select from different options and perform their task.\

# problem statement Q_3.21
The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:\
n =
{ n∕2, if n is even\
  &nbsp; 3 × n + 1, if n is odd\
}\
The conjecture states that when this algorithm is continually applied,
all positive integers will eventually reach 1. For example, if n = 35, the
sequence is\
35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1\
Write a C program using the fork() system call that generates this
sequence in the child process. The starting number will be provided
from the command line. For example, if 8 is passed as a parameter on
the command line, the child process will output 8, 4, 2, 1. Because the
parent and child processes have their own copies of the data, it will be
necessary for the child to output the sequence. Have the parent invoke
the wait() call to wait for the child process to complete before exiting
the program. Perform necessary error checking to ensure that a positive
integer is passed on the command line.
# code_explanation Q_3.21
1.Enter a integer greater than 0.\
2.create a child process using fork system call.\
3.if child process creation is failed then return.\
4.if child process is created sucessfully run the algorithm for colatz conjecture.\
5.in else statement wait for the child process to complete using wait system call.\
6.after successful completion return from parent process.

# References
 [(https://github.com/SheldonZhong/OS_practice/tree/master/ch3)]
