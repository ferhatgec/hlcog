// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//
#ifndef HLCOG_SYNTAX_RULES_HPP
#define HLCOG_SYNTAX_RULES_HPP

class HlCoG_Syntax_Rules {
public:
    std::tuple<
            bool,
            bool,
            std::string,
            std::string
    > SRIf;

    std::tuple<
            bool,
            bool,
            std::string,
            std::string
    > SRElse;

    std::tuple<
            bool,
            bool,
            std::string,
            std::string
    > SRElseIf;

    std::tuple<
            bool,
            bool,
            bool,
            std::string,
            std::string,
            std::string
    > SRFunctionNotation;

    std::tuple<
            bool,
            std::string,
            std::string
    > SRPrint;

    std::tuple<
            bool,
            std::string,
            std::string
    > SRReturn;
public:
    HlCoG_Syntax_Rules() = default;
    ~HlCoG_Syntax_Rules()= default;

    // if (test == 12)
    //
    void If(
                bool use_brackets       = true,
                bool use_parentheses    = true,
                std::string starts_with = "",
                std::string ends_with   = ""
    ) {
        this->SRIf = std::make_tuple(use_brackets, use_parentheses, starts_with, ends_with);
    }

    void Else(
                bool use_brackets       = true,
                bool use_parentheses    = true,
                std::string starts_with = "",
                std::string ends_with   = ""
    ) {
        this->SRElse = std::make_tuple(use_brackets, use_parentheses, starts_with, ends_with);
    }

    void ElseIf(
                bool use_brackets       = true,
                bool use_parentheses    = true,
                std::string starts_with = ""  ,
                std::string ends_with   = ""
    ) {
        this->SRElseIf = std::make_tuple(use_brackets, use_parentheses, starts_with, ends_with);
    }

    void FunctionNotation(
                bool use_brackets            = true ,
                bool use_parentheses         = true ,
                bool set_notation_type_align = false,
                std::string starts_with  = ""       ,
                std::string ends_with    = ""       ,
                std::string type_operator=""
    ) {
        this->SRFunctionNotation
                = std::make_tuple(use_brackets          ,
                                 use_parentheses        ,
                                 set_notation_type_align,
                                 starts_with            ,
                                 ends_with              ,
                                 type_operator);
    }


    void Print(bool use_parentheses = true,
                std::string starts_with = "",
                std::string ends_with = "") {
        this->SRPrint = std::make_tuple(use_parentheses, starts_with, ends_with);
    }

    void Return(bool use_parentheses = true,
               std::string starts_with = "",
               std::string ends_with = "") {
        this->SRReturn = std::make_tuple(use_parentheses, starts_with, ends_with);
    }
};

#endif // HLCOG_SYNTAX_RULES_HPP
