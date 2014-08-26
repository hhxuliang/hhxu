2014-07-23
There are more diffrence between linux 1.0 and 0.11, such as timer, V0.11 use a simple and limitational timer, it have up to 32/64 timer to be used at the same time. The struct time_list not support function with parameter. The V1.0 is a better implimentation. I upgrade the timer today.

2014-08-01
Add the socket system call named sys_socketcall, this function is copy from linux1.0 that is similarity with current linux kernel sys_socketcall.

2014-8-7
Upgrade the function related with task status change function: sleep_on sleep_interupte_on wake_up for better logic reference linux1.0. The new functions use loop list to record tasks status with resource requirment so that make sleep_on sleep_interupte_on wake_up with a unified logic.

2014-8-25
Change logic related with socket system call: socketcall(create file struct for socket as paremeter) and ioctl to open network dev. The major logic reference to the linux1.0, ioctl function is different between 0.11 and 1.0. Both of the two version use file to act the interface of device, but the additional operation function to the system call function, but 0.11 use device type to identify the funtion pointer. So that we must add this function pointer in file struct.

2014-8-26
Add a system call named netioctl that can contral network interface. The additional system call netioctl is unnecessary because there is a common system call name ioctl that is interface for file operation. But enhance the ioctl for network is fault, so that I add netioctl for network. Mybe it should not be add.
The additional system call netioctl can be used by process in userspace to up the network interface, ip address and so on.
