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

// HLCoG will support casting types.
enum class HlCoGVariableTypes : const u8 {
    Int,
    Int8,
    Int16,
    Int32,
    Int64,
    // Int128
    UInt8,
    UInt16,
    UInt32,
    UInt64,

    Float,

    Char,
    Short,
    Long,
    String
};

class HlCoGSyntax {
public:
    std::vector<std::string> syntax;
    std::vector<std::string> variable_types;

    bool is_auto = false;
};

class HlCoG_Metadata {
public:
    std::tuple<HlCoGTokens, std::string, std::string, std::string> metadata;
    //         ^^^^^^^^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^
    //         tokens    variable name  variable data  notation name (for functions)
    //                                   (or arguments)

    HlCoGVariableTypes function_return_type;
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
