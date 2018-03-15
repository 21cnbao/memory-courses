# valgrind:
    gcc -g leak-example.c
    valgrind --tool=memcheck --leak-check=yes ./a.out

# asan:
    gcc -g  -fsanitize=address  ./leak-example.c


