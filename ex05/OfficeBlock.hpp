#ifndef CPP05_EX05_OFFICEBLOCK_HPP_
# define CPP05_EX05_OFFICEBLOCK_HPP_

# include <iostream>
# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "Constants.hpp"
# include <exception>
# include <stdexcept>

class OfficeBlock {
    public:
        OfficeBlock();
        OfficeBlock(
            Intern* intern,
            Bureaucrat* signer,
            Bureaucrat* executor
        );
        ~OfficeBlock();

        class IncompleteBlockException: public std::runtime_error {
            public:
                IncompleteBlockException(const char *_message);
                const char* what() const _NOEXCEPT;
        };
        class UnknownFormException: public std::runtime_error {
            public:
                UnknownFormException(const char *_message);
                const char* what() const _NOEXCEPT;
        };

        const Intern*       getIntern(void) const;
        const Bureaucrat*   getSigner(void) const;
        const Bureaucrat*   getExecutor(void) const;

        void                setIntern(Intern* intern);
        void                setSigner(Bureaucrat* crat);
        void                setExecutor(Bureaucrat* crat);

        void                doBureaucracy(
            std::string form_name,
            std::string target_name
        );

    private:
        OfficeBlock(const OfficeBlock &from);
        OfficeBlock& operator=(const OfficeBlock &rhs);

        Intern*     intern_;
        Bureaucrat* signer_;
        Bureaucrat* executor_;
};

#endif
