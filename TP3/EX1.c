#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell
{
    int value;
    struct cell *next;
};
typedef struct cell cell;
typedef cell *list;

void addcell(int, list *);
list convert(char *);
list convertInv(char *);
int palindrome(char *);
int palindrome_opt(char *);

void addcell(int x, list *L)
{
    list C = (list)malloc(sizeof(cell));
    C->value = x;
    C->next = NULL;
    if (*L == NULL)
        *L = C;
    else
    {
        list temp = *L;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = C;
    }
    return;
}

list convert(char *word)
{

    list L = NULL;
    for (int j = 0; j < strlen(word); j++)
    {
        addcell(word[j], &L);
    }
    return L;
}

list convertInv(char *word)
{

    list L = NULL;
    for (int j = strlen(word) - 1; j >= 0; j--)
    {
        addcell(word[j], &L);
    }
    return L;
}

int palindrome(char *word)
{
    list L1 = convert(word);
    list L2 = convertInv(word);
    while (L1 != NULL)
    {
        if (L1->value != L2->value)
            return 0;
        L1 = L1->next;
        L2 = L2->next;
    }
    return 1;
}

int palindrome_opt(char *word)
{
    list L1 = convert(word);
    list L2 = convertInv(word);
    int l = 0;
    while (l < (strlen(word)) / 2 + 1)
    {
        if (L1->value != L2->value)
            return 0;
        L1 = L1->next;
        L2 = L2->next;
        l++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    printf("%d \n", argc);
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            printf("%c ", argv[i][j]);
        }
        printf("\n");
    }
    int a = palindrome(argv[1]);
    if (a == 1)
        printf("it is a palindrome");
    else
        printf("it is not a palindrome");
    printf("");
    return 0;
}
