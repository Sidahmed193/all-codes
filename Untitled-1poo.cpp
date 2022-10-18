#include <iostream>
using std::string;
class Employee {
    public:
    string Name;
    string Company;
    int Age;

    void Introduceyourself(){
    std::cout<<"Name :"<<Name<<std::endl;
    std::cout<<"Company :"<<Company<<std::endl;
    std::cout<<"Age :"<<Age<<std::endl;
    }
};
int main()
{

  Employee Employee1;
    Employee1.Name="saldina";
    Employee1.Company="elsaroukh co";
    Employee1.Age=25;
    Employee1.Introduceyourself();

}
