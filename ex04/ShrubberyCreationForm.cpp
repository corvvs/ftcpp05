#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
    Form("ShrubberyCreation", ShrubberyCreationForm::kMinGradeToSign, ShrubberyCreationForm::kMinGradeToExecute),
    target_(target.length() > 0 ? target : "") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &from):
    Form(from), target_(from.target_) {}

ShrubberyCreationForm&   ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    this->Form::operator=(rhs);
    const_cast<std::string&>(target_) = rhs.target_;
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    assertIsExecutable(executor);
    executeCore();
}

void    ShrubberyCreationForm::executeCore(void) const {
    std::string filename = target_ + "_shrubbery";
    {
        std::ofstream ofs;
        ofs.exceptions(std::ios::failbit | std::ios::badbit);
        ofs.open(filename);
        ofs
            << "　　　　　　　　　 (;;;;:::::) " << std::endl
            << "　　　　　　　　（;;;;;;;;:::::::::） " << std::endl
            << "　　　　　　　（;;;;;(;;;;;;:::::);;:::） " << std::endl
            << "　　　　　　（;;;（;;;;;(;;;;;:::);;:::）;::） " << std::endl
            << "　　　　　（;;;;;（;;;;;;;;(;;;;;:::);;:::）;;::） " << std::endl
            << "　　　　（;;;;;;;;（;;;;;;(;;;;;:::);;:;;;::）;;:;;:） " << std::endl
            << "　　　　　　　　　|i l i i l | " << std::endl
            << "　　　　　　　　　|i l i i l | " << std::endl
            << "　　　　　　　　　|i l i i l | " << std::endl
            << "　　　　　　　　　|i l i i l | " << std::endl
            << "　　　　　　　　　|i l i i l | " << std::endl
            << "　　　　　　　　　|i l i i l | " << std::endl;
    }
    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "a Shrubbery has been planted at "
        << filename
        << ", accroding to the Form"
        << Constants::kTextReset << std::endl;
}
