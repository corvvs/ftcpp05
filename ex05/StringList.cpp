#include "StringList.hpp"

StringList::StringList():
    str_(""), next_(NULL), no_delete_recursive_(false)
{
    std::cout
        << Constants::kTextWarning
        << "[" << this <<":StringListStringList] "
        << "default constructor for StringList is not recommended"
        << Constants::kTextReset << std::endl;
}

StringList::StringList(const std::string str):
    str_(str), next_(NULL), no_delete_recursive_(false)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this <<":StringList] "
        << "created with \"" << str << "\""
        << Constants::kTextReset << std::endl;
}

StringList::StringList(const StringList &from):
    str_(from.str_), next_(NULL), no_delete_recursive_(false)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this <<":StringList] "
        << "duplicated with \"" << str_ << "\""
        << Constants::kTextReset << std::endl;
    StringList *to_head = this;
    StringList *from_head = &(const_cast<StringList&>(from));
    try {
        int i = 0;
        while (from_head->next_) {
            // for exception testing
            // if (i == 2) {
            //     new StringList[-i];
            // }
            to_head->next_ = new StringList(from_head->next_->str_);
            to_head = to_head->next_;
            from_head = from_head->next_;
            i += 2;
        }
    } catch (std::bad_alloc& e) {
        delete this->next_;
        throw e;
    }
}

StringList& StringList::operator=(const StringList &rhs) {
    std::cout
        << Constants::kTextError
        << "[" << this <<":StringList::operator=] "
        << "Pardon?"
        << Constants::kTextReset << std::endl;
    if (this == &rhs) {
        return *this;
    }
    const_cast<std::string&>(str_) = rhs.str_;
    StringList* temp = rhs.next_ ? new StringList(*rhs.next_) : NULL;
    if (next_ != rhs.next_) {
        delete next_;
    }
    next_ = temp;
    return *this;
}

StringList::~StringList() {
    if (no_delete_recursive_) {
        std::cout
            << Constants::kTextLifeCycle
            << "[" << this <<":~StringList] "
            << "do nothing with \"" << str_ << "\""
            << Constants::kTextReset << std::endl;
        return;
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this <<":~StringList] "
        << "start recursive delete with \"" << str_ << "\""
        << Constants::kTextReset << std::endl;
    StringList* head = this->next_;
    while (head) {
        StringList* temp = head->next_;
        head->no_delete_recursive_ = true;
        delete head;
        head = temp;
    }
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
