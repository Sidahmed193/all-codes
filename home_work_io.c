/*
Open and read a file of integers into an array that is created with the first integer telling you how many to read.

So  4  9  11  12  15  would mean create an int array size 4 and read in the remaining 4 values into data[].

Then compute their average as a double and their max  as an int.
Print all this out neatly to the screen and to an output file named answer-hw3.*/

// Use of file I/O
/*
#include <stdio.h>

#define MAX_HW 20

void read_data(FILE *ptr, int d[], int *size)
{
    int n;
    fscanf(ptr, "%d", &n);          //scans first element of the file and gets the number of elements in the array 
    for (int i = 0; i < n; i++)
    {
        fscanf(ptr,"%d",&d[i]);     // scans the remaining elements and inserts them into the array d[]
    }
    *size=n;                        //the size of the array equals to the first element of the text file 
}

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
double average(int d[], int size)
{
    int i;
    double avg = 0.0;

    for (i = 0; i < size; i++)
        avg += d[i];
    return (avg / size);
}
int MAX(int d[], int size)
{
    int max = d[1];
    for (int i = 1; i < size; i++)
    {
        if (max < d[i])
            max = d[i];
    }
    return (max);
}
void output_data(int d[],int size,double avg,int max, FILE *ofp ){

    fprintf(ofp," %d integer values inside are :",size);         //  prints  the results into the file answer-hw3
    for(int i=0;i<size;i++){
        fprintf(ofp," %d ",d[i]);                                // prints the elements of the array 
    }
    fprintf(ofp,"\n the average is :%f \n",avg);                 // prints the average  
    fprintf(ofp," the MAX is : %d",max);                         // prints the MAX 
}

int main()
{
    int i, sz = MAX_HW;
    FILE *ifp;
    FILE *ofp;
    int data[MAX_HW] = {100, 0};
    ifp = fopen("myhw.txt", "r");
    read_data(ifp, data, &sz);
    printf(" %d integer values inside are :", sz);
    print_data(data, sz);
    printf("\n the average is %10f", average(data, sz));            
    printf("\n\n");
    printf("the MAX is %d", MAX(data, sz));
    ofp = fopen("answer-hw3", "w");                                 //opens the file for writing 
    output_data(data,sz,average(data,sz),MAX(data, sz),ofp);       //inserts all data into the file answers-hw3
    fclose(ifp);
    fclose(ofp);
    return 0;
}
*/

/*
#include <stdio.h>

int main()
{
    FILE *input_file, *output_file;
    int how_many, i, j, sum=0;
    float avg=0.0;

    input_file = fopen("input integer file.txt", "r");
    output_file = fopen("output file.txt", "w+");

    rewind(input_file);
    fscanf(input_file, "%d", &how_many);
    int numberArray[how_many];

    for (i = 0; i < how_many; i++)
    {
        fscanf(input_file, "%d", &numberArray[i]);
    }

    printf("The values of the array are:\n");
    fprintf(output_file, "The values of the array are:\n");
    for (i=0; i<how_many; i++)
    {
        printf("%d\t", numberArray[i]);
        fprintf(output_file, "%d\t", numberArray[i]);
    }

    for (j = 0; j < how_many; j++)
    {
        sum = sum + numberArray[j];
    }
    avg = (float)sum / j;
    printf("\nAverage of array values is %f", avg);
    fprintf(output_file, "\nAverage of array values is %f", avg);

    for (i = 1; i < how_many; ++i)
    {
        if (numberArray[0] < numberArray[i])
        numberArray[0] = numberArray[i];
    }
    printf("\nMaximum value = %d\n\n", numberArray[0]);
    fprintf(output_file, "\nMaximum value = %d\n\n", numberArray[0]);


    fclose(output_file);

return 0;

}
*/


/*This program reads a file of integers into an array and computes their average and max*/

