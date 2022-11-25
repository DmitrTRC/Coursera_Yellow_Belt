//
// Created by Dmitry Morozov on 20/9/22.
//
#include <iostream>
#include <string>
#include <vector>


class Human {
public:
    Human(const std::string &name, const std::string &type) : name_(name), type_(type) {}

    std::string Name() const {

        return name_;
    }

    std::string Type() const {

        return type_;
    }

    virtual void Walk(const std::string &destination) const {

        std::cout << Type() << ": " << Name() << " walks to: " << destination << std::endl;
    }

protected:
    const std::string type_;
    const std::string name_;
};

class Student : public Human {
public:

    Student(const std::string &name, const std::string &favouriteSong) : Human(name, "Student"),
                                                                         FavouriteSong(favouriteSong) {}

    void Learn() const {

        std::cout << "Student: " << Name() << " learns" << std::endl;
    }

    void Walk(const std::string &destination) const override {

        Human::Walk(destination);
        SingSong();
    }

    void SingSong() const {

        std::cout << "Student: " << Name() << " sings a song: " << FavouriteSong << std::endl;
    }

private:
    std::string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const std::string &name, const std::string &subject) : Human(name, "Teacher"), Subject(subject) {}

    void Teach() {

        std::cout << "Teacher: " << Name() << " teaches: " << Subject << std::endl;
    }


public:
    std::string Subject;
};


class Policeman : public Human {
public:
    explicit Policeman(const std::string &name) : Human(name, "Policeman") {}

    void Check(const Human &h) const {

        std::cout << "Policeman: " << Name() << " checks " << h.Type() << ". " << h.Type() << "'s name is: " << h.Name()
                  << std::endl;
    }
};


void VisitPlaces(const Human &h, const std::vector<std::string> &places) {

    for (const auto &p: places) {
        h.Walk(p);
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