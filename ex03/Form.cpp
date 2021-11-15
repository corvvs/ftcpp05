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
    Form::assertGradeIsInRange(
        min_grade_to_sign,
        Form::kHighestGrade,
        Form::kLowestGrade
    );
    const_cast<int &>(min_grade_to_sign_) = min_grade_to_sign;
    Form::assertGradeIsInRange(
        min_grade_to_execute,
        Form::kHighestGrade,
        Form::kLowestGrade
    );
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

void    Form::assertGradeIsInRange(
    int grade,
    int highet_grade,
    int lowest_grade
) {
    if (grade < highet_grade) {
        throw Form::GradeTooHighException("high");
    }
    if (grade > lowest_grade) {
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

void    Form::beSigned(const Bureaucrat& signer) {
    if (signer.getGrade() > min_grade_to_sign_) {
        throw Form::GradeTooLowException("low");
    }
    setIsSigned(true);
}

void                Form::setIsSigned(bool is_signed) {
    if (!is_signed) {
        is_signed_ = false;
    } else {
        if (is_signed_) {
            std::cout
                << Constants::kTextWarning
                << "[" << this << "] "
                << "This Form seems to be already signed...?"
                << Constants::kTextReset << std::endl;
        }
        is_signed_ = true;
    }
}

void    Form::assertIsExecutable(Bureaucrat const & executor) const {
    if (!getIsSigned()) {
        throw Form::ExecuteWithoutSignedException("unsigned");
    }
    if (executor.getGrade() > min_grade_to_execute_) {
        throw Form::GradeTooLowException("low");
    }
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
