
# 1.理解page cache对程序速度影响
    $ sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'
    $ time python hello.py 
    Hello World! Love, Python

    real	0m0.142s
    user	0m0.000s
    sys	0m0.020s
    
    $ time python hello.py
    ...
    real	0m0.018s
    ...
### 两次时间差很大！

# 2.理解mmap
    $ gcc mmap.c
    $ ./a.out 
    print "Hello World! Love, Python"
