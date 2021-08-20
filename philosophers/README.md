# ```philosophers```

This project is an introduction to the use of threads a consists of creating a simulation where a number of philosophers eat, think and sleep around a table. More information can be found [here](https://github.com/maxdesalle/42/blob/main/philosophers/en.subject.pdf).

## How to use it
To try out ```philosophers```, compile it first using:
```bash
make re
```
Then, execute the program as follows:
```bash
./philo <number of philosophers> <time to die> <time to eat> <time to sleep>
```

Here are some command examples:
```bash
./philo 1 200 200 200 # philosopher 1 should die before 210ms
./philo 5 800 200 200 # no one should die (infinite loop)
./philo 4 410 200 200 # no one should die (infinite loop)
./philo 4 310 200 200 # one philosopher should die before 320ms
./philo 4 500 200 2147483647 # one philosopher should die before 510ms
```

## What I learned
This project was a great introduction to threads. It opened my eyes to the paradigm which threading is.

## Acknowledgements
- [CodeVault's great playlist about threads](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [iciamyplant's amazing guide (french)](https://github.com/iciamyplant/Philosophers)

## Warning
The structure of this repository does **not** necessarily follow the guidelines.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
