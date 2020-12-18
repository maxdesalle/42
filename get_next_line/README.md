# ```get_next_line```
```get_next_line``` is one of the three projects following [**```libft```**](https://github.com/maxdesalle/42/tree/main/libft). The purpose is to create a function which, when called in a loop, will then read the text available on a file descriptor one line at a time until the end of the file.

## How to use it
If you want to try it out, simply clone this repository and execute the following commands:
```console
cd 42/get_next_line/
```
```console
gcc -Wall -Wextra -Werror -o gnl src/get_next_line.c src/get_next_line_utils.c src/main.c
```
You should now have an executable called ```gnl```. I have included two test files which you can find in the ```test``` folder. To try out the ```get_next_line``` function, simply execute the following commands:
```console
./gnl test/wisdom.txt
```
```console
./gnl test/ipsum.txt
```
If everything works correctly, it should have a similar behaviour as the ```cat``` command.

## What I have learned
This is the first "big" project I have created in C, as [**```libft```**](https://github.com/maxdesalle/42/tree/main/libft) was more a collection of little functions, than a real big function. Aside from that, I also learned how the ```read``` function works, as well as everything about static variables of course.

## Warning
This repository does **not** respect the project's guidelines in terms of structure. This is done on purpose to add some clarity.

## License
Everything is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
