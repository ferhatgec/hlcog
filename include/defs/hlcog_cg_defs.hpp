// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#ifndef HLCOG_CG_DEFS_HPP
#define HLCOG_CG_DEFS_HPP

#include <tuple>
#include <string>
#include "../hlcog_structure.hpp"
#include "../hlcog_syntax_rules.hpp"


namespace HlCogDefs {
    static void VariablePush(
                HLCoGLanguages& language,
                std::string& data,
                const std::string& variable_name,
                const std::string& variable_data) noexcept {
        if(language == HLCoGLanguages::Python) {
            data.append(variable_name + "= '" + variable_data + "'");
        }

        data.push_back('\n');
    }

    static void StatementPush(
                HLCoGLanguages language,
                std::string& data,
                HlCoGSyntax syntax,
                HlCoGTokens token,
                std::tuple<bool, bool, std::string, std::string> rules,
                const std::string& arguments) {
        data.append(std::get<2>(rules) + syntax.syntax[static_cast<const u8>(token)] + " ");

        if(std::get<1>(rules)) {
            // TODO: Include operator overloaders for syntax rules.
            data.append("(" + arguments + ")" + std::get<3>(rules));
        }
        else {
            data.append(arguments + std::get<3>(rules));
        }

        if(std::get<0>(rules)) {
            data.push_back('{');
        }

        data.push_back('\n');
    }

    static void FunctionPush(
                HLCoGLanguages language,
                std::string& data,
                HlCoGSyntax syntax,
                HlCoGTokens token,
                std::tuple<bool, std::string, std::string> rules,
                const std::string& arguments) {
        data.append(std::get<1>(rules) + syntax.syntax[static_cast<const u8>(token)] + " ");

        if(std::get<0>(rules)) {
            data.append("(" + arguments + ")" + std::get<2>(rules));
        }
        else {
            data.push_back(' ');
            data.append(arguments + std::get<2>(rules));
        }

        data.push_back('\n');
    }

    // return -31;
    static void ReturnPush(
                HLCoGLanguages language,
                std::string& data,
                HlCoGSyntax syntax,
                HlCoGTokens token,
                std::tuple<bool, std::string, std::string> rules,
                const std::string& arguments) {
        FunctionPush(language, data, syntax, token, rules, arguments);
    }

    static void FunctionNotationPush(
                HLCoGLanguages language,
                std::string& data,
                HlCoGSyntax syntax,
                HlCoGTokens token,
                std::tuple<bool, bool, bool, std::string, std::string, std::string> rules,
                //         ^^^^  ^^^^  ^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^
                //         *     /     -     &            %            @
                //
                // * = use_brackets
                // / = use_parentheses
                // - = notation type align (false: left, true: right)
                // & = starts_with
                // % = ends_with
                // @ = type_operator
                //
                // starts_with = "def"
                // ends_with   = ":"
                // type_operator = "->"
                // notation_type = right
                // use_brackets  = false
                // use_parentheses = true
                //
                // def ... (...) -> ... :
                // ^^^ ^^^ ^^^^^ ^^ ^^^ ^
                // &   data args @  -   %
                //
                const std::string& notation_name,
                const std::string& arguments,
                const std::string& return_type
            ) {
        if(!std::get<3>(rules).empty()) {
            data.append(std::get<3>(rules) + " ");
        }

        if(!std::get<2>(rules)) {
            data.append(return_type + " ");
        }

        data.append(notation_name);

        if(std::get<1>(rules)) {
            data.push_back('(');
            data.append(arguments);
            data.push_back(')');
        }

        data.append(" " + std::get<5>(rules) + " ");

        if(std::get<2>(rules)) {
            data.append(return_type);
        }

        data.append(std::get<4>(rules));

        if(std::get<0>(rules)) {
            data.push_back('{');
        }

        data.push_back('\n');
    }
}

#endif // HLCOG_CG_DEFS_HPP
