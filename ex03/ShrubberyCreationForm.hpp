#ifndef CPP05_EX03_SHRUBBERYCREATIONFORM_HPP_
# define CPP05_EX03_SHRUBBERYCREATIONFORM_HPP_

# include <iostream>
# include <fstream>
# include <sstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form {
    public:
        ShrubberyCreationForm(const std::string target = "");
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &from);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm &rhs);

        static const int    kMinGradeToSign     = 145;
        static const int    kMinGradeToExecute  = 137;

        const std::string&  getTarget(void) const;
        virtual void        execute(Bureaucrat const & executor) const;

    private:
        static void         assertGradeIsInRange(int grade);

        const std::string  target_;

        void                executeCore(void) const;
};

#endif
