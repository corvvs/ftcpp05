#ifndef CPP05_EX05_STRINGQUEUE_HPP_
# define CPP05_EX05_STRINGQUEUE_HPP_

# include <iostream>
# include <string>
# include <new>
# include "Constants.hpp"

class StringList {
    public:
        StringList(const std::string str);
        StringList(const StringList &from);
        StringList& operator=(const StringList &rhs);
        ~StringList();

        const std::string&  getStr(void) const;
        StringList*         getNext(void) const;

        void                setStr(const std::string str);
        void                setNext(StringList* next);

    private:
        StringList();

        const std::string   str_;
        StringList*         next_;
        bool                no_delete_recursive_;
};

#endif
