#ifndef _LINUX_TIMER_H
#define _LINUX_TIMER_H

struct timer_list {
	struct timer_list *next;
	unsigned long expires;
	unsigned long data;
	void (*function)(unsigned long);
};

extern void add_timer(struct timer_list * timer);
extern void add_timer_jiffies(struct timer_list,void (*fn)(unsigned long));
extern int  del_timer(struct timer_list * timer);

#endif

