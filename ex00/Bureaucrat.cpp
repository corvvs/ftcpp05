#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
    name_("<nameless>"),
    grade_(Bureaucrat::kLowestGrade) {}

Bureaucrat::Bureaucrat(std::string name, int grade):
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

void     Bureaucrat::assertGradeIsInRange(int grade) {
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
        << "a Bureaucrat <" << name_ << "> has gotten its grade higher: " << grade_
        << Constants::kTextReset << std::endl;
}

void                Bureaucrat::decrementGrade(void) {
    Bureaucrat::assertGradeIsInRange(grade_ + 1);
    grade_ += 1;
    std::cout
        << Constants::kTextInfo
        << "a Bureaucrat <" << name_ << "> has gotten its grade lower: " << grade_
        << Constants::kTextReset << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& value) {
    return stream
        << Constants::kTextInfo
        << "[" << &value << "] "
        << "a Bureaucrat <" << value.getName()
        << "> has a grade: " << value.getGrade()
        << Constants::kTextReset;
}