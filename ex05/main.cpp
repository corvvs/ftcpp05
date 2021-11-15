#include "CentralBureaucracy.hpp"
#include "Constants.hpp"
#include <iostream>
#include <sstream>
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
            &intern,
            &signer,
            &executor
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
    try {
        say("[ Construct CentralBureaucracy ]");
        CentralBureaucracy cb1;
        cb1.doBureaucracy();
        CentralBureaucracy cb2(cb1);
        CentralBureaucracy cb3;

        say("[ Construct Bureaucrat ]");
        const std::size_t N = 20;
        Bureaucrat *crats[N];
        for (std::size_t i = 0; i < N; i += 1) {
            std::stringstream ss;
            ss << "yo" << i + 1;
            crats[i] = new Bureaucrat(ss.str(), i * 7 + 1);
            cb1.feedBureaucrat(*crats[i]);
        }

        say("[ doBureaucracy with blank queue ]");
        cb1.doBureaucracy();

        say("[ push to cb1 ]");
        cb1.queueUp("42Tokyo");
        cb1.queueUp("yokawada");
        cb1.queueUp("mr");
        cb1.queueUp("hige");
        cb1.queueUp("ureshinokun");

        say("[ push to cb3 ]");
        cb3.queueUp("yo");
        cb3.queueUp("ohizumi");

        say("[ cb1 = cb1 ]");
        cb1 = cb1;

        say("[ cb3 = cb1 ]");
        cb3 = cb1;


        say("[ fulfill cb1 ]");
        for (std::size_t i = 0; i < (N + 5); i += 1) {
            cb1.feedBureaucrat(*crats[i % N]);
        }

        say("[ call cb1.doBureaucracy 3 times ]");
        cb1.doBureaucracy();
        cb1.doBureaucracy();
        cb1.doBureaucracy();

        say("[ call cb3.doBureaucracy 3 times ]");
        cb3.doBureaucracy();
        cb3.doBureaucracy();
        cb3.doBureaucracy();

        say("[ Destruct Objects ]");
        for (std::size_t i = 0; i < N; i += 1) {
            delete crats[i];
        }
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextWarning
            << e.what()
            << Constants::kTextReset << std::endl;
    }

    say("[ Finish ]");
}
