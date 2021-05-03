# ```ft_server```
```ft_server``` is a project which acts as an introduction to system administration. It consists of creating a web server with Nginx, in a docker container with the ability of running a WordPress website, phpMyAdmin and MySQL at the same time.

## How to use it
To use this project to create a Docker-based, phpMyAdmin and MySQL powered WordPress blog, simply execute the following commands in your command line tool (make sure to install Docker first).

Unzip the source files:
```bash
unzip srcs/utilities.zip -d srcs && rm -f srcs/utilities.zip
```
Build the image:
```bash
docker build -t ft_server .
```
Run the image:
```bash
docker run -it -p 80:80 -p 443:443 ft_server
```

## What I learned
I had been waiting for quite some time now for this project, as I was very interested in the use of Docker. And I wasn't disappointed. Docker is an insanely powerful tool. I truly love it. It has its risks, but if used correctly it can be very useful. Additionally, I also learned about how phpMyAdmin, WordPress and MySQL go hand in hand together.

## Acknowledgements
- Solal Dunckel's [ft_server](https://github.com/solaldunckel/ft_server)
- Romain Challie's [ft_server](https://github.com/rchallie/ft_server)
- Filippo Valsorda's [mkcert](https://github.com/FiloSottile/mkcert)

## Warning
The structure of this repository does **not** follow the guidelines.
The reason for this is to add some clarity in how the files are structured.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
