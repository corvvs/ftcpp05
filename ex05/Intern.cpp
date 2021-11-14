#include "Intern.hpp"

const std::string Intern::kConcreteFormNames[] = {
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
};

Intern::Intern() {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "another pathetic Intern was brought in"
        << Constants::kTextReset << std::endl;
}

Intern::~Intern() {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "the Intern has been kicked out"
        << Constants::kTextReset << std::endl;
}

Intern::Intern(const Intern &from) {
    (void)from;
}

Intern& Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return *this;
}


std::size_t  Intern::IndexForForName(std::string form_name) {
    std::size_t i = 0;
    while (i < Intern::kConcreteFormNum && form_name != Intern::kConcreteFormNames[i]) {
        i += 1;
    }
    return i;
}


Form*   Intern::makeForm(
    std::string form_name,
    std::string target_name
) const {
    Form *concrete = NULL;
    switch (Intern::IndexForForName(form_name)) {
        case 0:
            concrete = new ShrubberyCreationForm(target_name);
            break;
        case 1:
            concrete = new RobotomyRequestForm(target_name);
            break;
        case 2:
            concrete = new PresidentialPardonForm(target_name);
            break;
        default:
            std::cout
                << Constants::kTextWarning
                << "[" << this << "] "
                << "A blank-eyed intern said: <" << form_name << ">? That's good idea..."
                << Constants::kTextReset << std::endl;
            return NULL;
    }
    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "A sleepy intern created <" << form_name << ">"
        << ", for <" << target_name << "> as a target"
        << Constants::kTextReset << std::endl;
    return concrete;
}
