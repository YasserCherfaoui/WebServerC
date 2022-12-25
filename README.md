# WebServerC
In this repo we explore a simple web server coded in C.
This web server handles **GET** and **HEAD** requests.
## How to use it?
There's already a binary form of the web server under the name **microweb** you can run it right away, but make sure that inside its working directory there is a `webroot` directory.
The `webroot` directory serves as the root directory of the web server, which means there you can put your HTML, CSS, JS files so that your web server can show some pages, otherwise you will end up facing **404** errors x).
## How to build it?
I made this software to be open source to you can modify on it and use for any purposes just don't forget to give the repo a star x).
This web server uses the port 80 in your machine which is obvious since it's a web server that communicates throughout HTTP, so in order to bind your socket to that port you need root permissions. Thus to compile this file run the following commands.
```
username@machine:~$ gcc -o SERVER_OUTPUT_FILE_NAME microweb.c
username@machine:~$ sudo chown root ./SERVER_OUTPUT_FILE_NAME
username@machine:~$ sudo chmod u+s ./SERVER_OUTPUT_FILE_NAME
```
finally run the server with the following command.
```
username@machine:~$ ./SERVER_OUTPUT_FILE_NAME
```
