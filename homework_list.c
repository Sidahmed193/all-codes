/*
Option 1 (General)
Use the linear linked list code to store a randomly generated set of 100 integers.
Now write a routine that will rearrange the list in sorted order of these values.
Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

How will this work? Compare two adjacent list elements and if they are out of order swap them.
After a first pass the largest element will have bubbled to the end of the list.
Each pass can look at one less element as the end of a list stays sorted.

*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list
{
  int data;
  struct list *next;
};

void fill_random(int array[], int length, int max); // function to randomly generate numbers inside an array
void add_to_front(struct list **h, int data); // function to link between lists
void bubbleSort(struct list *head);                  // function to sort our list
void swap(struct list *a, struct list *b);            // function to that comparts 2 lists and swap when needed
void printList(struct list *head);                   // function to print list

int main()
{
  srand(time(NULL));
  int a[100];
  fill_random(a, 100, 300);
  struct list *head = NULL;
  for (int i = 0; i < 101; i++)
    add_to_front(&head, a[i]);
  printf("\n\n generated list before been sorted :\n");
  printList(head);
  bubbleSort(head);                                      // call this function to sort our list
  printf("\n\n generated list after getting sorted :\n");
  printList(head);
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
void add_to_front(struct list **h, int data)
{
  struct list *ptr1 = (struct list *)malloc(sizeof(struct list));
  ptr1->data = data;
  ptr1->next = *h;
  *h = ptr1;
}

void printList(struct list *head)  // function to print list with 5 numbers in one row at a time
{
  int numbers = 0;
  struct list *temp = head;
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

void bubbleSort(struct list *head)
{
  int swapped, i;
  struct list *ptr1;
  struct list *lptr = NULL;

  if (head == NULL)
    return;
  do
  {
    swapped = 0;
    ptr1 = head;
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
void swap(struct list *a, struct list *b) // function to swap data between 2 lists
{
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}*/
/*

#include<stdio.h>
enum myfoods{butter = 2, milk = 5, cheese = 8, eggs};

int main()
{
   int a = 2, b = 5, c = 8;
   printf("%6lf",eggs);
   printf("  a && b  = %d \n ",  a && b);
   printf(" b %% a   = %d \n ", b % a );
   printf(" a / b    = %d \n " , a/b);
   printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b);
   printf(" b <= c = %d \n "  , b<= c);
   printf(" !!c = %d \n " , !!c);
   printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6);
   printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
   printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
   printf(" c = ++b = %d \n ",c = ++b);
   return 0;
}
*/
/*
#include <stdio.h>

void gdp_growth_calculator(float gdp, float growthrate, int years)
{
  int d=2022;
  for (int i; i <= years; i++)
  {
    float temp = gdp * growthrate;
    gdp = gdp + temp;
    d++;
    printf("year %d the new gdp is %f \n", d, gdp);
  }
  return 0;
}

int main()
{
  float gdp = 1991;
  float growthrate = 0;
  int years = 0;
  printf("current algerian gdp is %f billion \n", gdp);
  printf("enter growth rate and number of years :");
  scanf("%f %d",&growthrate,&years);
  gdp_growth_calculator(gdp,growthrate,years);
  return 0;
}*/
