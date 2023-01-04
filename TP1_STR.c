// PILE
/*
#include <stdio.h>
#include <stdlib.h>
#define n 10

struct tampon_cir
{
    int contents[n]; //buffer area
    int pointeur;    // index
};

void error()
{
    printf("\n==> Error ! : LA PILE EST PLEINE \n\n");
}

typedef struct tampon_cir pile;

void write(int data, pile *s)
{
    if ((s->pointeur) >= n)
        error(); // buffer overflow 
    else
    {
        printf("\n=> Enter un nombre: ");
        scanf("%d", &data);
        s->contents[s->pointeur] = data;
        printf("\n=> Le nombre ecrit est : %d\n\n", data);
        if (s->pointeur <= n)
            s->pointeur++;
    }
}

void read(pile *s)
{
    int data;
    if (s->contents[0] == NULL)
    {
        printf("\n==> LA PILE EST VIDE \n\n"); // buffer underflow 
    }
    else
    {
        if (s->pointeur > 0)
            s->pointeur--;
        data = s->contents[s->pointeur]; // read data 
        printf("\n=> Le nombre lu est : %d\n\n", data);
        data = NULL;
        s->contents[s->pointeur] = data;
    }
}

int main()
{
    int choix = 0;
    pile p;
    p.pointeur = 0;
    printf(">> Enter 1 for [ WRITE ] 2 [ READ ] for and 3 for Exit: ");
    scanf("%d", &choix);
    for (int i = 0; i < n; i++)
        p.contents[i] = NULL;
    while (choix != 3)
    {
        switch (choix)
        {
        case 1:
            int data = 0;
            write(data, &p);

            break;
        case 2:
            read(&p);

            break;
        case 3:
            break;
        default:
            break;
        }
        for (int i = 0; i < n; i++)
            printf("LE contenu [%d]: %d\n", i, p.contents[i]);
        printf("\n");
        printf("\N## Pointeur : %d\n", p.pointeur);
        printf(">> Enter 1 for [ WRITE ] 2 [ READ ] for and 3 for Exit: ");
        scanf("%d", &choix);
    }

    printf("\n<< FIN >>");
}


*/
/*
// anneau

#include <stdio.h>
#include <stdlib.h>
#define n 10

struct tampon_cir
{
    int contents[n]; //buffer area
    int head;        //head index
    int tail;        //tail index
};

void error()
{
    printf("\n==> Error ! : ANNEAU IS FULL \n\n");
}

typedef struct tampon_cir anneau;

void write(int data, anneau *s)
{
    if ((s->tail) == (s->head) && (s->contents[(s->head)] != NULL))
        error(); // buffer overflow 
    else
    {
        printf("\n=> Enter un nombre: ");
        scanf("%d", &data);
        s->contents[s->tail] = data;
        printf("\n=> Le nombre ecrit est : %d\n\n", data);
        if (s->tail < n - 1)
            s->tail++;
        else
            s->tail = 0;
    }
}

void read(anneau *s)
{
    int data;
    if (s->tail == s->head && (s->contents[(s->head)] == NULL))
    {
        printf("\n==> Buffer underflow\n\n"); // buffer underflow 
    }
    else
    {
        data = s->contents[s->head]; // read data 
        printf("\n=> Le nombre lu est : %d\n\n", data);
        data = NULL;
        s->contents[s->head] = data;
        if (s->head < n - 1)
            s->head++;
        else
            s->head = 0;
    }
}

int main()
{
    int choix = 0;
    anneau a;
    a.head = 0;
    a.tail = 0;
    printf(">> Enter 1 for [ WRITE ] 2 [ READ ] for and 3 for Exit: ");
    scanf("%d", &choix);
    for (int i = 0; i < n; i++)
        a.contents[i] = NULL;
    while (choix != 3)
    {
        switch (choix)
        {
        case 1:
            int data = 0;
            write(data, &a);

            break;
        case 2:
            read(&a);

            break;
        case 3:
            break;
        default:
            break;
        }
        for (int i = 0; i < n; i++)
            printf("LE contenu [%d]: %d\n", i, a.contents[i]);
        printf("\n");
        printf("## Tail : %d\n", a.tail);
        printf("## Head : %d\n", a.head);
        printf(">> Enter 1 for [ WRITE ] 2 [ READ ] for and 3 for Exit: ");
        scanf("%d", &choix);
    }

    printf("<< FIN >>");
}
*/

// FILE

#include <stdio.h>
#include <stdlib.h>
#define n 10

struct tampon_cir
{
    int contents[n]; //buffer area
    int head;        //head index
    int tail;        //tail index
};

void error()
{
    printf("\n==> Error ! : LA FILE EST PLEINE \n\n");
}

typedef struct tampon_cir file;

void write(int data, file *s)
{
    if (s->contents[s->head] != NULL)
        error(); // buffer overflow 
    else
    {
        printf("\n=> Enter un nombre: ");
        scanf("%d", &data);
        s->contents[s->head] = data;
        printf("\n=> Le nombre ecrit est : %d\n\n", data);
        if (s->head < n - 1)
            s->head++;
        else
            s->head = 0;
    }
}

void read(file *s)
{
    int data;
    if (s->contents[s->tail] == NULL)
    {
        printf("\n==> LA FILE EST VIDE \n\n"); // buffer underflow 
    }
    else
    {
        data = s->contents[s->tail]; // read data 
        printf("\n=> Le nombre lu est : %d\n\n", data);
        data = NULL;
        s->contents[s->tail] = data;
        if (s->tail < n - 1)
            s->tail++;
        else
            s->tail = 0;
    }
}

int main()
{
    int choix = 0;
    file f;
    f.head = 0;
    f.tail = 0;
    printf(">> Enter 1 for [ WRITE ] 2 [ READ ] for and 3 for Exit:  ");
    scanf("%d", &choix);
    for (int i = 0; i < n; i++)
        f.contents[i] = NULL;
    while (choix != 3)
    {
        switch (choix)
        {
        case 1:
            int data = 0;
            write(data, &f);

            break;
        case 2:
            read(&f);

            break;
        case 3:
            break;
        default:
            break;
        }
        for (int i = 0; i < n; i++)
            printf("LE contenu [%d]: %d\n", i, f.contents[i]);
        printf("\n");
        printf("## Head : %d\n", f.head);
        printf("## Tail : %d\n", f.tail);
        printf("\n>> Enter 1 for [ WRITE ] 2 [ READ ] for and 3 for Exit:  ");
        scanf("%d", &choix);
    }

    printf("\n<< FIN >>");
}
