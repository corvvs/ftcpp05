#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
    Form("RobotomyRequest", RobotomyRequestForm::kMinGradeToSign, RobotomyRequestForm::kMinGradeToExecute),
    target_(target.length() > 0 ? target : "<unknown>") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &from):
    Form(from), target_(from.target_) {}

RobotomyRequestForm&   RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    this->Form::operator=(rhs);
    const_cast<std::string&>(target_) = rhs.target_;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    assertIsExecutable(executor);
    executeCore();
}

void    RobotomyRequestForm::executeCore(void) const {
    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "** WRYYYYYYYYYYYYYYYYYYYYYYY... **"
        << Constants::kTextReset << std::endl;

    const double dice = ((double)std::rand()) / RAND_MAX;
    const bool succeeded = dice >= 0.5;
    if (succeeded) {
        std::cout
            << Constants::kTextInfo
            << "[" << this << "] "
            << target_
            << " has been neutralized. all-green. over."
            << Constants::kTextReset << std::endl;
    } else {
        std::cout
            << Constants::kTextInfo
            << "[" << this << "] "
            << "oops!!"
            << Constants::kTextReset << std::endl;
    }
}
