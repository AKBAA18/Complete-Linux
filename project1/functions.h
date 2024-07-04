#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Library management structure 
struct book {
  char **name;
  char **author;
  char **username;
  char **bookid;
  int **index; // created index for deleting purpose
  int size;    // created size for calculating the inserted books
};

//Book management structure 
struct user {
  char **uname;
  char **uid;
  int size; // created size for calculating the inserted customers
};

void add(struct book *);
void display(struct book *);
void delete (struct book *);
void search(struct book *);

void add_customer(struct user *);
void display_customer(struct user *);
void delete_customer(struct user *);
void search_customer(struct user *);

