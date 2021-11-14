#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock():
    intern_(NULL),
    signer_(NULL),
    executor_(NULL)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a blank OfficeBlock has been built"
        << Constants::kTextReset << std::endl;
}

OfficeBlock::OfficeBlock(
    Intern* intern,
    Bureaucrat* signer,
    Bureaucrat* executor
):
    intern_(intern),
    signer_(signer),
    executor_(executor)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "an OfficeBlock has been built"
        << Constants::kTextReset << std::endl;
}

OfficeBlock::~OfficeBlock() {
    delete intern_;
    delete signer_;
    delete executor_;
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a blank OfficeBlock has been imploded. The world is fragile."
        << Constants::kTextReset << std::endl;
}

OfficeBlock::OfficeBlock(const OfficeBlock &from):
    intern_(NULL),
    signer_(NULL),
    executor_(NULL)
{
    (void)from;
    std::cout
        << Constants::kTextError
        << "[" << this << "] "
        << "copy of OfficeBlock is wrong"
        << Constants::kTextReset << std::endl;
}

OfficeBlock&    OfficeBlock::operator=(const OfficeBlock &rhs) {
    (void)rhs;
    std::cout
        << Constants::kTextError
        << "[" << this << "] "
        << "assignation of OfficeBlock is wrong"
        << Constants::kTextReset << std::endl;
    return *this;
}

void    OfficeBlock::doBureaucracy(
    std::string form_name,
    std::string target_name
) {
    if (!intern_ || !signer_ || !executor_) {
        std::cout
            << Constants::kTextWarning
            << "[" << this <<"] "
            << "The OfficeBlock is incomplete"
            << Constants::kTextReset << std::endl;
        return;
    }
    Form *aform = intern_->makeForm(form_name, target_name);
    if (!aform) {
        return;
    }
    signer_->signForm(*aform);
    executor_->executeForm(*aform);
    delete aform;
}
