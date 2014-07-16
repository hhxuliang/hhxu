#include <dev.h>




   

//struct packet_type *ptype_base = &ip_packet_type;
static struct sk_buff *volatile backlog = NULL;
static unsigned long ip_bcast = 0;



/* Initialize the DEV module. */
void
dev_init(void)
{
  struct device *dev, *dev2;

  /* Add the devices.
   * If the call to dev->init fails, the dev is removed
   * from the chain disconnecting the device until the
   * next reboot.
   */
  dev2 = NULL;
  for (dev = dev_base; dev != NULL; dev=dev->next) {
	if (dev->init && dev->init(dev)) {
		if (dev2 == NULL) dev_base = dev->next;
		  else dev2->next = dev->next;
	} else {
		dev2 = dev;
	}
  }

}



/*
 * Receive a packet from a device driver and queue it for the upper
 * (protocol) levels.  It always succeeds.
 */
void
netif_rx(struct sk_buff *skb)
{
  /* Set any necessary flags. */
  //skb->sk = NULL;
  //skb->free = 1;
  
  /* and add it to the "backlog" queue. */
  //IS_SKB(skb);
  skb_queue_tail(&backlog,skb);
   
  /* If any packet arrived, mark it for processing. */
  //if (backlog != NULL) mark_bh(INET_BH);

  return;
}

