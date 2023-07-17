#include <linux/module.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yurii <f1sty> Skrynnykov");
MODULE_DESCRIPTION("Simple hello world module");

int init_module(void) {
  pr_info("Hello world!\n");
  return 0;
}
void cleanup_module(void) { pr_info("Goodbye world!\n"); }
