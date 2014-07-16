#ifndef _MM_H
#define _MM_H

#define PAGE_SIZE 4096
/* to mask away the intra-page address bits */
#define PAGE_MASK			(~(PAGE_SIZE-1))

extern unsigned long get_free_page(void);
extern unsigned long put_page(unsigned long page,unsigned long address);
extern void free_page(unsigned long addr);

#endif
