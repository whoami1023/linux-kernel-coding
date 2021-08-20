#include <linux/notifier.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>

extern int invoke_notifiers_chain(unsigned long val, void *v);
#define NOTIFIER_TCHAIN_NUMBER 520111

static int __init send_notifier_chain_init(void)
{
    printk(KERN_DEBUG "send_notifier_chain_init\n");
    invoke_notifiers_chain(NOTIFIER_TCHAIN_NUMBER, "Your are very beautiful!");
    return 0;
}

static void __exit send_notifier_chain_exit(void)
{
    printk(KERN_DEBUG "send_notifier_chain_exit\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("whoami");

module_init(send_notifier_chain_init);
module_exit(send_notifier_chain_exit);