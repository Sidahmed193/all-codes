// HW__STR_TP1
//  homework --- STR ----------------------------------

#include <stdio.h>
#define n 10

typedef struct tampon_cir
{
    int contents[n]; // buffer area
    int head;        // head index
    int tail;        // tail index
};

void error()
{
    printf("\n ERROR !!!");
}
void write(int data, stack *s)
{
    if ((s->tail + 1) % n == (s->head))
        error(); // buffer overflow
    else
    {
        s->contents[s->tail] = data;
        s->tail = data;
        s->tail = (s->tail + 1) % n; // update tail
        printf("Le caractère écrit est : %c\n", data);
    }
}

void read(stack *s)
{
    if (s->head == s->tail)

        data = NULL; // buffer underflow
    else
    {
        //data = s->contents + s->head; // read data
        int temp=s->contents;
        s->head = (s->head + 1) % n;  // update head
        printf("Le caractère lu est : %c\n", temp);
    }
}

int main()
{
    int data = 0;
    int input = 0;
    stack stk;
    printf("------------------------------------------\n");
    printf(" 1 --> RESET \n");
    printf(" 2 --> PUSH \n");
    printf(" 3 --> POP \n");
    printf(" 4 --> EXIT \n");
    printf("------------------------------------------\n");
    scanf("%d", &input);
    switch (m)
    {
        case 1;

               break;

        case 2;
          printf("enter a value :\n");
          scanf("%d", &input);
          write(input,&stk);
          read(&stk);
        break;



    return 0;
    }
}


/*
// LIFO STACK
#include <stdio.h>
#define MAX 10
#define EMPTY 0
#define FULL (MAX - 1)

typedef struct stack
{
    int s[MAX];
    int top;
} stack;
void reset(stack *stk)
{
    stk->top = EMPTY;
}
void push(int c, stack *stk)
{
    stk->s[stk->top] = c;
    //printf("xx%d\n", stk->s[stk->top]);
    stk->top++;
}
int pop(stack *stk) {
    //printf("%d",*stk->s[stk->top]);
    return (stk->s[stk->top-1]);
    }
int top(const stack *stk) { return (stk->s[stk->top]); }
int is_empty(const stack *stk) { return (stk->top == EMPTY); }
int is_full(const stack *stk) { return (stk->top == FULL); }

int print_stack(stack *stk)
{
    int temp = 0;
    stack stack_temp;
    for (int i = 0; i < stk->top; i++)
    {
        temp = pop(stk);
        printf("%d \n", temp);
        push(temp, &stack_temp);
    }
    for (int i = 0; i < stack_temp.top; i++)
    {
        temp = pop(&stack_temp);
        push(temp, stk);
    }
}
int main()
{
    int input = 0;
    stack stack_of_int;
    reset(&stack_of_int);
    while (1)
    {
        int command;
        // printf("Please enter a commande \n 1-reset \t 5-exit  \n 2-push \n 3-pop   \n");
        printf("------------------------------------------\n");
        printf(" 1 --> RESET \n");
        printf(" 2 --> PUSH \n");
        printf(" 3 --> POP \n");
        printf(" 4 --> EXIT \n");
        printf("------------------------------------------\n");
        scanf("%d", &command);
        if (command == 2)
        {
            printf("Please Ender a number to the stack :");
            scanf("%d", &input);
            //printf("AA%d\n", input);
            push(input, &stack_of_int);
            print_stack(&stack_of_int);
        }
        else if (command == 1)
        {
            reset(&stack_of_int);
        }
        else if (command == 4)
        {
            break;
        }
        else if (command == 3)
        {
        }

    }


    return 0;
}
*/

/*
        /////////code ADI/////////////////////////////////////////////

        #include <stdio.h>
        #include <stdlib.h>
        #define n 10

        struct tampon_cir{
        int contents[n]; //buffer area
        int head ;  //head index
        int tail;  //tail index
            };

        void error(){
        printf("Error !");
        }

        typedef struct tampon_cir pile;

        void write(int data,pile *s)
        {
            if ((s->tail+1) % n ==s->head)
                error(); // buffer overflow
            else
            {
                s->contents[s->tail]= data;
                s->tail =(s->tail+1) % n; // update tail
                printf("Le caractere ecrit est : %d\n",data);
            }
        }

        void read(pile *s)
        {
            int data;
            if (s->head ==s->tail)

                data =NULL; // buffer underflow
            else
            {
                data =s->contents[s->head]; // read data
                s->head=(s->head+1) % n; // update head
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
        */