#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
    name_("<nameless>"), grade_(Bureaucrat::kLowestGrade)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a nameless Bureaucrat has arrived in lowest grade"
        << Constants::kTextReset << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):
    name_(name)
{
    Bureaucrat::assertGradeIsInRange(grade);
    grade_ = grade;
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Bureaucrat <" << name_ <<"> has arrived in grade " << grade_
        << Constants::kTextReset << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Bureaucrat <" << name_ <<"> on grade " << grade_ << " has been fired..."
        << Constants::kTextReset << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &from):
    name_(from.name_), grade_(from.grade_)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Bureaucrat <" << name_ <<"> has been copied with grade " << grade_
        << Constants::kTextReset << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
    const_cast<std::string&>(name_) = rhs.name_;
    grade_ = rhs.grade_;
    return *this;
}

void    Bureaucrat::assertGradeIsInRange(int grade) {
    if (grade < Bureaucrat::kHighestGrade) {
        throw Bureaucrat::GradeTooHighException("high");
    }
    if (grade > Bureaucrat::kLowestGrade) {
        throw Bureaucrat::GradeTooLowException("low");
    }
}

const std::string&  Bureaucrat::getName(void) const {
    return name_;
}

int                 Bureaucrat::getGrade(void) const {
    return grade_;
}

void                Bureaucrat::incrementGrade(void) {
    Bureaucrat::assertGradeIsInRange(grade_ - 1);
    grade_ -= 1;
    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "a Bureaucrat <" << name_ << "> has gotten its grade higher: " << grade_
        << Constants::kTextReset << std::endl;
}

void                Bureaucrat::decrementGrade(void) {
    Bureaucrat::assertGradeIsInRange(grade_ + 1);
    grade_ += 1;
    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "a Bureaucrat <" << name_ << "> has gotten its grade lower: " << grade_
        << Constants::kTextReset << std::endl;
}

void                Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
        std::cout
            << Constants::kTextInfo
            << "[" << this << "] "
            << "a Bureaucrat <" << name_ << "> has successfully signed the form "
            << form.getName() << "[" << &form << "]"
            << Constants::kTextReset << std::endl;
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextWarning
            << "[" << this << "] "
            << "a Bureaucrat <" << name_ << "> has failed to sign the form "
            << form.getName() << "[" << &form << "]"
            << ", with reason: <" << e.what() << ">"
            << Constants::kTextReset << std::endl;
        throw Bureaucrat::FailedToSignException("fail");
    } 
}

void                Bureaucrat::executeForm(Form const & form) {
    try {
        form.execute(*this);
        std::cout
            << Constants::kTextInfo
            << "[" << this << "] "
            << "a Bureaucrat <" << name_ << "> has successfully executed the form "
            << form.getName() << "[" << &form << "]"
            << Constants::kTextReset << std::endl;
    } catch (std::exception& e) {
        std::cout
            << Constants::kTextWarning
            << "[" << this << "] "
            << "a Bureaucrat <" << name_ << "> has failed to executed the form "
            << form.getName() << "[" << &form << "]"
            << ", with reason: <" << e.what() << ">"
            << Constants::kTextReset << std::endl;
        throw Bureaucrat::FailedToExecuteException("fail");
    } 
}
std::ostream&   operator<<(std::ostream& stream, const Bureaucrat& value) {
    return stream
        << Constants::kTextInfo
        << "[" << &value << "] "
        << "a Bureaucrat <" << value.getName()
        << "> has a grade: " << value.getGrade()
        << Constants::kTextReset;
}
