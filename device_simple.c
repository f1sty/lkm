#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>

#define MAJOR_NUMBER 9

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yurii <f1sty> Skrynnykov");
MODULE_DESCRIPTION("Simple hello world module");

static int driver_open(struct inode *device, struct file *instance) {
  pr_info("Device was opened\n");
  return 0;
}

static int driver_release(struct inode *device, struct file *instance) {
  pr_info("Device was opened\n");
  return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE, .open = driver_open, .release = driver_release};

static int __init mod_init(void) {
  int retval;

  pr_info("Hello kernel!\n");

  retval = register_chrdev(MAJOR_NUMBER, "laser", &fops);

  if (retval == 0) {
    pr_info("Registered device with major: %d, and minor: 0\n", MAJOR_NUMBER);
  } else if (retval > 0) {
    pr_info("Registered device with major: %d, and minor: %d\n", retval >> 20,
            retval & 0xfffff);
  } else {
    pr_err("Couldn't regiser device\n");
    return -1;
  }

  return 0;
}

static void __exit mod_exit(void) {
  unregister_chrdev(MAJOR_NUMBER, "laser");
  pr_info("Bye-bye kernel!");
}

module_init(mod_init);
module_exit(mod_exit);
