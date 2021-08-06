# ```pipex```
This project aims to provide a deeper understanding in two concepts: redirections and pipes. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus. Please view the [subject](https://github.com/maxdesalle/42/blob/main/pipex/en.subject.pdf) for more information.

## How to use it

To try out ```pipex```, compile it first using:
```bash
make re
```

Then, execute your command as follows:
```bash
./pipex infile cmd1 cmd2 outfile
```

The syntax is the same as:
```bash
< infile cmd1 | cmd2 > outfile
```

To add an option to the command, place it in quotes as follows:

```bash
./pipex README.md "grep is" "wc -l" outfile
```

If you want to try out my small tester script, execute the following command:
```bash
make test # if nothing appears, not problems were found
```

## What I learned

This project was a fun little one to do, I learned about how pipes really work, child and parent processes, file descriptors...

## Acknowledgements

- [holidaylvr's amazing videos](https://www.youtube.com/user/holidaylvr/videos)
- [Zeitoun's great blog post (french)](http://www.zeitoun.net/articles/communication-par-tuyau/start)

## Warning
The structure of this repository does **not** necessarily follow the guidelines.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
