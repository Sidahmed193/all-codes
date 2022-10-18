
/*
soritng merge sort
0(n log n) efficient
sally coder march 18,2018
*/
/*
#include<stdio.h>
void print_array(int how_many, int data[],char  *str)
{
  int i;
  printf("%s",str);
  for(i=0;i<how_many;i++)
  printf("%d\t",data[i]);
}

void merge(int a[],int b[],int c[],int how_many)
{
  int i=0,j=0,k=0;
  while(i<how_many && j<how_many)
  if(a[i]<b[j])
  c[k++]=a[i++];
  else
  c[k++]=b[j++];
  while(i<how_many)
  c[k++]=a[i++];
  while(j<how_many)
  c[k++]=b[j++];

}
int main(void)
{
  const int SIZE=5;
  int a [SIZE]={67,82,83,88,99};
  int b [SIZE]={58,69,72,81,88};
  int c[2*SIZE];
  print_array(SIZE,a,"My grades\n");
  printf("\n\n");
  print_array(SIZE,b,"More grades\n");
  printf("\n\n");
  print_array(2*SIZE,c,"My sorted grades\n");
  printf("\n\n");
  return 0;
}
*/
/*
#include<stdio.h>
//int i=0,j=1,k=2;
//int a=2;
int b=6;
int c=3;
int d=1;
//int r=0;
/*
int mystery(int p, int q){

    int r;
    if ((r = p % q) == 0)
        return q;
    else return mystery(q, r);
}
*/
/*
int a[10] = {1,2,3,4,5,6,7,8,9,10}, i = 6 ;
int *p = &a[0];



void main(){
   printf("%d\n", *(p + i));
  //r=b=a=c;
  //r=(i&&(j=k))||(k>j);
  //printf("r =%f\n",r);
  //printf("r =%d",a);
 // printf("HELLO\tWORLD\n");
}
*/

/*--------------------------------------------------------------------------------------------------------------------------------------
Coursera course c & c++
****** enumerated types********
*/
/*
#include <stdio.h>

enum day
{
  sun,
  mon,
  tue,
  wed,
  thu,
  fri,
  sat
}; // declare type

void print_day(enum day d)
{
  switch (d)
  {
  case sun:
    printf("sunday");
    break;
  case mon:
    printf("monday");
    break;
  case tue:
    printf("tuesday");
    break;
  case wed:
    printf("wednesday");
    break;
  case thu:
    printf("thursday");
    break;
  case fri:
    printf("friday");
    break;
  case sat:
    printf("saturday");
    break;
  default:
    printf("%d is an error", d);
    break;
  }
}
enum day next_day(enum day d)
{
  return (d + 1 % 7);
}
enum day previous_day(enum day d)
{
  return (d - 1 % 7);
}
int main()
{
  enum day today = wed;
  print_day(today);
  printf("\n\n");
  print_day(7);
  printf("\n\n");
  print_day(next_day(today));
  printf("\n\n");
  print_day(previous_day(today));
  return 0;
}
*/

/* use of Macro's preprocessor code */
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEPHANT_SEAL_WT_MALE 8800
#define MIN_ELEPHANT_SEAL_WT_MALE 4400

//note that female range is 880-2000 lbs

//produce macro that randomly generates a male weight

#define RANGE 4400
#define POPULATION 1000
#define WEIGHT_OVER rand() % RANGE
#define WEIGHT WEIGHT_OVER + MIN_ELEPHANT_SEAL_WT_MALE
#define FILL                       \
  for (i = 0; i < POPULATION; i++) \
  data[i] = WEIGHT
void print_data(int d[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d\t", d[i]);
    if ((i + 1) % 10 == 0)
      printf("\n");
  }
}
int main()
{
  int i;
  int data[POPULATION];
  srand(time(0));
  FILL;
  print_data(data, POPULATION);
  printf("\n\n");
  return 0;
}
*/

// ******************* asserts ************
/*
#define NDEBUG
#include <stdio.h>
#include <assert.h>

int main()
{

  double x, y = 0;

  while (1)
  {
    printf("please enter 2 numbers");
    scanf("%lf %lf",&x, &y);
    assert(y != 0);
        printf("X / Y equals to : %lf \n", x/y);
  }
  return 0;
}
*/
/*
#include <stdio.h>

int main()
{
    enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

    enum month next_month(enum month m)
    {
        return((m + 1) % 12);
    }

    printf("%u\n", next_month(dec));

    return 0;
}

*/

// THE ADT STACK

#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack
{
  char s[MAX_LEN];
  int top;
}
stack;

void reset(stack *stk) { stk->top = EMPTY; }

void push(char c, stack *stk)
{
  stk->top++;
  stk->s[stk->top] = c;
}
char pop(stack *stk) { return (stk->s[stk->top--]); }
char top(const stack *stk) { return (stk->s[stk->top]); }

int is_empty(const stack *stk) { return (stk->top == EMPTY); }
int is_full(const stack *stk) { return (stk->top == FULL); }

