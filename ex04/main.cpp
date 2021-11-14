#include "OfficeBlock.hpp"
#include "Constants.hpp"
#include <iostream>
#include <cstdlib>

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

void  test(
    Intern& intern,
    Bureaucrat& signer,
    Bureaucrat& executor
) {

    try {
        std::cout
            << std::endl
            << "[ <TestCase> Signer: " << signer.getName() << "(" << signer.getGrade() << ")"
            << " Executor: " << executor.getName() << "(" << executor.getGrade() << ")"
            << " ]"
            << std::endl
            << std::endl;
        OfficeBlock ob(
            new Intern(intern),
            new Bureaucrat(signer),
            new Bureaucrat(executor)
        );
        ob.doBureaucracy("FlameThrowingForm", "42Tokyo");
        say("[ ** Shrubbery, 145 to sign, 137 to exec ** ]");
        ob.doBureaucracy("ShrubberyCreationForm", "42Tokyo");
        say("[ ** Robotomy, 72 to sign, 45 to exec ** ]");
        ob.doBureaucracy("RobotomyRequestForm", "42Tokyo");
        say("[ ** Pardon, 25 to sign, 5 to exec ** ]");
        ob.doBureaucracy("PresidentialPardonForm", "42Tokyo");
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextWarning
            << e.what()
            << Constants::kTextReset << std::endl;
    }
}

int main() {

    say("[ Intern ]");
    Intern  it;
    Intern  it2(it);
    Intern  it3;
    it3 = it2;

    say("[ Labors ]");

    Bureaucrat crat1("yo1", 1);
    Bureaucrat crat10("yo10", 10);
    Bureaucrat crat30("yo30", 30);
    Bureaucrat crat50("yo50", 50);
    Bureaucrat crat140("yo140", 140);
    Bureaucrat crat150("yo150", 150);

    test(it3, crat1, crat150);
    test(it3, crat150, crat1);
    test(it3, crat50, crat50);
    test(it3, crat1, crat50);
    test(it3, crat50, crat1);


    say("[ Blank Test ]");
    try {
        OfficeBlock ob;
        // OfficeBlock ob2(ob); // error: calling a private constructor of class 'OfficeBlock'
        OfficeBlock ob3;
        // ob3 = ob; // error: 'operator=' is a private member of 'OfficeBlock'

        ob.doBureaucracy("FlameThrowingForm", "42Tokyo");
        say("[ ** Shrubbery, 145 to sign, 137 to exec ** ]");
        ob.doBureaucracy("ShrubberyCreationForm", "42Tokyo");
        say("[ ** Robotomy, 72 to sign, 45 to exec ** ]");
        ob.doBureaucracy("RobotomyRequestForm", "42Tokyo");
        say("[ ** Pardon, 25 to sign, 5 to exec ** ]");
        ob.doBureaucracy("PresidentialPardonForm", "42Tokyo");
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextWarning
            << e.what()
            << Constants::kTextReset << std::endl;
    }

    say("[ Finish ]");
}