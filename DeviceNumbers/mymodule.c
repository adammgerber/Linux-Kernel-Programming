#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

/* Meta information: some distributions only load licensed modules */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Adam Gerber GNU/LINUX");
MODULE_DESCRIPTION("Registers a device number and implements some callback functions");

/*This function is called when the device file is opened*/
static int driver_open(struct inode *device_file, struct file *instance){
	printk("dev_nr - open was called!\n");
	return 0;
}

/*This function is called when the device file is closed*/
static int driver_close(struct inode *device_file, struct file *instance){
        printk("dev_nr - close was called!\n");
        return 0;
}

/*Defining our struct for file operations*/
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};



/*This function is called when the module is loaded into the kernel */
static int __init ModuleInit(void){
	int retval;
	printk("Hello, Kernel!\n");
	/* register device number */
	retval = register_chrdev(
	return 0;
}

/*This function is called when the module is removed from the kernel*/
static void __exit ModuleExit(void) {
	printk("Goodbye, Kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);