int main()
{
  stack stack_of_char;
  char *str = "i am otto am i";
  char str_back[20];
  int i = 0;
  reset(&stack_of_char);
  printf("original is : %s\n", str);
  while (str[i] != '\0')
  {
    printf("%c\n", str[i]);
    push(str[i++], &stack_of_char);
  }
  i = 0;
  while (!is_empty(&stack_of_char) && i < 20)

    str_back[i++] = pop(&stack_of_char);
    printf("reverse is : %s\n", str_back);
    printf("\n\n");
    return 0;

}
*/

// using struct assignment
/*
#include <stdio.h>
#define MAX_DAY 31

typedef enum month
{
  jan,
  feb,
  mar,
  apr,
  may,
  jun,
  jul,
  aug,
  sep,
  oct,
  nov,
  dec
} month;
typedef struct date
{
  month m;
  int d
} date;

void print_month(enum month m)
{
  switch (m)
  {
  case jan:
    printf("January");
    break;
  case feb:
    printf("February");
    break;
  case mar:
    printf("March");
    break;
  case apr:
    printf("April");
    break;
  case may:
    printf("May");
    break;
  case jun:
    printf("June");
    break;
  case jul:
    printf("July");
    break;
  case aug:
    printf("August");
    break;
  case sep:
    printf("September");
    break;
  case oct:
    printf("October");
    break;
  case nov:
    printf("November");
    break;
  case dec:
    printf("December");
    break;
  default:
    printf("%d is an error", m);
    break;
  }
}
void next_day(day)
{
  day = day + 1 % 31;
  printf("    %d\n\n", day);
}
void printdate(date)
{

  if (month == jan || month == mar || month == may || month == jul || month == aug || month == oct || month == dec)
  {
    MAX_DAY = 31;
    print_month(m);
    printf("    %d \n\n", d);

    if (d > 31)
    {
      MAX_DAY = 0;
      month = month + 1 % 12;
    }
  }
}
int main()
{
  enum month m = dec;
  int day = 12;
  print_month(m);
  printf("    %d \n\n", day);
  print_month(m);
  next_day(day);
  return 0;
}
*/
/*
//typedef float DOLLARS;
#define DOLLARS float
int main(void)
{
  DOLLARS amount = 100.0, interest = 0.07 * amount;
  printf("DOLLARS = %.2f\n", amount + interest);
  return 0;
}
*/

