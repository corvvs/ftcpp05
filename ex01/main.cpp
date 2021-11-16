#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Constants.hpp"
#include <iostream>

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

void    test(
    Bureaucrat& signer,
    Form& form
) {
    try {
        signer.signForm(form);
    } catch (std::exception& e) {
    std::cout
        << Constants::kTextError
        << e.what()
        << Constants::kTextReset << std::endl;
    }
}

int main() {
    try {
        say("[ Fail by Too High To Sign]");
        Form tooHigh("yo", 0, 150);
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
    }
    try {
        say("[ Fail by Too High To Execute]");
        Form tooHigh("yo", 150, 0);
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
    }
    try {
        say("[ Fail by Too Low To Sign]");
        Form tooLow("yo", 151, 1);
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
            
    }
    try {
        say("[ Fail by Too Low To Execute]");
        Form tooLow("yo", 1, 151);
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
            
    }
    try {
        say("[ Hire Signers ]");
        Bureaucrat signer150("yo150", 150);
        Bureaucrat signer101("yo101", 101);
        Bureaucrat signer100("yo100", 100);
        Bureaucrat signer99("yo99", 99);
        Bureaucrat signer2("yo2", 2);
        Bureaucrat signer1("yo1", 1);

        say("[ Print Forms ]");
        Form forms[3];
        forms[0] = Form("form150", 150, 150);
        forms[1] = Form("form100", 100, 150);
        forms[2] = Form("form1", 1, 150);
        for (int j = 0; j < 3; j += 1) {
            std::cout << forms[j] << std::endl;
        }

        say("[ Sign. ]");
        say("[ yo150: success, fail, fail ]");
        for (int j = 0; j < 3; j += 1) {
            test(signer150, forms[j]);
        }
        say("[ yo101: success, fail, fail ]");
        for (int j = 0; j < 3; j += 1) {
            test(signer101, forms[j]);
        }
        say("[ yo100: success, success, fail ]");
        for (int j = 0; j < 3; j += 1) {
            test(signer100, forms[j]);
        }
        say("[ yo99: success, success, fail ]");
        for (int j = 0; j < 3; j += 1) {
            test(signer99, forms[j]);
        }
        say("[ yo2: success, success, fail ]");
        for (int j = 0; j < 3; j += 1) {
            test(signer2, forms[j]);
        }
        say("[ yo1: success, success, success ]");
        for (int j = 0; j < 3; j += 1) {
            test(signer1, forms[j]);
        }
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextError
            << e.what()
            << Constants::kTextReset << std::endl;
            
    }

    say("[ Finish ]");
}
