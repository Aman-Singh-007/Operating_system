# Operating_system
# problem statement Q_3.21
The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:\
n =
{ n∕2, if n is even\
  &nbsp 3 × n + 1, if n is odd
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
6.after successful completion return from parent process.\
