#include <linux/notifier.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>


static RAW_NOTIFIER_HEAD(notifier_chain_fp);

int invoke_notifiers_chain(unsigned long val, void *v)
{
    printk(KERN_DEBUG "invoke_notifiers_chain\n");
    return raw_notifier_call_chain(&notifier_chain_fp, val, v);
}
EXPORT_SYMBOL_GPL(invoke_notifiers_chain);

int register_notifier_chain(struct notifier_block *nb)
{
    int err;
    err = raw_notifier_chain_register(&notifier_chain_fp, nb);

    if (err)
    {
        printk(KERN_DEBUG "raw_notifier_chain_register error!\n");
        goto out;
    }
    else 
    {
        printk(KERN_DEBUG "raw_notifier_chain_register success!\n");
    }
    out:
    return err;
}

EXPORT_SYMBOL_GPL(register_notifier_chain);

static int __init notifier_chain_init(void)
{
    printk(KERN_DEBUG "notifier_chain_init\n");
    return 0;
}

static void __exit notifier_chain_exit(void)
{
    printk(KERN_DEBUG "notifier_chain_exit\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("whoami");

module_init(notifier_chain_init);
module_exit(notifier_chain_exit);