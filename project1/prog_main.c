#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book {
  char **name;
  char **author;
  char **username;
  char **bookid;
  int **index; // created index for deleting purpose
  int size;    // created size for calculating the inserted books
};

struct user {
  char **uname;
  char **uid;
  int size; //// created size for calculating the inserted customers
};

void add(struct book *);
void display(struct book *);
void delete (struct book *);
void search(struct book *);

void add_customer(struct user *);
void display_customer(struct user *);
void delete_customer(struct user *);
void search_customer(struct user *);

int main() {
  int choice = 1;

  struct book book_lib;
  struct user user_lib;
  // allocating the space for library
  book_lib.name = (char **)calloc(15, sizeof(char));
  book_lib.author = (char **)calloc(15, sizeof(char));
  book_lib.username = (char **)calloc(15, sizeof(char));
  book_lib.bookid = (char **)calloc(15, sizeof(char));
  book_lib.index = (int **)calloc(20, sizeof(int));

  // allocating the space for user
  user_lib.uname = (char **)malloc(15 * sizeof(char));
  user_lib.uid = (char **)malloc(15 * sizeof(char));
  user_lib.size = 0;

  while (1) {
    printf("\n1 Book addition \n2 Book deletion \n3 Display books \n4 Search book \n5 Add customer \n6 Display customer \n7 Search customer \n8 Delete customer \n9 Exit \nEnter your choice ");
    scanf("%d", &choice);
    if (choice == 1) {
      add(&book_lib);
    }
    if (choice == 2) {
      delete (&book_lib);
    }
    if (choice == 3) {
      display(&book_lib);
    }
    if (choice == 4) {
      search(&book_lib);
    }
    if (choice == 5) {
      add_customer(&user_lib);
    }
    if (choice == 6) {
      display_customer(&user_lib);
    }
    if (choice == 7) {
      search_customer(&user_lib);
    }
    if (choice == 8) {
      delete_customer(&user_lib);
    }
    if(choice ==9)
    {
        break;
    }

    printf("\n");
  }

  return 0;
}

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

void add_customer(struct user *p) {
  for (int i = p->size; i <= p->size; i++) {
    printf("Enter the name of Customer :");
    p->uname[i] = (char *)malloc(15 * sizeof(char));
    scanf("%s", p->uname[i]);

    printf("Enter the id of Customer :");
    p->uid[i] = (char *)malloc(15 * sizeof(char));
    scanf("%s", p->uid[i]);
  }
  p->size = p->size + 1;
}

void display_customer(struct user *p) {
  printf("Now we are displaying the customer details \n");
  printf("%d", p->size);
  for (int i = 0; i < p->size; i++) {
    printf("The Name of Customer : %s", p->uname[i]);
    printf("\nThe Customer id is   : %s ", p->uid[i]);
    printf("\n");
  }
}

void delete_customer(struct user *p) {
  printf("Enter the name of customer to remove from the Database\n");
  char *namee = (char *)malloc(15 * sizeof(char));
  scanf("%s", namee);
  for (int i = 0; i < p->size; i++) {
    if (strcmp(p->uname[i], namee) == 0) {
      p->uname[i] = p->uname[i + 1];
    }
    p->size = p->size - 1;
  }
}

void search_customer(struct user *p) {
  printf("Enter the name of customer to be searched \n");
  char *custo;
  custo = (char *)calloc(15, sizeof(char));
  getchar();
  scanf("%s", custo);
  int sizee;
  printf("%s", custo);
  for (int i = 0; i < p->size; i++) {
    if (strcmp(p->uname[i], custo) == 0) {
      sizee = i + 1;
      printf("The customer is found at %d index\n", sizee);
    } else {
      printf("No user found \n");
    }
  }
}

