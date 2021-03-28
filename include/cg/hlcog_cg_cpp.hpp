// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//
// C++ code-generator
// and initializer supportter
// front-end for HLCoG.
//

#ifndef HLCOG_CG_CPP_HPP
#define HLCOG_CG_CPP_HPP

#include "../hlcog_structure.hpp"
#include "../hlcog_cg_main.hpp"

namespace HlCoGCPP {
    HlCoGSyntax        InitSyntax() {
        HlCoGSyntax        syntax;

        syntax.syntax.push_back("auto"   );// Variable definition
        syntax.syntax.push_back("if"     );// If
        syntax.syntax.push_back("else"   );// Else
        syntax.syntax.push_back("else if");// ElseIf

        syntax.syntax.push_back("cout"   );// Print (*STL*)

        syntax.syntax.push_back("void"   );// Function

        syntax.syntax.push_back("include");// Import
        syntax.syntax.push_back("return"); // Return

        syntax.variable_types.push_back("int");
        syntax.variable_types.push_back("int8_t");
        syntax.variable_types.push_back("int16_t");
        syntax.variable_types.push_back("int32_t");
        syntax.variable_types.push_back("int64_t");

        syntax.variable_types.push_back("uint8_t");
        syntax.variable_types.push_back("uint16_t");
        syntax.variable_types.push_back("uint32_t");
        syntax.variable_types.push_back("uint64_t");

        syntax.variable_types.push_back("float");

        syntax.variable_types.push_back("char");
        syntax.variable_types.push_back("short");
        syntax.variable_types.push_back("long");
        syntax.variable_types.push_back("string");

        return syntax;
    }

    HlCoG_Syntax_Rules InitRules () {
        HlCoG_Syntax_Rules rules;

        // if     (...) {
        // else if(...) {
        // else         {
        rules.If(true, true, "", "");
        rules.Else(true, false, "", "");
        rules.ElseIf(true, true, "", "");

        rules.FunctionNotation(true, true, false, "", "", "");

        // std::cout << ...;
        rules.Print(false, "std::", ";");

        // return ...;
        rules.Return(false, "", ";");

        return rules;
    }
}

#endif // HLCOG_CG_CPP_HPP
