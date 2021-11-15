#ifndef CPP05_EX01_FORM_HPP_
# define CPP05_EX01_FORM_HPP_

# include <string>
# include <iostream>
# include <exception>
# include <stdexcept>
# include "Constants.hpp"

class Bureaucrat;

class Form {
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

        Form();
        Form(
            std::string name,
            int min_grade_to_sign,
            int min_grade_to_execute
        );
        virtual ~Form();
        Form(const Form &from);
        Form& operator=(const Form &rhs);

        static const int    kHighestGrade  = 1;
        static const int    kLowestGrade   = 150;

        const std::string&  getName(void) const;
        bool                getIsSigned(void) const;
        int                 getMinGradeToSign(void) const;
        int                 getMinGradeToExecute(void) const;

        void                beSigned(const Bureaucrat& signer);

    private:

        const std::string   name_;
        bool                is_signed_;
        const int           min_grade_to_sign_;
        const int           min_grade_to_execute_;

        static void         assertGradeIsInRange(int grade);
};

std::ostream& operator<<(std::ostream& stream, const Form& value);

# include "Bureaucrat.hpp"

#endif
