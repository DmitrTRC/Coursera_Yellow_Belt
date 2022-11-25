//
// Created by Dmitry Morozov on 20/9/22.
//
#include <iostream>
#include <string>
#include <vector>


class Human {
public:
    Human(const std::string &name, const std::string &type) : Name(name), Type(type) {}

    virtual void Walk(const std::string &destination) const {

        std::cout << Type << ": " << Name << " walks to: " << destination << std::endl;
    }

    const std::string Name;
    const std::string Type;
};

class Student : public Human {
public:

    Student(const std::string &name, const std::string &favouriteSong) : Human(name, "Student"),
                                                                         FavouriteSong(favouriteSong) {}

    void Learn() const {

        std::cout << "Student: " << Name << " learns" << std::endl;
    }

    void Walk(const std::string &destination) const override {

        Human::Walk(destination);
        SingSong();
    }

    void SingSong() const {

        std::cout << "Student: " << Name << " sings a song: " << FavouriteSong << std::endl;
    }

public:
    std::string Name;
    std::string FavouriteSong;
};


class Teacher {
public:
    Teacher(std::string name, std::string subject) : Name(std::move(name)), Subject(std::move(subject)) {}

    void Teach() {

        std::cout << "Teacher: " << Name << " teaches: " << Subject << std::endl;
    }


public:
    std::string Name;
    std::string Subject;
};


class Policeman {
public:
    Policeman(std::string name) : Name(std::move(name)) {}

    void Check(Teacher t) {

        std::cout << "Policeman: " << Name << " checks Teacher. Teacher's name is: " << t.Name << std::endl;
    }

    void Check(Student s) {

        std::cout << "Policeman: " << Name << " checks Student. Student's name is: " << s.Name << std::endl;
    }

    void Check(Policeman p) {

        std::cout << "Policeman: " << Name << " checks Policeman. Policeman's name is: " << p.Name << std::endl;
    }

    void Walk(std::string destination) {

        std::cout << "Policeman: " << Name << " walks to: " << destination << std::endl;
    }

public:
    std::string Name;
};


void VisitPlaces(Teacher t, std::vector<std::string> places) {

    for (auto p: places) {
        t.Walk(p);
    }
}

void VisitPlaces(Student s, std::vector<std::string> places) {

    for (auto p: places) {
        s.Walk(p);
    }
}

void VisitPlaces(Policeman pol, std::vector<std::string> places) {

    for (auto p: places) {
        pol.Walk(p);
    }
}


int main() {

    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

/* Output:
Teacher: Jim walks to: Moscow
Teacher: Jim walks to: London
Policeman: Bob checks Student. Student's name is: Ann
Student: Ann walks to: Moscow
Student: Ann sings a song: We will rock you
Student: Ann walks to: London
Student: Ann sings a song: We will rock you

Process finished with exit code 0
*/