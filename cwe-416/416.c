#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char name[160];
};

void free_list(struct node *head)
{
    for (struct node *p = head; p != NULL; p = p->next) {
        free(p);
    }
}

int main()
{
    //struct node n1;
    //struct node n2;

    struct node* n1 = malloc(sizeof(struct node));
    struct node* n2 = malloc(sizeof(struct node));

    strcpy(n1->name, "1");
    n1->next = n2;

    strcpy(n2->name, "2");

    free_list(n1);
}
