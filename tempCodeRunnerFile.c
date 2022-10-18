
/////////code ADI/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#define n 10

struct tampon_cir{
int contents[n]; /*buffer area*/
int head ;  /*head index*/
int tail;  /*tail index*/
    };

void error(){
printf("Error !");
}

typedef struct tampon_cir pile;

void write(int data,pile *s)
{
    if ((s->tail+1) % n ==s->head)
        error(); /* buffer overflow */
    else
    {
        s->contents[s->tail]= data;
        s->tail =(s->tail+1) % n; /* update tail */
        printf("Le caractere ecrit est : %d\n",data);
    }
}

void read(pile *s)
{
    int data;
    if (s->head ==s->tail)

        data =NULL; /* buffer underflow */
    else
    {
        data =s->contents[s->head]; /* read data */
        s->head=(s->head+1) % n; /* update head */
        printf("Le caractere lu est : %d\n",data);
    }

}




int main()
{
 int choix = 0;
 pile p;

 printf("Enter 1 for Read 2 for Write and 3 for Exit: ");
 scanf("%d",&choix);
 for (int i=0; i < n; i++)
    p.contents[i] = 0;
while (choix != 3){
     switch (choix){

         case 1:
            int data;
            printf("Enter  ");
            scanf("%d",&data);

            write(data,&p);

            break;
         case 2:
            read(&p);


            break;
         case 3:
            break;
         default:
            return 0;
            break;

     }
    for (int i=0; i < n; i++)
        printf("LE contenu [%d]: %d\n",i,p.contents[i]);
    printf("Enter 1 for Read 2 for Write and 3 for Exit: ");
     scanf("%d",&choix);
}


 printf("FIN");
}