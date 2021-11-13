#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(const char *_message):
    std::runtime_error(_message) {}

const char* Form::GradeTooHighException::what() const _NOEXCEPT {
    return "Form: Grade is too high.";
}

Form::GradeTooLowException::GradeTooLowException(const char *_message):
    std::runtime_error(_message) {}

const char* Form::GradeTooLowException::what() const _NOEXCEPT {
    return "Form: Grade is too low.";
}

Form::ExecuteWithoutSignedException::ExecuteWithoutSignedException(const char *_message):
    std::runtime_error(_message) {}

const char* Form::ExecuteWithoutSignedException::what() const _NOEXCEPT {
    return "Form: Attemted to execute without sign.";
}
