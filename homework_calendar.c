
/* homework assginement using struct Write enumerated types that supports dates—such as december 12.
Then add a function that produces a next day.  So nextday(date) of december 12 is december 13.
Also write a function printdate(date) that prints a date legibly.
The function can assume that February has 28 days and it most know how many days are in each month.
Use a struct with two members; one is the month and the second  is the day of the month—an int (or short).

Then print out  the date January 1  and print  the next day Jan 2.
Do this for the following dates:  February 28, March 14, October 31, and  December 31.
*/
/*
#include <stdio.h>

int DaysinMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef enum month
{
  jan = 1,
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

void print_month(month m)
{

  switch (m)
  {
  case 1:
    printf("January");
    break;
  case 2:
    printf("February");
    break;
  case 3:
    printf("March");
    break;
  case 4:
    printf("April");
    break;
  case 5:
    printf("May");
    break;
  case 6:
    printf("June");
    break;
  case 7:
    printf("July");
    break;
  case 8:
    printf("August");
    break;
  case 9:
    printf("September");
    break;
  case 10:
    printf("October");
    break;
  case 11:
    printf("November");
    break;
  case 12:
    printf("December");
    break;
  default:
    printf("%d is an error", m);
    break;
  }
}

date nextday(date a)
{

  if (a.d < DaysinMonths[a.m - 1])
  {
    a.d++;
  }
  else if (a.d = DaysinMonths[a.m - 1])
  {
    a.d = 1;
    a.m++;
    if (a.m >= 12)
    {
      a.m = 1;
    }
  }
  return a;
}

void printdate(date a)
{
  print_month(a.m);
  printf("  %d", a.d);
}

int main()
{
  date a;
  printf("please enter a date MM//DD with a space in between:");
  scanf("%d %d", &a.m, &a.d);
  printdate(a);
  printf("\n the next day will be :\n");
  a = nextday(a);
  printdate(a);

  return 0;
}

*/
/*
#include <stdio.h>

typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date{ month m; int d;} date;
int max_days, i;

void printday(date* dt)
{

    switch(dt-> m)
    {
        case jan:
            printf("January %d", dt->d);
            max_days = 31;
            break;
        case feb:
            printf("February %d", dt->d);
            max_days = 28;
            break;
        case mar:
            printf("March %d", dt->d);
            max_days = 31;
            break;
        case apr:
            printf("April %d", dt->d);
            max_days = 30;
            break;
        case may:
            printf("May %d", dt->d);
            max_days = 31;
            break;
        case jun:
            printf("June %d", dt->d);
            max_days = 30;
            break;
        case jul:
            printf("July %d", dt->d);
            max_days = 31;
            break;
        case aug:
            printf("August %d", dt->d);
            max_days = 31;
            break;
        case sep:
            printf("September %d", dt->d);
            max_days = 30;
            break;
        case oct:
            printf("October %d", dt->d);
            max_days = 31;
            break;
        case nov:
            printf("November %d", dt->d);
            max_days = 30;
            break;
        case dec:
            printf("December %d", dt->d);
            max_days = 31;
            break;
    }
}
date* nextday(date* dt)
{
    if (dt->d==max_days) //For the case that we're in the last day of the month
    {
        dt->d = (dt->d + 1)%max_days;
        dt->m = (dt->m + 1)%12; //%12 for the case that we're in the last day of the year
    }
    else //If we're not in the end of the month, just increment the day
        dt->d = dt->d + 1;
    return dt;
}

int main()
{
    date date1 = {jan, 1};
    date date2 = {feb, 28};
    date date3 = {mar, 14};
    date date4 = {oct, 31};
    date date5 = {dec, 31};
    date dates[] = {date1, date2, date3, date4, date5};

    for (i=0; i<5; i++)
    {
        printf("Date is ");
        printday(&dates[i]);
        printf("\nNext day is ");
        nextday(&dates[i]);
        printday(&dates[i]);
        printf("\n\n");
    }

    return 0;
}

*/
/*
#include <stdio.h>

typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date{ month m; int d;} date;
int max_days, i;

void printday(date* dt)
{

    switch(dt-> m)
    {
        case jan:
            printf("January %d", dt->d);
            max_days = 31;
            break;
        case feb:
            printf("February %d", dt->d);
            max_days = 28;
            break;
        case mar:
            printf("March %d", dt->d);
            max_days = 31;
            break;
        case apr:
            printf("April %d", dt->d);
            max_days = 30;
            break;
        case may:
            printf("May %d", dt->d);
            max_days = 31;
            break;
        case jun:
            printf("June %d", dt->d);
            max_days = 30;
            break;
        case jul:
            printf("July %d", dt->d);
            max_days = 31;
            break;
        case aug:
            printf("August %d", dt->d);
            max_days = 31;
            break;
        case sep:
            printf("September %d", dt->d);
            max_days = 30;
            break;
        case oct:
            printf("October %d", dt->d);
            max_days = 31;
            break;
        case nov:
            printf("November %d", dt->d);
            max_days = 30;
            break;
        case dec:
            printf("December %d", dt->d);
            max_days = 31;
            break;
    }
}
date* nextday(date* dt)
{
    if (dt->d==max_days) //For the case that we're in the last day of the month
    {
        dt->d = (dt->d + 1)%max_days;
        dt->m = (dt->m + 1)%12; //%12 for the case that we're in the last day of the year
    }
    else //If we're not in the end of the month, just increment the day
        dt->d = dt->d + 1;
    return dt;
}

int main()
{
    date date1 = {jan, 1};
    date date2 = {feb, 28};
    date date3 = {mar, 14};
    date date4 = {oct, 31};
    date date5 = {dec, 31};
    date dates[] = {date1, date2, date3, date4, date5};

    for (i=0; i<5; i++)
    {
        printf("Date is ");
        printday(&dates[i]);
        printf("\nNext day is ");
        nextday(&dates[i]);
        printday(&dates[i]);
        printf("\n\n");
    }

    return 0;
}
*/

