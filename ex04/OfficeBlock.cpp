#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock():
    intern_(NULL),
    signer_(NULL),
    executor_(NULL)
{
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << ":OfficeBlock] "
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
        << "[" << this << ":OfficeBlock] "
        << "an OfficeBlock has been built"
        << Constants::kTextReset << std::endl;
}

OfficeBlock::~OfficeBlock() {
    // OfficeBlock doesn't delete.
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << ":~OfficeBlock] "
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
        << "[" << this << ":OfficeBlock] "
        << "copy of OfficeBlock is wrong"
        << Constants::kTextReset << std::endl;
}

OfficeBlock&    OfficeBlock::operator=(const OfficeBlock &rhs) {
    (void)rhs;
    std::cout
        << Constants::kTextError
        << "[" << this << ":OfficeBlock::=] "
        << "assignation of OfficeBlock is wrong"
        << Constants::kTextReset << std::endl;
    return *this;
}

const Intern*       OfficeBlock::getIntern(void) const {
    return intern_;
}

const Bureaucrat*   OfficeBlock::getSigner(void) const {
    return signer_;
}

const Bureaucrat*   OfficeBlock::getExecutor(void) const {
    return executor_;
}

void                OfficeBlock::setIntern(Intern* intern) {
    intern_ = intern;
}

void                OfficeBlock::setSigner(Bureaucrat* crat) {
    signer_ = crat;
}

void                OfficeBlock::setExecutor(Bureaucrat* crat) {
    executor_ = crat;
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
        throw OfficeBlock::IncompleteBlockException("blank");
    }
    Form *aform = intern_->makeForm(form_name, target_name);
    if (!aform) {
        std::cout
            << Constants::kTextWarning
            << "[" << this <<"] "
            << "an idiot intern has mistaken his printing job."
            << Constants::kTextReset << std::endl;
        throw OfficeBlock::UnknownFormException("unknown");
    }
    try {
        signer_->signForm(*aform);
        executor_->executeForm(*aform);
    } catch (...) {
        delete aform;
        throw;
    }
    delete aform;
}
