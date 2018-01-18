#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>

static unsigned int variable=0x12345678;
static struct proc_dir_entry  *test_entry;

static int test_proc_show(struct seq_file *seq, void *v)
{
	unsigned int *ptr_var = seq->private;
	seq_printf(seq, "%u\n", *ptr_var);
	return 0;
}

static int test_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, test_proc_show, PDE_DATA(inode));
}

static const struct file_operations test_proc_fops =
{
	.owner = THIS_MODULE,
	.open = test_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static __init int test_proc_init(void)
{
	printk("variable addr:%p\n", &variable);

	test_entry = proc_create_data("stolen_data",0444, NULL, &test_proc_fops, &variable);
	if (test_entry)
		return 0;

	return -ENOMEM;
}
module_init(test_proc_init);

static __exit void test_proc_cleanup(void)
{
	remove_proc_entry("stolen_data", NULL);
}
module_exit(test_proc_cleanup);

MODULE_AUTHOR("Barry Song <baohua@kernel.org>");
MODULE_DESCRIPTION("proc exmaple");
MODULE_LICENSE("GPL v2");
