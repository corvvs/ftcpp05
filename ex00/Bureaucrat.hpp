#ifndef CPP05_EX00_BUREAUCRAT_HPP_
# define CPP05_EX00_BUREAUCRAT_HPP_

# include <string>
# include <iostream>
# include <exception>
# include <stdexcept>
# include "Constants.hpp"

class Bureaucrat {
    public:
        class GradeTooHighException: public std::runtime_error {
            public:
                GradeTooHighException(const char *_message);
                const char* what() const _NOEXCEPT;
        };
        class GradeTooLowException: public std::runtime_error {
            public:
                GradeTooLowException(const char *_message);
                const char* what() const _NOEXCEPT;
        };

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &from);
        Bureaucrat& operator=(const Bureaucrat &rhs);

        static const int    kHighestGrade  = 1;
        static const int    kLowestGrade   = 150;

        const std::string&  getName(void) const;
        int                 getGrade(void) const;

        void                incrementGrade(void);
        void                decrementGrade(void);

    private:

        const std::string   name_;
        int                 grade_;

        static void         assertGradeIsInRange(int grade);
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& value);

#endif
