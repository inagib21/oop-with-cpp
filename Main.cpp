#include <iostream>
#include <string>
#include <vector>
// Base Class Person
class Person {
protected:
    std::string first;
    std::string last;

public:
    // Constructor
    Person(std::string first, std::string last) : first(first), last(last) {}
    Person() = default; // Default constructor
   
    // Setter methods
    void setFirstName(std::string first) { this->first = first; }
    void setLastName(std::string last) { this->last = last; }
    
    // Getter method
    std::string getName() {
        return first + " " + last;
    }
    
    // Method to print full name
    void printFullName() { 
        std::cout << first << " " << last << std::endl; 
    }

    // Virtual method to print info (can be overridden by derived classes)
    virtual void printInfo() {
        std::cout << "First Name: " << first << std::endl;
        std::cout << "Last Name: " << last << std::endl;
    }

    // Static method to print all people in a vector
    static void printPeople(std::vector<Person*> people) {
        for (auto person : people) {
            person->printInfo();
        }
    }
};

// Derived class Employee, inherits from Person
class Employee : public Person {
    std::string department;
public:
    // Constructor
    Employee(std::string firstName, std::string lastName, std::string department)
        : Person(firstName, lastName), department(department) {}
    
    // Getter method for department
    std::string getDepartment() {
        return department;
    }
    
    // Setter method for department
    void setDepartment(std::string department) {
        this->department = department;
    }
    
    // Override the printInfo method from the base class
    void printInfo() override {
        Person::printInfo(); // Call the base class method
        std::cout << "Department: " << department << std::endl;
    }
};

int main() {
    // Create a vector of Person pointers
    std::vector<Person*> people;
    Person p("John", "Doe");
    Employee e("Jane", "Doe", "Sales");

    people.push_back(&p);
    people.push_back(&e);

    // Use the static method to print all people
    Person::printPeople(people);

    // OOP Principles:
    // 1. Encapsulation: Data (first, last, department) is hidden and accessed through methods
    // 2. Inheritance: Employee inherits from Person
    // 3. Polymorphism: printInfo() is overridden in Employee and called through base class pointer
    // 4. Abstraction: Person class provides a general interface for all types of people

    return 0;
}