#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fcntl.h> /*Helps fix O_ACCMODE*/
#include <linux/sched.h> /*Helps fix TASK_UNINTERRUPTIBLE */
#include <linux/fs.h> /*Helps fix the struct intializer */

#include<linux/slab.h>                 //kmalloc()
#include<linux/uaccess.h>              //copy_to/from_user()
#include <linux/ioctl.h>

#include <linux/proc_fs.h>    // proc file system
#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/proc_ns.h>

#include <linux/kobject.h>

#include <linux/interrupt.h>

#include <linux/kthread.h> // therad 
#include <linux/delay.h>   // sleep 
#include <linux/sched.h>  

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sindhu");


struct task_struct *char_thread1;
struct task_struct *char_thread2;

int count=0,i;

int my_thread1(void *p);
int my_thread2(void *p);


int my_thread1(void *p)
{
		//while(!kthread_should_stop())
		for(i=0;i<=100;i++)
		{
				count++;
	//	printk("My thread1 = %d\n", count++);
	//	msleep(1000);
		}
		return 0;
}


/*int my_thread2(void *p)
{
		//while(!kthread_should_stop())
		for(i=0;i<=100;i++)
		{
		printk("My thread2 = %d\n", count++);
		msleep(1000);
		}
		return 0;
}*/


static int __init my_thread_init(void)
{
	char_thread1 = kthread_run(my_thread1, NULL, "my_thread1");
        if(char_thread1)
	{
		 printk(KERN_INFO "kthread created successfully\n");		
	}
	else
	{	
		
		printk(KERN_INFO "COuldnt create thread\n");
	} 

	char_thread2 = kthread_run(my_thread1, NULL, "my_thread2");
        if(char_thread2)
	{	
		printk(KERN_INFO "kthread created successfully\n");
	}
	else
	{		
		printk(KERN_INFO "COuldnt create thread\n");
	}

	printk("My thread1 = %d\n", count);
	return 0;
}


static void __exit my_thread_exit(void)
{
	kthread_stop(char_thread1);
	kthread_stop(char_thread2);
}


module_init(my_thread_init);
module_exit(my_thread_exit);


