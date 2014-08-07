2014-07-23
There are more diffrence between linux 1.0 and 0.11, such as timer, V0.11 use a simple and limitational timer, it have up to 32/64 timer to be used at the same time. The struct time_list not support function with parameter. The V1.0 is a better implimentation. I upgrade the timer today.

2014-08-01
Add the socket system call named sys_socketcall, this function is copy from linux1.0 that is similarity with current linux kernel sys_socketcall.

2014-8-7
Upgrade the function related with task status change function: sleep_on sleep_interupte_on wake_up for better logic reference linux1.0. The new functions use loop list to record tasks status with resource requirment so that make sleep_on sleep_interupte_on wake_up with a unified logic.
