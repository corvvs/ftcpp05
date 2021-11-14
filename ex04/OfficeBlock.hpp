#ifndef CPP05_EX04_OFFICEBLOCK_HPP_
# define CPP05_EX04_OFFICEBLOCK_HPP_

# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock {
    public:
        OfficeBlock();
        OfficeBlock(
            Intern* intern,
            Bureaucrat* signer,
            Bureaucrat* executor
        );
        ~OfficeBlock();

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
