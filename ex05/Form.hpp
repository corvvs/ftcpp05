#ifndef CPP05_EX05_FORM_HPP_
# define CPP05_EX05_FORM_HPP_

# include <string>
# include <iostream>
# include <exception>
# include <stdexcept>
# include "Constants.hpp"

class Bureaucrat;

class Form {
    public:
        virtual ~Form();

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
        class ExecuteWithoutSignedException: public std::runtime_error {
            public:
                ExecuteWithoutSignedException(const char *_message);
                const char* what() const _NOEXCEPT;
        };

        static const int    kHighestGrade  = 1;
        static const int    kLowestGrade   = 150;

        const std::string&  getName(void) const;
        bool                getIsSigned(void) const;
        int                 getMinGradeToSign(void) const;
        int                 getMinGradeToExecute(void) const;

        void                beSigned(const Bureaucrat& signer);
        virtual void        execute(Bureaucrat const & executor) const = 0;

    protected:
        Form();
        Form(
            std::string name,
            int min_grade_to_sign,
            int min_grade_to_execute
        );
        Form(const Form &from);
        Form& operator=(const Form &rhs);

        void    setIsSigned(bool is_signed);

        void    assertIsSignable(Bureaucrat const & executor) const;
        void    assertIsExecutable(Bureaucrat const & executor) const;

        static void assertGradeIsInRange(
            int grade,
            int highet_grade,
            int lowest_grade
        );

    private:
        const std::string   name_;
        bool                is_signed_;
        const int           min_grade_to_sign_;
        const int           min_grade_to_execute_;

};

std::ostream& operator<<(std::ostream& stream, const Form& value);

# include "Bureaucrat.hpp"

#endif
