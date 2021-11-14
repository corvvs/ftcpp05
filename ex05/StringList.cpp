#include "StringList.hpp"

StringList::StringList():
    str_(""), next_(NULL)
{
    std::cout
        << Constants::kTextWarning
        << "[" << this <<":StringListStringList] "
        << "default constructor for StringList is not recommended"
        << Constants::kTextReset << std::endl;
}

StringList::StringList(const std::string str):
    str_(str), next_(NULL)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this <<":StringList] "
        << "created with \"" << str << "\""
        << Constants::kTextReset << std::endl;
}

StringList::StringList(const StringList &from): next_(from.next_) {
    if (from.next_) {
        next_ = new StringList(*from.next_);
    } else {
        next_ = NULL;
    }
}

StringList& StringList::operator=(const StringList &rhs) {
    const_cast<std::string&>(str_) = rhs.str_;
    if (next_ != rhs.next_) {
        delete next_;
    }
    next_ = rhs.next_ ? new StringList(*rhs.next_) : NULL;
    return *this;
}

StringList::~StringList() {
    delete next_;
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this <<":~StringList] "
        << "destroyed with \"" << str_ << "\""
        << Constants::kTextReset << std::endl;
}

const std::string&  StringList::getStr(void) const {
    return str_;
}

StringList*        StringList::getNext(void) const {
    return next_;
}

void                StringList::setStr(const std::string str) {
    const_cast<std::string&>(str_) = str;
}

void                StringList::setNext(StringList* next) {
    next_ = next;
}
