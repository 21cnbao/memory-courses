# 观察mallopt.c的代码，理解mallopt(M_TRIM_THRESHOLD, -1UL);
# 运行oom程序
    $ sudo swapoff -a
    [sudo] password for baohua: 

    $ sudo sh -c 'echo 1 > /proc/sys/vm/overcommit_memory'
    $ gcc oom.c
    $ ./a.out
    $ dmesg
    
### 通过dmesg可以获得kernel的oom消息
