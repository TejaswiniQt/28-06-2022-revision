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

#include <linux/kthread.h> // thread 
#include <linux/delay.h>   // sleep 
#include <linux/sched.h>  
#include <linux/mutex.h>             //step 1 for mutex


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sindhu");

unsigned long my_global_variable = 0;

struct mutex my_mutex; // step 2 for mutex 

int my_thread_handle1(void *p);
int my_thread_handle2(void *p);

int count =0;
struct task_struct * char_thread1,*char_thread2;

int my_thread_handle1(void *p)
{
	while(!kthread_should_stop())
	{
		wake_up_process(char_thread1);
		mutex_lock(&my_mutex);   // step 4 for mutex 
		my_global_variable++;
		printk(KERN_INFO "my_thread_handle1 =  %lu\n", my_global_variable);
		mutex_unlock(&my_mutex);  // step 5 for mutex 
		msleep(1000);
		
	}
	return 0;
}

int my_thread_handle2(void *p)
{
	while(!kthread_should_stop())
	{
		wake_up_process(char_thread2);
		mutex_lock(&my_mutex);   // step 4 for mutex 
		my_global_variable++;
		printk(KERN_INFO "my_thread_handle2 = %lu\n", my_global_variable);
		mutex_unlock(&my_mutex);  // step 5 for mutex 
		msleep(1000);
		
	}
	return 0;
}

static int __init my_thread_driver_init(void)
{

    mutex_init(&my_mutex); // Mutex init   step 3 for mutex 
        
	char_thread1 = kthread_run(my_thread_handle1, NULL, "my_thread");

	if(char_thread1)
	{
		printk("thread1 created successfully");
	}
	else
	{
		printk("thread created failed");
		 
	}

	char_thread2 = kthread_run(my_thread_handle2, NULL, "my_thread");

	if(char_thread2)
	{
		printk("thread2 created successfully");
	}
	else
	{
		printk("thread created failed");
		 
	}
	return 0;
}

static void __exit my_therad_driver_exit(void)
{
	kthread_stop(char_thread1);
	kthread_stop(char_thread2);
}

module_init(my_thread_driver_init);
module_exit(my_therad_driver_exit);


