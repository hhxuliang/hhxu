/*
 *  linux/fs/ioctl.c
 *
 *  (C) 1991  Linus Torvalds
 */

/* #include <string.h>*/
#include <errno.h>
#include <sys/stat.h>

#include <linux/sched.h>

extern int tty_ioctl(int dev, int cmd, int arg);

typedef int (*ioctl_ptr)(int dev,int cmd,int arg);

#define NRDEVS ((sizeof (ioctl_table))/(sizeof (ioctl_ptr)))

static ioctl_ptr ioctl_table[]={
	NULL,		/* nodev */
	NULL,		/* /dev/mem */
	NULL,		/* /dev/fd */
	NULL,		/* /dev/hd */
	tty_ioctl,	/* /dev/ttyx */
	tty_ioctl,	/* /dev/tty */
	NULL,		/* /dev/lp */
	NULL};		/* named pipes */
	
int sys_netioctl(unsigned int fd, unsigned int cmd, unsigned long arg)
{	
	
	struct file * filp = current->filp[fd];
	int mode;
	printk("(%d %d)",fd,cmd);
	if (fd >= NR_OPEN || !(filp = current->filp[fd]))
		return -EBADF;

	if(filp->f_op != NULL)
		return filp->f_op->ioctl(filp->f_inode,filp,cmd,arg); 
	else
		printk("File %d is invalid!\n",fd);
	
}

int sys_ioctl(unsigned int fd, unsigned int cmd, unsigned long arg)
{	
	struct file * filp;
	int dev,mode;

	if (fd >= NR_OPEN || !(filp = current->filp[fd]))
		return -EBADF;
	mode=filp->f_inode->i_mode;
	if (!S_ISCHR(mode) && !S_ISBLK(mode))
		return -EINVAL;
	dev = filp->f_inode->i_zone[0];
	if (MAJOR(dev) >= NRDEVS)
		return -ENODEV;
	if (!ioctl_table[MAJOR(dev)])
		return -ENOTTY;
	return ioctl_table[MAJOR(dev)](dev,cmd,arg);
}
