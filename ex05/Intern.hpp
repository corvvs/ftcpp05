#ifndef CPP05_EX05_INTERN_HPP_
# define CPP05_EX05_INTERN_HPP_

# include <iostream>
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

        static std::size_t  IndexForFormName(const std::string form_name);

        Form*   makeForm(
            const std::string form_name,
            const std::string target_name
        ) const;
};

#endif
