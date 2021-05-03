# ```libasm```
The aim of this project is to get familiar with the Assembly language.

It consists of creating 6 basic functions of the C language into x86 (Intel syntax) Assembly code. Here are the function definitions:

```c
size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);
```

## How to use it

To compile the library, execute the following command:
```bash
make
```

In order to compile the test files using the library:
```bash
make test
```

To test the library:
```bash
./test
```

## What I learned
Assembly isn't that difficult in the end. Initially, it seemed very chaotic to me, but in reality it's pretty easy to understand (at least for small functions). This project was incredibly useful to me as it really taught me the inner workings of computers with syscalls, function calls...

## Acknowledgments
- Davy Wybiral's excellent [Intro to x86 Assembly Language](https://www.youtube.com/watch?v=wLXIWKUWpSs&list=PLmxT2pVYo5LB5EzTPZGfFN0c2GDiSXgQe)
- Yaroslav Soroko's [libasm](https://github.com/Ysoroko/Libasm)
- Charles Cabergs' [libasm](https://github.com/cacharle/libasm)
- fdeĉ's [libasm](https://git.42l.fr/frdescam/libasm)

## Warning
The structure of this repository does **not** follow the guidelines.
The reason for this is to add some clarity in how the files are structured.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
