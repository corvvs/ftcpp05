#include "OfficeBlock.hpp"

OfficeBlock::IncompleteBlockException::IncompleteBlockException(const char *_message):
    std::runtime_error(_message) {}

const char* OfficeBlock::IncompleteBlockException::what() const _NOEXCEPT {
    return "OfficeBlock: Block has any blank position.";
}

OfficeBlock::UnknownFormException::UnknownFormException(const char *_message):
    std::runtime_error(_message) {}

const char* OfficeBlock::UnknownFormException::what() const _NOEXCEPT {
    return "OfficeBlock: Form to execute is unknown.";
}
