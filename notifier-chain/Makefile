obj-m:=notifier_chain_register.o receiver_notifier_chain.o send_notifier_chain.o 

KBUILD_DIR:= /lib/modules/$(shell uname -r)/build

default:
	$(MAKE) -C $(KBUILD_DIR) M=$(shell pwd) 

clean:
	$(MAKE) -C $(KBUILD_DIR) M=$(shell pwd) clean
