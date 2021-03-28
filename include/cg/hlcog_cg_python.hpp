// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//
// Python3 code-generator
// and initializer supporter
// front-end for HLCoG.
//
#ifndef HLCOG_CG_PYTHON_HPP
#define HLCOG_CG_PYTHON_HPP

#include "../hlcog_structure.hpp"
#include "../hlcog_cg_main.hpp"

namespace HlCoGPython {
    HlCoGSyntax        InitSyntax() {
        HlCoGSyntax        syntax;

        syntax.syntax.push_back("");    // Variable definition
        syntax.syntax.push_back("if");  // If
        syntax.syntax.push_back("else");// Else
        syntax.syntax.push_back("elif");// ElseIf

        syntax.syntax.push_back("print");// Built-in Print

        syntax.syntax.push_back("def"); // Function

        syntax.syntax.push_back("import");// Import
        syntax.syntax.push_back("return");// Return

        return syntax;
    }

    HlCoG_Syntax_Rules InitRules () {
        HlCoG_Syntax_Rules rules;

        // if   ...:
        // elif ...:
        // else ...:
        rules.If    (false, false, "", ":");
        rules.Else  (false, false, "", ":");
        rules.ElseIf(false, false, "", ":");

        // def ...(...) -> ...:
        rules.FunctionNotation(false, true, true, "def", ":", "->");

        // print(...)
        rules.Print (true, "", "");

        // return ...
        rules.Return(false, "", "");

        return rules;
    }
}

#endif // HLCOG_CG_PYTHON_HPP
