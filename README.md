# memory-courses

## 硬件原理和分页管理

*   CPU寻址内存，虚拟地址、物理地址
*   MMU以及RWX权限、kernel和user模式权限
*   内存的zone: DMA、Normal和HIGHMEM
*   Linux内存管理Buddy算法
*   连续内存分配器(CMA)

## 内存的动态申请和释放

*   slab、kmalloc/kfree、/proc/slabinfo和slabtop
*   用户空间malloc/free与内核之间的关系
*   mallopt
*   vmalloc
*   内存耗尽（OOM）、oom_score和oom_adj
*   Android进程生命周期与OOM

## 进程的内存消耗和泄漏

*   进程的VMA。
*   进程内存消耗的4个概念：vss、rss、pss和uss
*   page fault的几种可能性，major和minor
*   应用内存泄漏的界定方法
*   应用内存泄漏的检测方法：valgrind和addresssanitizer

## 内存与I/O的交换

*   page cache
*   free命令的详细解释
*   read、write和mmap
*   file-backed的页面和匿名页
*   swap以及zRAM
*   页面回收和LRU

## 其他工程问题以及调优

*   DMA和cache一致性
*   内存的cgroup
*   性能方面的调优：page in/out, swapin/out
*   Dirty ratio的一些设置
*   swappiness