/*
//typedef float DOLLARS;
#define DOLLARS float
int main(void)
{
  DOLLARS amount = 0.0,
          interest = 0.07 * amount;
  {                                      // new block
    float DOLLARS;
    DOLLARS = amount + interest;
    printf("DOLLARS = %.2f\n", DOLLARS);
  }
  return 0;
}
*/
/*
// typedef char *string;
#define string char *
int main(void)
{

  string a[] = {"I", "like", "to", "fight, "},
         b[] = {"pinch,", "and", "bite."};
  printf("%s %s %s %s %s %s %s\n", a[0], a[1], a[2], a[3], b[0], b[1], b[2]);
  return 0;
}
*/
/*
#include <stdio.h>
typedef enum month
{
  jan,
  feb,
  mar,
  apr,
  may,
  jun,
  jul,
  aug,
  sep,
  oct,
  nov,
  dec
} month;

typedef struct date
{
  month m;
  int d;
} date;

 void get_date(date.a)
{
  date a;
  printf("please enter a date without year for example jan 12 :");
  scanf("%d %d", m, d);
  a.m=m;
  a.d=m;
}

int main()
{
  date a;
  //get_date(date.a);
  a.m=7;
  a.d = 27;
  printf("%d %d", a.m,a.d);
  return 0;
}
*/
/*
#include<stdio.h>


int main(){
int test[]= {1,2,3};


}
*/
/*
// list of one element code

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list
{
  int data;
  struct list *next;
} list;
int is_empty(const list *h, char *title)
{
  printf("%s\n", title);
  while (h != NULL)
  {
    printf("%d :", h->data);
        h = h->next;
  }
}
void print_list(list *h, char *title)
{
  printf("%s\n",title);
  while(h != NULL){
    printf("%d :",h ->data);
    h=h-> next;
  }
}
int main()
{
  list list_of_int;
  list *head = NULL;
  head = malloc(sizeof(list));
  printf("sizeof(list) =%lu\n", sizeof(list)); // unsigned long
  head->data = 5;
  head->next = NULL;
  print_list(head, "single element list");
  printf("\n\n");
  return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


typedef struct list
{
  int data;
  struct list *next;
} list;

void srand( unsigned seed );int i;

list *create_list(int d)
{
  for (i = 0; i <= 100; i++)
  {
    list *head = malloc(sizeof(list));
    head->data = srand()%100;
    head->next = NULL;
    return head;
  }
}

*/
/*
// C program to implement Bubble Sort on singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//structure for a node
struct Node
{
  int data;
  struct Node *next;
};

void fill_random(int array[], int length, int max);
//Function to insert a node at the beginning of a linked list
void insertAtTheBegin(struct Node **start_ref, int data);

// Function to bubble sort the given linked list
void bubbleSort(struct Node *start);

// Function to swap data of two nodes a and b
void swap(struct Node *a, struct Node *b);

// Function to print nodes in a given linked list
void printList(struct Node *start);

int main()
{
  srand(time(NULL));
  // int arr[] = {12, 56, 2, 11, 1, 90};
  int list_size, i;
  int a[100];
  fill_random(a, 100, 300);
  // start with empty linked list
  struct Node *start = NULL;

  // Create linked list from the array arr[].
   // Created linked list will be 1->11->2->56->12
  for (i = 0; i < 101; i++)
    insertAtTheBegin(&start, a[i]);

  // print list before sorting
  printf("\n\n Linked list before sorting :\n");
  printList(start);

  // sort the linked list //
  bubbleSort(start);

  // print list after sorting
  printf("\n\n Linked list after sorting :\n");
  printList(start);

  getchar();
  return 0;
}

void fill_random(int array[], int length, int max)
{
  for (int i = 0; i < length; i++)
  {
    array[i] = (rand() % max) + 1; // fills array from 1 to max
  }
}

// Function to insert a node at the beginning of a linked list
void insertAtTheBegin(struct Node **start_ref, int data)
{
  struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
  ptr1->data = data;
  ptr1->next = *start_ref;
  *start_ref = ptr1;
}

// Function to print nodes in a given linked list
void printList(struct Node *start)
{
  int numbers = 0;
  struct Node *temp = start;
  // printf("");
  while (temp != NULL)
  {

    printf("  %d  ", temp->data);
    temp = temp->next;
    if (numbers >= 5)
    {
      printf("\n");
      numbers = 0;
    }
    numbers++;
  }
}

// Bubble sort the given linked list
void bubbleSort(struct Node *start)
{
  int swapped, i;
  struct Node *ptr1;
  struct Node *lptr = NULL;

  // Checking for empty list
  if (start == NULL)
    return;

  do
  {
    swapped = 0;
    ptr1 = start;

    while (ptr1->next != lptr)
    {
      if (ptr1->data > ptr1->next->data)
      {
        swap(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

// function to swap data of two nodes a and b
void swap(struct Node *a, struct Node *b)
{
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

int is_empty(const list *l) { return (l == NULL); };

void srand( unsigned seed );int i;

list *create_list(int d)
{
  for (i = 0; i <= 100; i++)
  {
    list *head = malloc(sizeof(list));
    head->data = srand()%100;
    head->next = NULL;
    return head;
  }
}
list *add_to_front(int d, list *h)
{
  list *head = create_list(d);
  head->next = h;
  return head;
}
void print_list(list *h, int d)
{
  printf("%d\t", d);
  while (h != NULL)
  {
    printf("%d :", h->data);
    h = h->next;
  }
}
int main()
{
  list list_of_int;
  list *head = NULL;
  head = malloc(sizeof(list));
  printf("sizeof(list) =%lu\n", sizeof(list)); // unsigned long
  print_list(head,"single element list");
  printf("\n\n");
  return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *newNode(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;;
    return new_node;
}

node *insert_node(node *root, int data) {
    if (root == NULL)
        return newNode(data);
    else {
        node *cur;
        cur = insert_node(root->next, data);
        root->next = cur;
    }
    return root;
}

void print(node *np) {
    if (np) {
        printf("(%d)", np->data);
        print(np->next);
    }
}

int main() {
    int T = 100;
    node *root = NULL;
    while (T-- > 0) {
        int r = rand() % 200;
        root = insert_node(root, r);
    }
    print(root);
    printf("\n");
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define DECK_MAX 52

typedef enum suit
{
  hearts,
  diamonds,
  spades,
  clubs
} suit;

typedef struct card
{
  short pips;
  suit suit;
} card;

card *shuffles_deck(card *ptr_to_deck, card *ptr_to_shuffled) // shuffles the deck
{
  int element_numbers[52]; // keeps track of selected cards to avoid repetition
  int value = 53;          // use to initalize the above array with number > 52

  for (int m = 0; m < 52; m++)
  {
    element_numbers[m] = value; // filling the array with value not in deck
  }

  for (int i = 0; i < 52; i++)
  {
    int which_element = rand() % DECK_SIZE;
    int original_i = i; // to keep track of i's value so far
    for (int k = 0; k < 52; k++)
    {
      if (element_numbers[k] == which_element) // ie: if card drawn before
      {
        i--;
      }
    }

    if (original_i == i) // if i wsn't decremented = card not drawn before
    {
      element_numbers[i] = which_element;
      *(ptr_to_shuffled + i) = *(ptr_to_deck + which_element);
    }
  }

  return ptr_to_shuffled;
}

int main()
{
}