// #include <stdio.h>

// typedef enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
// typedef struct date{month m; int d;} date;

// int daysinmonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

// void printdate(date d)
// {
//     switch (d.m)
//     {
//         case jan: printf("January %d", d.d); break;
//         case feb: printf("Feburay %d", d.d); break;
//         case mar: printf("March %d", d.d); break;
//         case apr: printf("April %d", d.d); break;
//         case may: printf("May %d", d.d); break;
//         case jun: printf("June %d", d.d); break;
//         case jul: printf("July %d", d.d); break;
//         case aug: printf("August %d", d.d); break;
//         case sep: printf("September %d", d.d); break;
//         case oct: printf("October %d", d.d); break;
//         case nov: printf("November %d", d.d); break;
//         case dec: printf("December %d", d.d); break;
//         default: printf("month input incorrect");
//     }
// }

// date nextday(date d)
// {
//     int days_in_month = daysinmonths[d.m];
//     int current_date = d.d;
//     int current_month = d.m;
//     int new_month, new_date;

//     /* test if given date is the last day of the month
//     if yes, month needs to be updated as well */
//     if (current_date == days_in_month)
//     {
//         new_date = (current_date + 1) % days_in_month;
//         new_month = (current_month + 1) % 12;
//     }
//     else
//     {
//         new_date = (current_date + 1) % days_in_month;
//         new_month = current_month;
//     }

//     /* here directly return a struct but need to define a struct variable first
//     also use the index feature for enum, where new_month is a number */
//     date nextday = {new_month, new_date};
//     return nextday;
// }

// int main(void)
// {
//     month m = may;
//     date today = {feb, 28};

//     printf("today is: ");
//     printdate(today);
//     printf("\nnext day is: ");;
//     printdate(nextday(today));

// }
//
/*
#include <stdio.h>
#include <stdlib.h>

int da=0;
int mo=0;

typedef enum month{January, February, March, April, May, June, July, August,
September, October, November, December} month;

typedef struct date{
month m;
int d;
} date;

void printdate()
{
if(mo == 0)
printf("January %d\n",da);

else if(mo == 1)
printf("February %d\n",da);

else if(mo == 2)
printf("March %d\n",da);

else if(mo == 10)
printf("November %d\n",da);

}

void nextday(date dat)
{

if(dat.m==0 && dat.d==1)
{
da = 2;
mo = dat.m;
}
else if(dat.m==1 && dat.d==28)
{
da = 1;
mo = (dat.m + 1);
}
else if(dat.m==2 && dat.d==14)
{
    da = 15;
    mo = dat.m;
}
else if(dat.m==9 && dat.d==31)
{
    da = 1;
    mo = (dat.m + 1);
}
else if(dat.m==11 && dat.d==31)
{
    da = 1;
    mo = 0;
}

}

int main(){

date dates;

dates.m=January;
dates.d=1;
printf("January %d\t", dates.d);
nextday(dates);
printdate();

dates.m=February;
dates.d=28;
printf("February %d\t", dates.d);
nextday(dates);
printdate();

dates.m=March;
dates.d=14;
printf("March %d\t", dates.d);
nextday(dates);
printdate();

dates.m=October;
dates.d=31;
printf("October %d\t", dates.d);
nextday(dates);
printdate();

dates.m=December;
dates.d=31;
printf("December %d\t", dates.d);
nextday(dates);
printdate();

}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct list
{
  int data;
  struct list *next;
} list;

// void fill_random(int array[],int length,int max);

void fill_random(int array[], int length, int max)
{
  for (int i = 0; i < length; i++)
  {
    array[i] = (rand() % max) + 1; // fills array from 1 to max
  }
}
// int is_empty(const list *l) { return (l == NULL); };
list *create_list(int d)
{
  list *head = malloc(sizeof(list));
  head->data = d;
  head->next = NULL;
  return head;
}

list *add_to_front(int d, list *h)
{
  list *head = create_list(d);
  head->next = h;
  return head;
}
list *array_to_list(int a[], int length)
{
  list *head = create_list(a[0]);
  int i;
  for (i = 1; i < length; i++)
  {
    head = add_to_front(a[i], head);
  }
  return head;
}
void print_list(list *h)
{
  printf("%d\t");
  while (h != NULL)
  {
    printf("%d :", h->data);
    h = h->next;
  }
}
/* Function to print nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp = start;
  printf("");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
/* function to swap data of two nodes a and b*/
void swap(struct list *a, struct list *b)
{
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}
/* Bubble sort the given linked list */
void bubbleSort(struct list *start)
{
  int swapped, i;
  struct Node *ptr1;
  struct Node *lptr = NULL;

  /* Checking for empty list */
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

/* function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b)
{
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}
int main()
{
  srand(time(NULL));
  list *head = NULL;
  int a[100];
  fill_random(a, 100, 300);
  head = array_to_list(a,100);
  head = (struct list *)malloc(sizeof(list));
  printf("sizeof(list) =%lu\n", sizeof(list)); // unsigned long
  print_list(head);
  printf("\n\n");
  return 0;
}