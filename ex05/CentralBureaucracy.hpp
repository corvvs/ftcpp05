#ifndef CPP05_EX05_CENTRALBUREAUCRACY_HPP_
# define CPP05_EX05_CENTRALBUREAUCRACY_HPP_

# include <iostream>
# include <string>
# include <cstdlib>
# include "StringList.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "OfficeBlock.hpp"
# include "Constants.hpp"

class CentralBureaucracy {
    public:
        CentralBureaucracy();
        CentralBureaucracy(const CentralBureaucracy &from);
        CentralBureaucracy& operator=(const CentralBureaucracy &rhs);
        ~CentralBureaucracy();

        static const std::size_t    kOfficeBlockNumber = 20;

        bool    feedBureaucrat(Bureaucrat& crat);
        void    queueUp(std::string target_name);
        void    doBureaucracy(void);

        const OfficeBlock*  getOfficeBlocks(void) const;
        const StringList*   getTargetQueue(void) const;

    private:
        OfficeBlock office_blocks_[CentralBureaucracy::kOfficeBlockNumber];
        StringList* target_queue_;
};

#endif
