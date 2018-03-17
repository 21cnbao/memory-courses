# 1. getdelay+swap
### 本实验要保证swap不关闭，如已经关闭，运行sudo swapon -a，另外允许overcommit
    $ sudo swapon -a
    $ sudo sh -c 'echo 1 > /proc/sys/vm/overcommit_memory'
### 按照视频提示，用getdelays监控swap.c

# 2. cgroup/memory
### 本实验要关闭swap, 运行swapoff -a，另外允许overcommit
    $ sudo swapoff -a
    $ sudo sh -c 'echo 1 > /proc/sys/vm/overcommit_memory'
### 按照视频提示，把oom.c用cgexec放到新的group执行

# 3. vmstat
### 本实验要保证swap不关闭，如已经关闭，运行sudo swapon -a，另外允许overcommit
    $ sudo swapon -a
    $ sudo sh -c 'echo 1 > /proc/sys/vm/overcommit_memory'
### 按照视频提示，运行vmstat，修改swap.c，加大磁盘压力

