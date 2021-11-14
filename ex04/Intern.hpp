#ifndef CPP05_EX04_INTERN_HPP_
# define CPP05_EX04_INTERN_HPP_

# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class   Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern &from);
        Intern& operator=(const Intern &rhs);

        static const std::size_t kConcreteFormNum = 3;
        static const std::string kConcreteFormNames[kConcreteFormNum];

        Form*   makeForm(
            std::string form_name,
            std::string target_name
        ) const;
};

#endif
