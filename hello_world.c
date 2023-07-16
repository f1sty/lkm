#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yurii <f1sty> Skrynnykov");
MODULE_DESCRIPTION("Simple hello world module");

static int __init mod_init(void) {
  printk("Hello world from module!\n");
  return 0;
}

static void __exit mod_exit(void) { printk("Bye-bye world from module!\n"); }

module_init(mod_init);
module_exit(mod_exit);
