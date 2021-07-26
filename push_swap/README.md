# ```push_swap```
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. Please view the [subject](https://github.com/maxdesalle/42/blob/main/push_swap/en.subject.pdf) for more information.

## How to use it
My ```push_swap``` comes along with a built-in tester, to compile all the necessary files, execute the following command after cloning and entering the repository in your terminal:

```bash
make re
```

A file called ```tester``` should now have been created (among other files), to try out the program, simply execute the tester program along with the number of numbers you want to give over to the push_swap program:

```bash
./tester 392 # the tester will generate 392 unique random numbers and execute the push_swap program with those
```

If you want to launch the tester program on repeat, simply start the following bash script with the number of numbers to give to ```push_swap``` as argument:

```bash
./test/launcher.sh 392 # this will execute the tester program every second
```

If you want to use your own numbers, simply execute the program as indicated below:

```bash
./push_swap <your list of unique numbers separated by spaces> # ./push_swap 30 60 2 849 303 3
```

## What I learned
This project was relatively short compared to others, but was incredibly instructive on the algorithm side (obviously), but also on the linked list side. Before ```push_swap```, I must admit I wasn't really comfortable with linked lists, especially when adding fancy additions like circularity and/or two ways to iterate through it (with next previous pointers).

## Acknowledgements
- Jamie Dawson's [blog post](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- Leo Fu's [blog post](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- Michael Sambol's [videos](https://www.youtube.com/user/mikeysambol)

## Warning
The structure of this repository does **not** follow the guidelines.
The reason for this is the addition of a test folder, as well as global variables needed to get the tester to work correctly.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
