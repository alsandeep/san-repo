#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int ary_argc = 0;
static short myshort = 0;
static int myint = 0;
static long mylong = 0;
static char *mystring = "string new";
static int myarray[2] = {0,0};


module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
MODULE_PARM_DESC(myshort, "A short interger");
module_param(myint, int, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(myint, "An Interger");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A String");

/* Integer array  passed from the command line while insmod */
module_param_array(myarray, int, &ary_argc, 0000);
MODULE_PARM_DESC(myarray, "An array of integer");

static int hello_5_init(void){
	int i=0;
	printk(KERN_INFO "myshort value :%hd\n", myshort);
	printk(KERN_INFO "myint value :%d\n", myint);
	printk(KERN_INFO "mylong value :%ld\n", mylong);
	printk(KERN_INFO "mystring value :%s\n", mystring);
	printk(KERN_INFO "myarray values" );
	for(i=0; i < (sizeof(myarray)/sizeof(int)); i++){
		printk(KERN_INFO " :%02x", myarray[i] );
	}
	printk(KERN_INFO "\n Got %d number of arguments\n", ary_argc);

return 0;
}

static void hello_5_exit(void){
	printk(KERN_INFO "myshort value :%hd\n", myshort);
	printk(KERN_INFO "myint value :%d\n", myint);
	printk(KERN_INFO "mylong value :%ld\n", mylong);
	printk(KERN_INFO "GoodBye hello world 5...!!\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sandeep A L <alsandeep@gmail.com>");
MODULE_DESCRIPTION("Module to Test module_param and MODULE_PARM_DESC");
