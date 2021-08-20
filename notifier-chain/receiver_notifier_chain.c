#include <linux/notifier.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>

extern int register_notifier_chain(struct notifier_block *nb);
#define NOTIFIER_TCHAIN_NUMBER 520111

/* realize the notifier call func */
int receiver_notifier_chain_event(struct notifier_block *nb, unsigned long action, void *data)
{
    switch (action)
    {
    case NOTIFIER_TCHAIN_NUMBER:
        printk(KERN_DEBUG "^_^very great! received a notifier chain event!^_^\n");
        break;
    default:
        break;
    }
    return NOTIFY_DONE;
}

static struct notifier_block receiver_notifier_chain = {
    .notifier_call = receiver_notifier_chain_event,
};

static int __init receiver_notifier_chain_init(void)
{
    printk(KERN_DEBUG "receiver_notifier_chain_init");
    register_notifier_chain(&receiver_notifier_chain);
    return 0;
}

static void __exit receiver_notifier_chain_exit(void)
{
    printk(KERN_DEBUG "receiver_notifier_chain_exit");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("whoami");

module_init(receiver_notifier_chain_init)
module_exit(receiver_notifier_chain_exit)

