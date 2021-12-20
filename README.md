# 0x02. C - Shell v

## Concepts

###### For this project, students are expected to look at these concepts:

###### Everything you need to know to start coding your own shell (/concepts/64)

###### [EYNTK] - Shell v2 (/concepts/76)

```
 By Alexandre Gautier, Software Engineer at Holberton School
```
```
 Weight: 2
```
```
 Project to be done in teams of 2 people
```
```
 Ongoing project - started 12-14-2021, must end by 01-11-2022 (in 22 days) - you're done with 0 % of tasks.
```
```
 Checker will be released at 12-28-2021 12:00 AM
```
```
 Manual QA review must be done (request it when you are done with the project)
```
```
 QA review fully automated.
```
## 

#### (/)


## Resources

###### Read or watch :

###### Unix shell (/rltoken/bhsTFyMe10qXIvxlwkpnrw)

###### Thompson shell (/rltoken/_XqR7hikhAj-6ptcweOqXQ)

###### Ken Thompson (/rltoken/hcG6qRIeOtjfMBYIo5tt7w)

###### Interactive shells (/rltoken/lZxmum4XMYwC2j_8xul4yA)

###### Differences between lexers and parsers (/rltoken/i6Q2DeY25uv2twzmcvkBDA)

###### man or help :

```
sh
```
## 

#### (/)


## Learning Objectives

###### At the end of this project, you are expected to be able to explain to anyone

###### (/rltoken/MLAIfh4OOelPdSSZfCf0xA), without the help of Google :

### General

###### Who designed and implemented the original Unix operating system

###### Who wrote the first version of the UNIX shell

###### Who invented the B programming language (the direct predecessor to the C programming

###### language)

###### Who is Ken Thompson

###### How does a shell work

###### What are a pid and a ppid

###### How to manipulate the environment of the current process

###### What is the difference between a function and a system call

###### How to create processes

###### What are the three prototypes of main

###### How does the shell use the PATH to find the programs

###### How to execute another program with the execve system call

###### How to suspend the execution of a process until one of its children terminates

###### What is EOF / “end-of-file”?

###### How to redirect the content of a file into another file

###### What is a pipeline

###### How to setup a pipe

###### How to setup a pipe between two processes

## Requirements

### General

###### Allowed editors: vi, vim, emacs

###### All your files will be compiled on Ubuntu 14.04 LTS

###### Your C programs and functions will be compiled with gcc 4.8.

###### All your files should end with a new line

###### A README.md file, at the root of the folder of the project, is mandatory

###### A AUTHORS.md file, at the root of the folder of the project, is mandatory

###### Your code should use the Betty style. It will be checked using betty-style.pl

###### (https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and betty-doc.pl

###### (https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)

###### No more than 5 functions per file

###### All your header files should be include guarded

###### There shouldn’t be any error nor memory leak upon execution of your shell

### Allowed Functions and System Calls

```
access
chdir
```
## 

#### (/)


```
close
execve
fork
```
###### stat (__xstat)

###### lstat (__lxstat)

###### fstat (__fxstat)

```
kill
open
read
signal
wait
waitpid
wait
wait
write
_exit
dup
dup
pipe
unlink
time
gethostname
geteuid
sigaction
sigemptyset
select
getpid
```
###### __errno_location (errno macros)

```
closedir
exit
free
getcwd
getline
malloc
opendir
perror
readdir
strtok
localtime
getpwuid
isatty
printf
fflush
fprintf
vfprintf
sprintf
```
### Compilation

## 

#### (/)


###### You have to provide a Makefile in order to compile your program

###### Your Makefile must define the all rule: The all rule should compile and link the source code to

###### generate the executable hsh

###### Make sure your program compiles on Ubuntu 14.04 LTS, with gcc 4.8.

###### You must compile using the flags -Wall -Werror -Wextra and -pedantic

###### Your executable must be named: hsh

## More Info

### Output

###### Your shell will be auto-reviewed in non-interactive (/rltoken/lZxmum4XMYwC2j_8xul4yA) mode

###### (commands will be piped to it). Thereby, the prompt you print in interactive mode will not be taken

###### into account, so you are free to have the prompt of your choice.

###### Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as

###### well as the exact same error output.

###### The only difference is when you print an error, the name of the program must be equivalent to your

###### argv[0] (See below)

###### Example of error with sh:

