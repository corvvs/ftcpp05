#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
    Form("ShrubberyCreation", ShrubberyCreationForm::kMinGradeToSign, ShrubberyCreationForm::kMinGradeToExecute),
    target_(target.length() > 0 ? target : "<unknown>") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &from):
    Form(from), target_(from.target_) {}

ShrubberyCreationForm&   ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    this->Form::operator=(rhs);
    const_cast<std::string&>(target_) = rhs.target_;
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    assertIsExecutable(executor);
    executeCore();
}

void    ShrubberyCreationForm::executeCore(void) const {
    std::string filename = target_ + "_shrubbery";
    {
        std::ofstream ofs;
        ofs.exceptions(std::ios::failbit | std::ios::badbit);
        ofs.open(filename);
        ofs
            << "                                    ...                                      " << std::endl
            << "                                  .+MMMMMNL                                  " << std::endl
            << "                                 ,MMMMMMMMF                                  " << std::endl
            << "                                     MMMMM    ...                            " << std::endl
            << "                                     dMMMMgMMMMMMMMNa,                       " << std::endl
            << "                                  ..JMMMMMMMMMMMMMMMM                        " << std::endl
            << "                             ..JNMMMMMMMMMMM#9'!                             " << std::endl
            << "                       ...gMMMMMMMMMMMMMM'`                                  " << std::endl
            << "                ....gNMMMMMMMMMMMMW'WMMM]                                    " << std::endl
            << "                 ?TMMMMMMMMHWM#=    JMMMb .....-JJJ.....                     " << std::endl
            << "                          .gM@    ..dMMMMMMMMMMMMMMMMMMMMNe                  " << std::endl
            << "                        .MMMD..JNMMB4MMM#`       ?TMMMMMMM@`                 " << std::endl
            << "                      .MMMMMMH'^    .MMM#       ..dMB''^                     " << std::endl
            << "                    .MMMMM'!        .MMMN_     ?`                            " << std::endl
            << "                  .MMM#'      TNg++MMMMMM:     .gMMNJ.                       " << std::endl
            << "                .MMM'`         (MMMMMMMM#     .MMMMMMMN-                     " << std::endl
            << "                .#^   .+gJ,      ?MMMMMMt         ?MMM#`                     " << std::endl
            << "                      TMMMM:       7MMMD          .MMMN,....J-..             " << std::endl
            << "                        MMN,..                  ..gMMMMMMMMMMMMMMp           " << std::endl
            << "                       .MMMMMMMMMm           .+MMMMMMMMMMB'''''''^           " << std::endl
            << "                   ..+MMMMMMMMMMB=       ..MMMMMMMMMMM]                      " << std::endl
            << "               ..+MMMMMMMMMM#'`       .JMMMMM9^(MMMMMM{                      " << std::endl
            << "            .JMMMMMMMMMMMM`        .gMMMM9!  .dMMMMMMM`                      " << std::endl
            << "        ..MMMMMMMM#'4MMMMM      .gMMM#=     .MMMM=MMMM                       " << std::endl
            << "    ..gMMMMMMB'!   .MMMMMM_  .dMMMB^      .MMMMY  MMM#                       " << std::endl
            << "    ?""""!        .MMMMMMMmgMMMM=       .dMMMB` ..MMMN.........              " << std::endl
            << "                 .MMMMMMMMMMM9!       .&MMMMNgMMMMMMMMMMMMMMMMMMMNN&..       " << std::endl
            << "                (MMMMMMMMMM'        .+MMMMMMB'7`  dMMM] _7TMMMMMMMMMMMNg,    " << std::endl
            << "              .MMMMMMMMMMF        .uMMMM#'`       JMMM]      -TMMMMMMMMMMNe. " << std::endl
            << "            .jMMMMMMMMMMM]   .a .dMMMM#`          JMMM]          +MMMMMMMMMb " << std::endl
            << "           .MMMMMMMM'`dMM]  (MNMMMM#! MN.         JMMM]        .+MMMMMMMMMM5 " << std::endl
            << "         .MMMMMMM#^   MMMt .MMMMM#^    WN,        JMMM]        !~``          " << std::endl
            << "       .+MMMMMM#'    .MMM) MMMM'`       ?MN,      JMMM]                      " << std::endl
            << "      .MMMMMM#!      dMMM]  `            .MMMa....MMMMF                      " << std::endl
            << "      dMMMMB!        JMMMF                 TMMMMMMMMMMF                      " << std::endl
            << "      dMM@!          .MMM\\                  ?MMMMMMMMF                      " << std::endl
            << "       ?               7'                    /MMMMMMF                        " << std::endl
            << "                                               TMMMt                         " << std::endl;
    }
    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "a Shrubbery has been planted at "
        << filename
        << ", accroding to the Form"
        << Constants::kTextReset << std::endl;
}
