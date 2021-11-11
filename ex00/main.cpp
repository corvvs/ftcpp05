#include "Bureaucrat.hpp"
#include "Constants.hpp"
#include <iostream>

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

int main() {
    try {
        say("[ Fail by Too High ]");
        Bureaucrat tooHigh("yo", 0);
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
    }
    try {
        say("[ Fail by Too Low ]");
        Bureaucrat tooLow("yo", 151);
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
            
    }
    Bureaucrat ausie("temp", 57);
    Bureaucrat monge(ausie);
    std::cout << ausie << std::endl;
    std::cout << monge << std::endl;
    try {
        say("[ Increment, Decrement and Fired ]");
        Bureaucrat boobie("yo", 150);
        std::cout << boobie << std::endl;
        for (int i = 1; i < 150; i += 1) {
            boobie.incrementGrade();
        }
        std::cout << ausie << std::endl;
        std::cout << boobie << std::endl;
        ausie = boobie;
        std::cout << ausie << std::endl;
        std::cout << monge << std::endl;
        for (int i = 1; i <= 150; i += 1) {
            boobie.decrementGrade();
        }
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
    }
    try {
        say("[ Over the Sky ]");
        std::cout << ausie << std::endl;
        std::cout << monge << std::endl;
        ausie.incrementGrade();
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
    }
}
