#include<stdio.h>
#include"functions.h"

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