/*NOTE: file integer.txt must be in the same directory for the program to fun successfully*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// Read from a file pointer
void read(FILE *ptr, int d[], int *size)
{
    *size = 0;
    while (fscanf(ptr, "%d", &d[*size]) == 1)
    {
       (*size)++; 
    }
}

// Format array to output screen
void print_data(int d[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", d[i]);
        
    }
}

// Compute the average integer value in an array
double average(int d[], int size)
{
    int i;
    double avg = 0.0;
    for (i = 0; i < size; i++)
    {
        avg += d[i];
    }
    return avg/size;
}

int max(int d[], int size)
{
  int i; 
  int num = 0;
  for (i = 0; i < size; i++)
  {
    if (d[i] > num)
      {
        num = d[i];
      }
  }
  return num;
}

int main()
{
    int i; 
    int size = MAX;
    FILE *input, *output;
    int data[MAX];

    
    input = fopen("integers.txt", "r");
    read(input, data, &size);
    fclose(input);

  // Get the appropriate data
  int new_size = data[0];
  int new_data[new_size];
  for (i = 0; i < new_size; i++)
  {
    new_data[i] = data[i+1];
  }

  // Print the information to screen
  printf("Array: ");
  print_data(new_data, new_size);
  printf("\n\nFrom the data present in the file, the average is %lf and the max is %d", average(new_data, new_size), max(new_data, new_size));

  // Save the information to file
  output = fopen("answer-hw3", "w");
  fprintf(output, "From the data present in the file, the average is %lf and the max is %d", average(new_data, new_size), max(new_data, new_size));
  fclose(output);
  

  return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

struct rational {
    int n;  // numerator
    int d;  // denominator
}data[10];

typedef struct rational RATIONAL;

void generate_pairs(FILE *ifp);
void test_pairs(RATIONAL a, RATIONAL b);

RATIONAL add_rationals(RATIONAL a, RATIONAL b);
RATIONAL subtract_rationals(RATIONAL a, RATIONAL b);
RATIONAL multiply_rationals(RATIONAL a, RATIONAL b);
RATIONAL divide_rationals(RATIONAL a, RATIONAL b);

int main (int argc, char **argv) {
    FILE *ifp;
    char c;

    if(argc != 2){
        printf("Usage: numbers file.txt\n");
        exit(1);
    }
    // File exists?
    ifp = fopen(argv[1], "r");
    if (ifp == NULL) {
        printf("File not found\n");
        exit(1);
    }
    // Generate pairs from input text
    generate_pairs(ifp);
    // Test pair for operations
    test_pairs(data[0], data[1]);
    //
    fclose(ifp);
    return(0);
}
/*
 * According to the value of first element (n) of the file,
 * generate 'n' pairs.
 */
void generate_pairs(FILE *ifp) {
    int a[10], *ptr_a, i=0, j=0;

    ptr_a = &a[0];
    // Read input file
    while(fscanf(ifp, "%d", ptr_a++) == 1) { }

    printf("Number of pairs: %d\n",a[0]);
    // Store pairs in data struct
    while(++i <= a[0]) {
        data[j].n = a[(i*2)-1];
        data[j].d = a[i*2];
        printf("Pair %d: %d/%d\n", j, data[j].n, data[j].d);
        j++;
    }
}

void test_pairs(RATIONAL a, RATIONAL b) {
    RATIONAL res; // result from pair operation
    // '+' operation
    res = add_rationals(a,b);
    printf("Add: %d/%d + %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
    // '-' operation
    res = subtract_rationals(a,b);
    printf("Subtract: %d/%d - %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
    // '*' operation
    res = multiply_rationals(a,b);
    printf("Multiply: %d/%d * %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
    // '/' operation
    res = divide_rationals(a,b);
    printf("Divide: %d/%d / %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
}
/*
 * Add operation for input pair
 */
RATIONAL add_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = a.n*b.d + b.n*a.d;
    return(r);
}
/*
 * Subtract operation for input pair
 */
struct rational subtract_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = a.n*b.d - b.n*a.d;
    return(r);
}
/*
 * Multiplication operation for input pair
 */
RATIONAL multiply_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = a.n*b.n;
    return(r);
}
/*
 * Divide operation for input pair
 */
RATIONAL divide_rationals(RATIONAL a, RATIONAL b) {
    RATIONAL r;

    r.d = a.d*b.n;
    r.n = a.n*b.d;
    return(r);
}





