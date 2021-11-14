#ifndef CPP05_EX04_PRESIDENTIALPERDONFORM_HPP_
# define CPP05_EX04_PRESIDENTIALPERDONFORM_HPP_

# include <iostream>
# include <cstdlib>
# include "Form.hpp"

class PresidentialPardonForm: public Form {
    public:
        PresidentialPardonForm(std::string target = "");
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &from);
        PresidentialPardonForm&  operator=(const PresidentialPardonForm &rhs);

        static const int    kMinGradeToSign     = 25;
        static const int    kMinGradeToExecute  = 5;

        const std::string&  getTarget(void) const;
        virtual void        execute(Bureaucrat const & executor) const;

    private:
        static void         assertGradeIsInRange(int grade);

        const std::string  target_;

        void                executeCore(void) const;
};

#endif
