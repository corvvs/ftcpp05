#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Constants.hpp"
#include <iostream>
#include <cstdlib>

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

template<class ConcreteForm> void  test(
    ConcreteForm form,
    Bureaucrat& crat
) {
    ConcreteForm copied_form;
    copied_form = form;

    std::cout << crat << std::endl;
    std::cout << form << std::endl;
    std::cout << copied_form << std::endl;

    try {
        crat.executeForm(copied_form);
    } catch (std::exception& e) {
        std::cout << Constants::kTextError << e.what() << Constants::kTextReset << std::endl;
    }
    try {
        crat.signForm(copied_form);
    } catch (std::exception& e) {
        std::cout << Constants::kTextError << e.what() << Constants::kTextReset << std::endl;
    }
    try {
        crat.executeForm(copied_form);
    } catch (std::exception& e) {
        std::cout << Constants::kTextError << e.what() << Constants::kTextReset << std::endl;
    }

    std::cout << form << std::endl;
    std::cout << copied_form << std::endl;
}

int main() {
    say("[ Labors ]");

    Bureaucrat crat1("yo1", 1);
    Bureaucrat crat10("yo10", 10);
    Bureaucrat crat30("yo30", 30);
    Bureaucrat crat50("yo50", 50);
    Bureaucrat crat140("yo140", 140);
    Bureaucrat crat150("yo150", 150);

    say("[ ** Shrubbery, 145 to sign, 137 to exec ** ]");
    ShrubberyCreationForm   fs("42Tokyo");

    say("[ By 150, can nothing ]");
    test(fs, crat150);
    say("[ By 140, can sign but not exec ]");
    test(fs, crat140);
    say("[ By 50, sign and exec ]");
    test(fs, crat50);
    say("[ By 30, sign and exec ]");
    test(fs, crat30);
    say("[ By 10, sign and exec ]");
    test(fs, crat10);
    say("[ By 1, sign and exec ]");
    test(fs, crat1);
    std::cout << fs << std::endl;

    say("[ ** Robotomy, 72 to sign, 45 to exec ** ]");
    std::srand(42);
    RobotomyRequestForm fr("bob");

    say("[ By 150, can nothing ]");
    test(fr, crat150);
    say("[ By 140, can nothing ]");
    test(fr, crat140);
    say("[ By 50, can sign but not exec ]");
    test(fr, crat50);
    say("[ By 30, sign and exec ]");
    test(fr, crat30);
    say("[ By 10, sign and exec ]");
    test(fr, crat10);
    say("[ By 1, sign and exec ]");
    test(fr, crat1);

    say("[ ** Pardon, 25 to sign, 5 to exec ** ]");
    PresidentialPardonForm fp("42SV");
    say("[ By 150, can nothing ]");
    test(fp, crat150);
    say("[ By 140, can nothing ]");
    test(fp, crat140);
    say("[ By 50, can nothing ]");
    test(fp, crat50);
    say("[ By 30, can nothing ]");
    test(fp, crat30);
    say("[ By 10, can sign but not exec ]");
    test(fp, crat10);
    say("[ By 1, sign and exec ]");
    test(fp, crat1);

    say("[ Finish ]");
}