```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
###### Same error with your program hsh:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
### Testing

###### Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
###### But also in non-interactive mode:

## 

#### (/)


```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_
$
$ cat test_ls_
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_
hsh main.c shell.c test_ls_
$
```
### Checks

###### We strongly encourage the entire class to work together to create a suite of checks covering both regular

###### tests and edged cases for each task

## Quiz questions

###### Show

## Tasks

##### 0. README, man, AUTHORS mandatory

###### Write a README

###### Write a man for your shell.

###### You should have an AUTHORS.md file at the root of your repository, listing all individuals having

###### contributed content to the repository. Format, see Docker (/rltoken/8vc-FUIu-wjWPghP9aTpPQ)

######  Done? Help

##### 1. Betty would be proud mandatory

###### Repo:

###### GitHub repository: shell_v

###### File: README.md, man_1_hsh, AUTHORS.md

## 

#### (/)


###### Write a beautiful code that passes the Betty checks

###### Be aware that every single C source file (*.c and *.h) inside your repository will be checked

######  Done? Help

##### 2. hsh 1.0 mandatory

###### Write a UNIX command line interpreter.

###### Usage: hsh

#### Your shell must:

###### Display a prompt and wait for the user to type a command. A command line always ends with a new

###### line.

###### The prompt is displayed again each time a command has been executed.

###### If an executable cannot be found, print an error message and display the prompt again.

###### Handle errors.

###### You have to handle the “end of file” condition (Ctrl+D)

###### Handle command lines with arguments

###### Handle and parse the PATH environment variable

#### Builtins

###### Implement the built-in command exit:

###### Your exit built-in must behave exactly like sh‘s

###### You have to handle arguments

###### Implement the built-in command cd:

###### Changes the current directory of the process.

###### Command syntax: cd [path]

###### If no argument is given to cd the command must be interpreted like cd $HOME

###### You have to handle the command cd -

###### You have to update the environment variable PWD when you change directory

###### Implement the built-in command env:

###### Prints the current environment

#### You don’t have to:

###### handle special characters : ", ', `, \, *, &, #

###### be able to move the cursor

###### handle pipes and redirections

###### Repo:

###### GitHub repository: shell_v

## 

#### (/)


#### IMPORTANT NOTE

###### A lot of checks will be performed for this task. Thus, the auto-review can take up to 5 minutes. Make sure to

###### test your code locally before launching the checker.

######  Done?^ Help

##### 3. hsh 1.1 mandatory

###### hsh 1.0 +

###### Handle the right stream redirection >

###### Usage: command > output_file

```
alex@~$ echo Holberton School > test
alex@~$ cat -e test
Holberton School$
alex@~$
```
###### You don’t have to handle the syntax: > output_file command

######  Done?^ Help

##### 4. hsh 1.1.1 #advanced

###### hsh 1.1 +

###### Handle the right stream redirection >

###### Usage: command n> output_file

###### Where n is the file descriptor of the file to redirect the output from

###### n is a number between 0 and 9

###### Repo:

###### GitHub repository: shell_v

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


```
alex@~$ echo Holberton School > test
alex@~$ cat -e test
Holberton School$
alex@~$ echo Holberton School 1> test
alex@~$ cat -e test
Holberton School$
alex@~$ echo Holberton School 2> test
alex@~$ cat -e test
alex@~$ ls /hbtn 2> test
alex@~$ cat -e test
ls: cannot access /hbtn: No such file or directory$
alex@~$
```
###### You don’t have to handle the syntax: n> output_file command

######  Done? Help

##### 5. hsh 1.2 mandatory

###### hsh 1.1 +

###### Handle the double right stream redirection >>

###### Usage: command >> output_file

```
alex@~$ rm -f test
alex@~$ echo Holberton School >> test
alex@~$ cat -e test
Holberton School$
alex@~$ echo Holberton School >> test
alex@~$ cat -e test
Holberton School$
Holberton School$
alex@~$
```
###### You don’t have to handle the syntax: >> output_file command

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


######  Done? Help

##### 6. hsh 1.3 mandatory

###### hsh 1.2 +

###### Handle the left stream redirection <

###### Usage: command < input_file

```
alex@~$ cat -e small_file
Holberton$
Second line$
alex@~$ rev < small_file
notrebloH
enil dnoceS
alex@~$
```
###### You don’t have to handle the syntax: < input_file command

######  Done?^ Help

##### 7. hsh 1.4 mandatory

###### hsh 1.3 +

###### Handle the double left stream redirection << (also known as heredoc)

###### Usage: command << delimiter

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


```
alex@~$ cat -e << HOLBERTON
> qwertyuiop
> ls -l
> cat -e small_file
> HOLBERTONnope
> nopeHOLBERTON
> HOLBERTON
> HOLBERTON
qwertyuiop$
ls -l$
cat -e small_file$
HOLBERTONnope$
nopeHOLBERTON$
HOLBERTON $
alex@~$
```
###### You don’t have to handle the syntax: << delimiter command

######  Done? Help

##### 8. hsh 1.5 mandatory

###### hsh 1.4 +

