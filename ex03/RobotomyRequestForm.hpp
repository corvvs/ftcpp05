#ifndef CPP05_EX03_ROBOTOMYREQUESTFORM_HPP_
# define CPP05_EX03_ROBOTOMYREQUESTFORM_HPP_

# include <iostream>
# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm: public Form {
    public:
        RobotomyRequestForm(const std::string target = "");
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &from);
        RobotomyRequestForm&  operator=(const RobotomyRequestForm &rhs);

        static const int    kMinGradeToSign     = 72;
        static const int    kMinGradeToExecute  = 45;

        const std::string&  getTarget(void) const;
        virtual void        execute(Bureaucrat const & executor) const;

    private:
        static void         assertGradeIsInRange(int grade);

        const std::string  target_;

        void                executeCore(void) const;
};

#endif
