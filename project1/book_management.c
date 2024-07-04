#include<stdio.h>
#include"functions.h"

void add(struct book *p) {

  for (int i = p->size; i <= p->size; i++) {
    printf("Enter the name of book :");
    p->name[i] = (char *)calloc(15, sizeof(char));
    scanf("%s", p->name[i]);

    printf("Enter the name of author :");
    p->author[i] = (char *)calloc(15, sizeof(char));
    getchar();
    scanf("%s", p->author[i]);

    printf("Enter the Username:");
    p->username[i] = (char *)calloc(15, sizeof(char));
    scanf("%s", p->username[i]);

    printf("Enter the bookid :");
    p->bookid[i] = (char *)calloc(15, sizeof(char));
    scanf("%s", p->bookid[i]);

    p->index[i] = p->index[i] + 1;
  }
  p->size = p->size + 1;
}

void display(struct book *p) {
  printf("\nThe books added to library are : \n");
  for (int i = 0; i < p->size; i++) {
    printf("The name of the book: %s\n", p->name[i]);
    printf("The author name : %s\n", p->author[i]);
    printf("The User name : %s\n", p->username[i]);
    printf("The book id: %s\n", p->bookid[i]);
    printf("\n");
  }
}
void delete (struct book *p) {
  printf("Enter the index to delete \n");
  int indexx;
  scanf("%d", &indexx);
  for (int i = indexx; i < p->size - 1; i++) {
    p->name[i] = p->name[i + 1];
    p->author[i] = p->author[i + 1];
    p->username[i] = p->username[i + 1];
    p->bookid[i] = p->bookid[i + 1];
    printf("\n");
  }
  p->size = p->size - 1;
}

void search(struct book *p) {
  printf("Enter the book to be searched \n");
  char *book_name;
  book_name = (char *)calloc(15, sizeof(char));
  scanf("%s", book_name);
  int search;
  for (int i = 0; i < p->size; i++) {
    if (strcmp(p->name[i], book_name) == 0) {
      search = i;
      printf("The book is at %d index\n", search + 1);
    } else {
      printf("Book not found \n");
    }
  }
}

