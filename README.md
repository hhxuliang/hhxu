2014-07-23
There are more diffrence between linux 1.0 and 0.11, such as timer, V0.11 use a simple and limitational timer, it have up to 32/64 timer to be used at the same time. The struct time_list not support function with parameter. The V1.0 is a better implimentation. I upgrade the timer today.

2014-08-01
Add the socket system call named sys_socketcall, this function is copy from linux1.0 that is similarity with current linux kernel sys_socketcall.
