/*
// outputting text
#include <iostream>

using namespace std;

int main()
{
    cout << "this is some text ." << endl;
    cout << "hello world " << endl;

    return 0;
}
*/
/*
// variables

#include <iostream>

using namespace std;

int main()
{
    int numberCars = 17;
    int numberBikes = 11;
    int numbertoys = numberBikes + numberCars;
    cout << "The Number of Cars is: " << numberCars << endl;
    cout << "The Number of Bikes is: " << numberBikes << endl;
    cout << "The total Number of Cars + Bikes is: " << numbertoys << endl;
    cout << "New car aquired !" << endl;

      numberCars = numberCars + 1;

    cout << "The New Number of Cars is: " << numberCars << endl;
    cout << "The New total number of cars + bikes is: " << numbertoys << endl;
    cout << "The New total number of cars + bikes is: " << numberBikes + numberCars << endl;

    return 0;
}
*/
/*
// strings
#include <iostream>

using namespace std;

int main()
{
    string text1 = "tarek ";
    string text2 = "el saroukh";
    string text3 = text1 + text2;
    cout << text1 << text2 << endl;
    cout << text1 + text2 << endl;
    cout << text3 << endl;

    return 0;
}
*/
/*
// user input
#include <iostream>
using namespace std;

int main()
{

    cout << "please enter your name : " << flush;
    string name;
    cin >> name;
    cout << "your name is : " << name; //<< " please enter your age :"<<flush;

    cout << "please enter your age :" << flush;
    int age;
    cin >> age;

    cout << "your name is : " << name << " and your age is "<< age<< endl;
    //cout << "and your age is:" << age << endl;

    return 0;
}
*/
/*
#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    const string password = "hello";
    string input;
    do
    {
        cout << "please enter password : " << flush;
        string input;
        cin >> input;
        if (input != password)
        {
            cout << "access denied" << endl;
        }

    } while (input != password);

    cout << "password accepted " << endl;

    return 0;
}
*/
