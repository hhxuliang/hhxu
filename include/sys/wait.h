#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

#include <sys/types.h>

#define _LOW(v)		( (v) & 0377)
#define _HIGH(v)	( ((v) >> 8) & 0377)

/* options for waitpid, WUNTRACED not supported */
#define WNOHANG		1
#define WUNTRACED	2

#define WIFEXITED(s)	(!((s)&0xFF)
#define WIFSTOPPED(s)	(((s)&0xFF)==0x7F)
#define WEXITSTATUS(s)	(((s)>>8)&0xFF)
#define WTERMSIG(s)	((s)&0x7F)
#define WSTOPSIG(s)	(((s)>>8)&0xFF)
#define WIFSIGNALED(s)	(((unsigned int)(s)-1 & 0xFFFF) < 0xFF)

struct wait_queue {
	struct task_struct * task;
	struct wait_queue * next;
};

struct select_table_entry {
	struct wait_queue wait;
	struct wait_queue ** wait_address;
};

typedef struct select_table_struct {
	int nr;
	struct select_table_entry * entry;
} select_table;
#define __MAX_SELECT_TABLE_ENTRIES (4096 / sizeof (struct select_table_entry))

pid_t wait(int *stat_loc);
pid_t waitpid(pid_t pid, int *stat_loc, int options);

#endif
