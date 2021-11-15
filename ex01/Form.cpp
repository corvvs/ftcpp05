#include "Form.hpp"

Form::Form():
    name_("<nameless>"),
    is_signed_(false),
    min_grade_to_sign_(Form::kLowestGrade),
    min_grade_to_execute_(Form::kLowestGrade) {}

Form::Form(
    std::string name,
    int min_grade_to_sign,
    int min_grade_to_execute
):
    name_(name),
    is_signed_(false),
    min_grade_to_sign_(Form::kLowestGrade),
    min_grade_to_execute_(Form::kLowestGrade)
{
    Form::assertGradeIsInRange(min_grade_to_sign);
    const_cast<int &>(min_grade_to_sign_) = min_grade_to_sign;
    Form::assertGradeIsInRange(min_grade_to_execute);
    const_cast<int &>(min_grade_to_execute_) = min_grade_to_execute;
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Form <" << name_ <<
        "> requires "<< min_grade_to_sign_ << " to sign, " <<
        "and also requires " << min_grade_to_execute_ << " to execute"
        << Constants::kTextReset << std::endl;
}

Form::~Form() {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Form <" << name_ <<"> has been burnt (^o^)"
        << Constants::kTextReset << std::endl;
}

Form::Form(const Form &from):
    name_(from.name_),
    is_signed_(from.is_signed_),
    min_grade_to_sign_(from.min_grade_to_sign_),
    min_grade_to_execute_(from.min_grade_to_execute_)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Form <" << name_ <<"> has been xeroxed"
        << Constants::kTextReset << std::endl;
}

Form& Form::operator=(const Form &rhs) {
    const_cast<std::string&>(name_) = rhs.name_;
    is_signed_ = rhs.is_signed_;
    const_cast<int&>(min_grade_to_sign_) = rhs.min_grade_to_sign_;
    const_cast<int&>(min_grade_to_execute_) = rhs.min_grade_to_execute_;
    return *this;
}

void     Form::assertGradeIsInRange(int grade) {
    if (grade < Form::kHighestGrade) {
        throw Form::GradeTooHighException("high");
    }
    if (grade > Form::kLowestGrade) {
        throw Form::GradeTooLowException("low");
    }
}

const std::string&  Form::getName(void) const {
    return name_;
}

bool                Form::getIsSigned(void) const {
    return is_signed_;
}

int                 Form::getMinGradeToSign(void) const {
    return min_grade_to_sign_;
}

int                 Form::getMinGradeToExecute(void) const {
    return min_grade_to_execute_;
}

void                Form::beSigned(const Bureaucrat& signer) {
    if (signer.getGrade() > min_grade_to_sign_) {
        throw Form::GradeTooLowException("low");
    }
    if (is_signed_) {
        std::cout
            << Constants::kTextWarning
            << "[" << this << "] "
            << "This Form seems to be already signed...?"
            << Constants::kTextReset << std::endl;
    }
    is_signed_ = true;
}

std::ostream&   operator<<(std::ostream& stream, const Form& value) {
    return stream
        << Constants::kTextInfo
        << "[" << &value << "] "
        << "a Form <" << value.getName()
        << "> is " << (value.getIsSigned() ? "SIGNED" : "NOT SIGNED")
        << ", requires " << value.getMinGradeToSign() << " grade to sign, and"
        << " requires " << value.getMinGradeToExecute() << " grade to execute"
        << Constants::kTextReset;
}