###### Handle the pipe stream redirection |

###### Usage: command1 | command

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


```
alex@~$ ls /var | rev
spukcab
ehcac
hsarc
bil
lacol
kcol
gol
liam
scirtem
tpo
nur
loops
pmt
alex@~$ ls -lr /var | cat -e
total 44$
drwxrwxrwt 2 root root 4096 Jul 5 10:26 tmp$
drwxr-xr-x 9 root root 4096 Feb 17 2016 spool$
lrwxrwxrwx 1 root root 4 Nov 19 2016 run -> /run$
drwxr-xr-x 2 root root 4096 Feb 17 2016 opt$
drwxrwsrwt 2 root whoopsie 4096 Feb 17 2016 metrics$
drwxrwsr-x 2 root mail 4096 Feb 17 2016 mail$
drwxrwxr-x 14 root syslog 4096 Jul 11 09:34 log$
lrwxrwxrwx 1 root root 9 Nov 19 2016 lock -> /run/lock$
drwxrwsr-x 2 root staff 4096 Apr 10 2014 local$
drwxr-xr-x 70 root root 4096 Mar 21 13:06 lib$
drwxrwsrwt 2 root whoopsie 4096 Jul 11 14:54 crash$
drwxr-xr-x 17 root root 4096 Feb 17 2016 cache$
drwxr-xr-x 2 root root 4096 Jul 11 09:33 backups$
alex@~$ echo "Holberton" | wc -c
10
alex@~$
```
######  Done? Help

##### 9. hsh 1.6 mandatory

###### hsh 1.5 +

###### Handle the commands separator ;

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


```
alex@~$ ls /var ; ls /var
backups cache crash lib local lock log mail metrics opt run spool tmp
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$ ls /hbtn ; ls /var
ls: cannot access /hbtn: No such file or directory
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$ ls /var ; ls /hbtn
backups cache crash lib local lock log mail metrics opt run spool tmp
ls: cannot access /hbtn: No such file or directory
alex@~$ ls /var ; ls /hbtn ; ls /var ; ls /var
backups cache crash lib local lock log mail metrics opt run spool tmp
ls: cannot access /hbtn: No such file or directory
backups cache crash lib local lock log mail metrics opt run spool tmp
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$
```
######  Done? Help

##### 10. hsh 1.7 mandatory

###### hsh 1.6 +

###### Handle the && logical operator

```
alex@~$ ls /var && ls /var
backups cache crash lib local lock log mail metrics opt run spool tmp
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$ ls /hbtn && ls /var
ls: cannot access /hbtn: No such file or directory
alex@~$ ls /var && ls /var && ls /var && ls /hbtn
backups cache crash lib local lock log mail metrics opt run spool tmp
backups cache crash lib local lock log mail metrics opt run spool tmp
backups cache crash lib local lock log mail metrics opt run spool tmp
ls: cannot access /hbtn: No such file or directory
alex@~$ ls /var && ls /var && ls /var && ls /hbtn && ls /hbtn
backups cache crash lib local lock log mail metrics opt run spool tmp
backups cache crash lib local lock log mail metrics opt run spool tmp
backups cache crash lib local lock log mail metrics opt run spool tmp
ls: cannot access /hbtn: No such file or directory
alex@~$
```
###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


######  Done? Help

##### 11. hsh 1.8 mandatory

###### hsh 1.7 +

###### Handle the || logical operator

```
alex@~$ ls /var || ls /var
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$ ls /hbtn || ls /var
ls: cannot access /hbtn: No such file or directory
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$ ls /hbtn || ls /hbtn || ls /hbtn || ls /var
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$ ls /hbtn || ls /hbtn || ls /hbtn || ls /var || ls /var
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
backups cache crash lib local lock log mail metrics opt run spool tmp
alex@~$
```
######  Done? Help

##### 12. hsh 2.0 mandatory

###### hsh 1.8 +

###### Implement the setenv and unsetenv builtin commands

```
setenv
```
###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


###### Initialize a new environment variable, or modify an existing one

###### Command syntax: setenv VARIABLE VALUE

###### Should print something on stderr on failure

```
unsetenv
```
###### Remove a environment variable

###### Command syntax: unsetenv VARIABLE

###### Should print something on stderr on failure

######  Done? Help

##### 13. Ctrl + C #advanced

###### hsh 1.0 +

###### Handle Ctrl+C: your shell should not quit when the user inputs ^C

###### man 2 signal.

```
julien@ubuntu:~/shell$ ./hsh
$ ^C
$ ^C
$ ^C
$ ls /var
backups cache crash lib local lock log mail metrics opt run snap spool
tmp
$ ^C
$ ^C
$ ^C
$ exit
julien@ubuntu:~/shell$
```
######  Done? Help

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


