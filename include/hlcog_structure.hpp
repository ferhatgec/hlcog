// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef HLCOG_STRUCTURE_HPP
#define HLCOG_STRUCTURE_HPP

#include <iostream>
#include <tuple>
#include <vector>

#include "defs/hlcog_defs.hpp"

enum class HLCoGLanguages  : const u8 {
    Python
};

enum class HlCoGTokens : const u8 {
    Variable,

    If,
    Else,
    ElseIf,

    Print,

    Function,

    Import,
    Return
};

class HlCoGSyntax {
public:
    std::vector<std::string> syntax;
};

class HlCoG_Metadata {
public:
    std::tuple<HlCoGTokens, std::string, std::string, std::string> metadata;
    //         ^^^^^^^^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^
    //         tokens    variable name  variable data  notation name (for functions)
    //                                   (or arguments)
};

class HLCoG_Structure {
    HLCoGLanguages used;
public:
    HLCoG_Structure(HLCoGLanguages& language) {
        this->used = language;
    }

    ~HLCoG_Structure()= default;
};

#endif // HLCOG_STRUCTURE_HPP
