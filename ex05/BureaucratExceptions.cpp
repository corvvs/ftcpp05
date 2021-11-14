#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *_message):
    std::runtime_error(_message) {}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
    return "Bureaucrat: Grade is too high.";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *_message):
    std::runtime_error(_message) {}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
    return "Bureaucrat: Grade is too low.";
}