##### 14. Aliases #advanced

###### hsh 1.0 +

###### Implement the alias builtin command

###### Usage: alias [name[='value'] ...]

###### alias: Prints a list of all aliases, one per line, in the form name='value'

###### alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form

```
name='value'
```
###### alias name='value' [...]: Defines an alias for each name whose value is given. If name

###### is already an alias, replaces its value with value

######  Done?^ Help

##### 15. $VARIABLES #advanced

###### hsh 1.0 +

###### Handle variables replacement

###### Handle the $? variable

###### Handle the $$ variable

```
julien@ubuntu:~/shell$ ./hsh
$ ls /var
backups cache crash lib local lock log mail metrics opt run snap spool
tmp
$ echo $?
0
$ echo $$
5104
$ echo $PATH
/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/u
sr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
$ exit
julien@ubuntu:~/shell$
```
###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


######  Done? Help

##### 16. #Comments #advanced

###### hsh 1.0 +

###### Handle comments (#)

```
julien@ubuntu:~/shell$ ./hsh
$ echo Hello # ls -la
Hello
$ echo Hello#Holberton
Hello#Holberton
$ exit
julien@ubuntu:~/shell$
```
######  Done?^ Help

##### 17. Help! #advanced

###### hsh 1.0 +

###### Implement the help builtin command

###### Usage: help [BUILTIN]

######  Done? Help

##### 18. Move on #advanced

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


###### hsh 1.0 +

###### Implement the history builtin command, without any argument

###### The history builtin displays the history list, one command by line, preceded with line numbers

###### (starting at 0 )

###### On exit, write the entire history, without line numbers, to a file named .hsh_history in the

###### directory $HOME

###### When the shell starts, read the file .hsh_history in the directory $HOME if it exists, and set the first

###### line number of the current session to the total number of lines in the file modulo 4096

######  Done? Help

##### 19. Try to run this! #advanced

###### hsh 1.0 +

###### Usage: hsh [filename]

###### Your shell can take a file as a command line argument

###### The file contains all the commands that your shell should run before exiting

###### The file should contain one command per line

###### In this mode, the shell should not print a prompt and should not read from stdin

######  Done? Help

##### 20.. .hshrc #advanced

###### hsh 1.0 +

###### At startup, your shell must open the file .hshrc located in the $HOME directory, and execute it

###### Since this task requires only hsh 1.0, there won’t be any advanced content in .hshrc file during

###### the correction (no aliases, no redirections, ...)

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


```
alex@~/hsh_v2$ cat ~/.hshrc
echo "Holberton School"
```
```
echo 98 Battery St.
```
```
ls -l /var
alex@~/hsh_v2$ ./hsh
Holberton School
98 Battery St.
total 44
drwxr-xr-x 2 root root 4096 Jul 6 09:12 backups
drwxr-xr-x 17 root root 4096 Feb 17 2016 cache
drwxrwsrwt 2 root whoopsie 4096 Jul 6 10:03 crash
drwxr-xr-x 70 root root 4096 Mar 21 13:06 lib
drwxrwsr-x 2 root staff 4096 Apr 10 2014 local
lrwxrwxrwx 1 root root 9 Nov 19 2016 lock -> /run/lock
drwxrwxr-x 14 root syslog 4096 Jul 6 09:12 log
drwxrwsr-x 2 root mail 4096 Feb 17 2016 mail
drwxrwsrwt 2 root whoopsie 4096 Feb 17 2016 metrics
drwxr-xr-x 2 root root 4096 Feb 17 2016 opt
lrwxrwxrwx 1 root root 4 Nov 19 2016 run -> /run
drwxr-xr-x 9 root root 4096 Feb 17 2016 spool
drwxrwxrwt 2 root root 4096 Jul 5 10:26 tmp
$ exit
alex@~/hsh_v2$
```
######  Done?^ Help

##### 21. $PS1 #advanced

###### hsh 1.0 +

###### When executing interactively, your shell must displays the primary prompt PS1 when it is ready to

###### read a command

###### The PS1 variable can be customized by inserting a number of backslash-escaped special characters

###### You must handle the following backslash-escaped characters:

###### \d: The date in “Weekday Month Date” format (e.g., “Tue Feb 05”, “Sat Jul 26”)

###### \H: The hostname

###### \s: The name of the shell

###### \u: The username of the current user

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)


```
Copyright © 2021 Holberton Inc, All rights reserved.
```
###### \w: The current working directory, with $HOME abbreviated with a tilde (~)

###### You are free to implements more, but only the above will be checked.

######  Done? Help

###### Repo:

###### GitHub repository: shell_v

###### File: Makefile

## 

#### (/)
