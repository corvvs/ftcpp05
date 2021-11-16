#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
    Form("PresidentialPardon", PresidentialPardonForm::kMinGradeToSign, PresidentialPardonForm::kMinGradeToExecute),
    target_(target.length() > 0 ? target : "<unknown>") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &from):
    Form(from), target_(from.target_) {}

PresidentialPardonForm&   PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    this->Form::operator=(rhs);
    const_cast<std::string&>(target_) = rhs.target_;
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    assertIsExecutable(executor);
    executeCore();
}

void    PresidentialPardonForm::executeCore(void) const {
    std::cout
        << Constants::kTextInfo
        << "[" << this <<"] "
        << target_ << " has been pardoned by Zafod Beeblebrox"
        << Constants::kTextReset << std::endl;
}
