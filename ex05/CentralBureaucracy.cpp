#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy():
    target_queue_(NULL) {}

CentralBureaucracy::CentralBureaucracy(const CentralBureaucracy &from):
    target_queue_(NULL)
{
    target_queue_ = from.target_queue_ ? new StringList(*(from.target_queue_)) : NULL;
    for(std::size_t i = 0; i < CentralBureaucracy::kOfficeBlockNumber; i += 1) {
        office_blocks_[i].setSigner(
            const_cast<Bureaucrat *>(from.office_blocks_[i].getSigner())
        );
        office_blocks_[i].setExecutor(
            const_cast<Bureaucrat *>(from.office_blocks_[i].getExecutor())
        );
    }
}

CentralBureaucracy& CentralBureaucracy::operator=(const CentralBureaucracy &rhs) {
    if (this == &rhs) {
        return *this;
    }
    StringList *temp = rhs.target_queue_ ? new StringList(*rhs.target_queue_) : NULL;
    if (target_queue_ != rhs.target_queue_) {
        delete target_queue_;
    }
    target_queue_ = temp;
    for(std::size_t i = 0; i < CentralBureaucracy::kOfficeBlockNumber; i += 1) {
        office_blocks_[i].setSigner(
            const_cast<Bureaucrat *>(rhs.office_blocks_[i].getSigner())
        );
        office_blocks_[i].setExecutor(
            const_cast<Bureaucrat *>(rhs.office_blocks_[i].getExecutor())
        );
    }
    return *this;
}

CentralBureaucracy::~CentralBureaucracy() {
    delete target_queue_;
}

bool    CentralBureaucracy::feedBureaucrat(Bureaucrat& crat) {
    for (std::size_t i = 0; i < CentralBureaucracy::kOfficeBlockNumber; i += 1) {
        if (!office_blocks_[i].getSigner()) {
            office_blocks_[i].setSigner(&crat);
            std::cout
                << Constants::kTextInfo
                << "[" << this << ":feedBureaucrat] "
                << "a Bureaucrat " << crat.getName() << "(" << crat.getGrade() << ")"
                << " has been assigned at a signer of block #" << i
                << Constants::kTextReset << std::endl;
            return true;
        }
        if (!office_blocks_[i].getExecutor()) {
            office_blocks_[i].setExecutor(&crat);
            std::cout
                << Constants::kTextInfo
                << "[" << this << ":feedBureaucrat] "
                << "a Bureaucrat " << crat.getName() << "(" << crat.getGrade() << ")"
                << " has been assigned at an executor of block #" << i
                << Constants::kTextReset << std::endl;
            return true;
        }
    }
    std::cout
        << Constants::kTextWarning
        << "[" << this << ":feedBureaucrat] "
        << "no vacant OfficeBlock"
        << Constants::kTextReset << std::endl;
    return false;
}

void    CentralBureaucracy::queueUp(std::string target_name) {
    if (target_queue_) {
        StringList* head = target_queue_;
        while (head->getNext()) {
            head = head->getNext();
        }
        head->setNext(new StringList(target_name));
        std::cout
            << Constants::kTextInfo
            << "[" << this << ":queueUp] "
            << target_name << " is at end of the queue"
            << Constants::kTextReset << std::endl;
    } else {
        target_queue_ = new StringList(target_name);
        std::cout
            << Constants::kTextInfo
            << "[" << this << ":queueUp] "
            << target_name << " is at top of the queue"
            << Constants::kTextReset << std::endl;
    }
}

void    CentralBureaucracy::doBureaucracy(void) {
    if (!target_queue_) {
        std::cout
            << Constants::kTextWarning
            << "[" << this << ":doBureaucracy] "
            << "target queue is empty"
            << Constants::kTextReset << std::endl;
        return;
    }
    StringList *head = target_queue_;
    target_queue_ = target_queue_->getNext();
    head->setNext(NULL);

    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "doBureaucracy for " << head->getStr() << ""
        << Constants::kTextReset << std::endl;
    for (std::size_t i = 0; i < CentralBureaucracy::kOfficeBlockNumber; i += 1) {
        std::cout
            << Constants::kTextInfo
            << "[" << this << "] "
            << "<<" << i << ">>"
            << Constants::kTextReset << std::endl;
        std::string form_name
            = Intern::kConcreteFormNames[std::rand() % Intern::kConcreteFormNum];
        Intern dust;
        office_blocks_[i].setIntern(&dust);
        office_blocks_[i].doBureaucracy(form_name, head->getStr());
        office_blocks_[i].setIntern(NULL);
    }
    delete head;
}
