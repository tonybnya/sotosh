# SOTO SHELL (sotosh)

sotosh is a simple implementation of a shell in C. It demonstrates the basics of how a shell works. This project is the final project for the C learning path for the ALX-Holberton Software Engineering Program.



## Compilation

```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

Interactive Mode

```c
$ ./hsh
  ($) /bin/ls
  hsh main.c shell.c
  ($)
  ($) exit
$
```

Non Interactive Mode

```c
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test
$
$ cat test
/bin/ls
/bin/ls
$
$ cat test | ./hsh
hsh main.c shell.c test
hsh main.c shell.c test
$
```

## Contributors

[Soso Oloju](https://github.com/soclassique)

[Tony B. NYA]([soclassique · GitHub](https://github.com/tonybnya))


