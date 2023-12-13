#ifndef BEN_H
#define BEN_H
#define BUFSIZE 10240


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

void read_input(char *user);
void parse(char *buff);
void run(char *path, char **av);
int fwds(const char *str);
char *path_finder(char *file);
char *loc_finder(char *path, char *file);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
int _strlen(char *s);
char *_strdup(char *str);
char *_getline();
char *enter(char *string);
char *space(char *str);
void hashtag(char *buff);
void create_envi(char **envi);
void free_env(char **env);

#endif /* BEN_H */
