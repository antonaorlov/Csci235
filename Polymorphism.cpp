#include <iostream>
#include <stack>
#include <queue>
using namespace std;

 // In comparison to basic inheritance, polymorphism incurs both runtime and memory overhead. 
 // A pure Virual Function is always ovverriden by a subclass method, found in an abstract class, has no implementation
 // An abstract class is a class that has at least 1 pure virtual function
 // A virtual function table stores pointers to all virtual functions in a class
 // To implement Plymorphism store superclass pointers to access subclass objects
 // Final keywoard to method prevents subclasses from ovverriding
 // A protected method is one that is accessible within class and by its subclasses, but not by its clients
 // Final keyword to class prevents further inheritance
 // The base class must be virtual and the derived class method of the same name overrides

//function overloading

int sum(int num1, int num2){
    return num1+num2;
}
double sum(double num1, double num2){
    return num1+num2;
}
int sum(int num1, int num2, int num3){
    return num1+num2+num3;
}

//function overriding

class Base{
public:
virtual void print(){
    cout<<"Base Function"<<endl;
}
};

class Derived:public Base{
    public:
    void print(){
        cout<<"Derived Function"<<endl;
    }
};

//Pure Virtual Functions

class Shape{ //Abstract class has 0
    public:
    virtual void calculateArea()=0;
};

int main(){
 // Call function with 2 int parameters
    cout << "Sum 1 = " << sum(5, 6) << endl;

    // Call function with 2 double parameters
    cout << "Sum 2 = " << sum(5.5, 6.6) << endl;

    // Call function with 3 int parameters
    cout << "Sum 3 = " << sum(5, 6, 7) << endl;

    Derived derived1;
    derived1.print(); //pritns Derived function ovverrides base function of print
    derived1.Base::print(); //Base Function, dirrectly access base class

}