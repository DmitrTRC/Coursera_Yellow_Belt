//
// Created by Dmitry Morozov on 20/9/22.
//
#include <iostream>
#include <utility>
#include <vector>

class Human {
public:

    Human(std::string name, std::string type) : name_(std::move(name)), type_(std::move(type)) {}

    [[nodiscard]] std::string Name() const {

        return name_;
    }

    [[nodiscard]] std::string Type() const {

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

    Student(const std::string &name, std::string favouriteSong) : Human(name, "Student"),
                                                                  FavouriteSong(std::move(favouriteSong)) {}

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

    Teacher(const std::string &name, std::string subject) : Human(name, "Teacher"), Subject(std::move(subject)) {}

    [[maybe_unused]] void Teach() {

        std::cout << "Teacher: " << Name() << " teaches: " << Subject << std::endl;
    }


private:
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
