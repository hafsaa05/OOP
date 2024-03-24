/*
A software house has employees who are passionate about the role they have been given. 
Some are developers and some are debuggers. All the affiliated employees are collectively known as employees. 
A team lead is both a developer and a debugger. All the employees have a name, age and joining date. 
Moreover, A developer has attribute; role (frontend developer or backend developer), A debugger has attribute; 
role (Manual debugger or auto debugger). A team lead can display all the data with respect to roles. 
Identify the type of inheritance that is present in the above scenario. Also, implement the scenario and 
create object of team head (only) in main by adding appropriate constructors, accessor functions.
*/
#include<iostream>
using namespace std;
class Employees{
    public:
    string name;
    int age; string date;
    Employees(string name, int age, string date): name(name), age(age), date(date) {}

    string getName() { return name;}
    void setName(int name) {
        this->name=name;
    }

    int getAge(){ return age; }
    void setAge(int age){
        this->age=age;
    }

    string getDate(){ return date; }
    void setDate(string date){
      this->date=date;
    }

};

class Developer: public Employees{
protected:
string role;
public:
Developer(string name, int age, string date, string developer): Employees(name, age, date), role(developer) {}
};

class Debugger: public Employees{
protected:
string role;
public:
Debugger(string name, int age, string date, string debugger): Employees(name, age, date), role(debugger) {}
};

class Lead: public Developer, public Debugger{
public: 
Lead(string name, int age, string date, string developer, string debugger): Developer(name, age, date, developer),Debugger(name, age, date, debugger) {}

void displayDeveloper(){
    cout<<"Name: "<<Developer::name<<endl;
    cout<<"Age: "<<Developer::age<<endl;
    cout<<"Date of joining: "<<Developer::date<<endl;
    cout<<"Role: "<<Developer::role<<endl;
}
void displayDebugger(){
    cout<<"Name: "<<Debugger::name<<endl;
    cout<<"Age: "<<Debugger::age<<endl;
    cout<<"Date of joining: "<<Debugger::date<<endl;
    cout<<"Role: "<<Debugger::role<<endl;
}

};
int main(){

    Lead e1("Hafsa", 18, "22nd August 2023", "Frontend Developer", "Front-end Developer");
    e1.displayDeveloper();
    cout<<endl;
    e1.displayDebugger();


    return 0;
}
