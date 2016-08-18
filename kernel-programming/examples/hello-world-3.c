#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int sample_data __initdata = 3; 

static int __init hello_3_init(void){
	printk(KERN_ALERT "Hello World %d Entering...\n", sample_data);
return 0;
}

static void __exit hello_3_exit(void){
	printk(KERN_ALERT "Hello World 3 Exiting..!!!");
} 

module_init(hello_3_init);
module_exit(hello_3_exit);
