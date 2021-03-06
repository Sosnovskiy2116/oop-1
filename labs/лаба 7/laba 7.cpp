#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
	static int count;
	string name; 
	string surname; 
	string midname; 
	int age;
public:
	Human() {
		count++;
		name = "Petr";
		surname = "Petrov";
		midname = "Petrovich";
		age = 21;
	};

	Human(string n, string s, string m, int a) {
		count++;
		name = n;
		surname = s;
		midname = m;
		age = a;
	};

	virtual void print() = 0;

	virtual ~Human() { count--; };
};

class Student : public Human {
private:
	bool on_lesson;
public:
	Student() : Human() {
		on_lesson = true;
	};

	Student(string n, string s, string m, int a, bool on_l) : Human(n, s, m, a) {
		on_lesson = on_l;
	};

	void print() {
		cout << "student" << endl;
		cout << "name: " << name << endl;
		cout << "surname: " << surname << endl;
		cout << "midname: " << midname << endl;
		cout << "age: " << age << endl;
		cout << "on lesson? ";
		cout << ((on_lesson) ? "yes" : "no") << endl;
	};

	~Student() {};
};


class Boss : public Human {
private:
	int kolr;
protected:
	Boss() : Human() {
		kolr = 0;
	}

	Boss(string n, string s, string m, int a, int rab) : Human(n, s, m, a) {
		kolr = rab;
	}

	void print() {
		cout << "boss" << endl;
		cout << "name: " << name << endl;
		cout << "surname: " << surname << endl;
		cout << "midname: " << midname << endl;
		cout << "age: " << age << endl;
		cout << "number of workers: " << kolr << endl;
	};

	~Boss() { };
};