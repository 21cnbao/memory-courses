# valgrind:
    gcc -g leak-example.c
    valgrind --tool=memcheck --leak-check=yes ./a.out

# asan:
    gcc -g  -fsanitize=address  ./lsan.c
    gcc-8 -fuse-ld=gold -fsanitize=address -g ./lsan.c

