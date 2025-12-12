_This project has been created as part of the 42 curriculum by msuizu_

**--- Description ---**

get_next_line is a function that returns the readed line from a file descriptor. it got the BUFFER_SIZE set by the user or by
default defined at '1000', that represents the number of size 'read()' is allowed to.. read.

**--- Instructions ---**

check with 'norminette', add a main.c or uncomment the main in get_next_line.c then
compile with 'cc -Wall -Werror -Wextra', and if you would like to set the value of BUFFER_SIZE, 
add the option '-D BUFFER_SIZE={nb of your choice beside negative value}'

**--- Resources ---**

functionning of the file descriptor https://www.codequoi.com/manipuler-un-fichier-a-laide-de-son-descripteur-en-c/ | no ai

**--- Technical choices ---**

#get_next_line.c : contains prototype of get_next_line and 4 other helper functions + commented main

\#get_next_line_utils.c : contains 5 more helper functions coded before from libft (strjoin, calloc, strchr, strdup, strndup)

\#get_next_line.h : header file

get_next_line read each time at least one time the size of BUFFER_SIZE and if needed, read while '\n' is not encountered and
while read's return value is superior to 0. a static variable 'next' is used to store excess readen caracters. at first
get_next_line allocate memory to 'buffer', and if 'next' is not empty, the contained caracters are added, and finally the
variable that checks read's return value is set to 1 to enter in the first while loop. when '\n' or '\0' is reached, read()
stops, the caracters in excess are stocked in the static, and returns the readed line.