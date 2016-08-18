#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_4_init(void){
	printk(KERN_ALERT "Hello World 4...!!");
return 0;
}

static void __exit hello_4_exit(void){
	printk(KERN_ALERT "Goodbye World...!!!");
}

module_init(hello_4_init);
module_exit(hello_4_exit)

MODULE_AUTHOR("Sandeep A L <alsandeep@gmail.com>");
MODULE_DESCRIPTION("Test module for MODULE LICENSE");
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("gsmsmssvr");
