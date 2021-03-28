//
// What's this?
//
// HLCoG (long-form: High-level Code-Generator (aka Transpiler))
//  * It's high level only-header shell for
//    compiler and transpiler development.
//  * It's customizable & can be implemented all
//    languages without pain.
//  * Written in C++, only headers, not shared libraries.
//  * You can directly link HLCoG with your AST.
//
// HLCoG offers only Python code-generator support for now,
// but it's customizable (up to *), and can be implemented other languages
// (Ruby, C++, C, Go, JavaScript, Objective-C etc..)
//
// It's at early-stage, work-in-progress.
//
// ok. What am I supposed to do with HLCoG???
// * If you want to create your own programming language,
// or transpiler, HLCoG makes code-generation easier.
//
// HLCoG will be support these languages for code-generation:
//
// Fully Python port (Python2, Python3)
// C++
// C
// Kalem             (It's a transpiler too)
// Ruby
// Assembly          (x86_64, i386, ARM32)
// and more!
//
//
// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef HLCOG_CG_MAIN_HPP
#define HLCOG_CG_MAIN_HPP

#include <iostream>
#include "hlcog_structure.hpp"

#include "defs/hlcog_defs.hpp"
#include "defs/hlcog_cg_defs.hpp"

#include "hlcog_syntax_rules.hpp"

#include "cg/hlcog_cg_python.hpp"

namespace HlCoG {
    class HLCoG_Codegen {
        std::string    generated;
        HLCoGLanguages language;
    public:
        HLCoG_Codegen(HLCoGLanguages language) {
            this->language = language;
        }

        ~HLCoG_Codegen() = default;

        std::string GetGenerated() noexcept {
            return this->generated;
        }

        void VariableType(HlCoGTokens type, HlCoG_Metadata data, HlCoGSyntax syntax, HlCoG_Syntax_Rules rules) noexcept {
            switch(type) {
                case HlCoGTokens::Variable: {
                    //if(this->language == HLCoGLanguages::Python) {
                        HlCogDefs::VariablePush(
                                this->language,
                                generated     ,
                                std::get<1>(data.metadata),
                                std::get<2>(data.metadata)
                        );
                    //}

                    break;
                }

                case HlCoGTokens::Else  :
                case HlCoGTokens::ElseIf:
                case HlCoGTokens::If    : {
                    //if(this->language == HLCoGLanguages::Python) {
                        HlCogDefs::StatementPush(this->language,
                                                 generated  ,
                                                 syntax        ,
                                                 type          ,
                                                 rules.SRIf    ,
                                                 std::get<2>(data.metadata)
                        );
                    //}

                    break;
                }

                case HlCoGTokens::Function: {
                    HlCogDefs::FunctionNotationPush(this->language,
                                                    generated     ,
                                                    syntax        ,
                                                    HlCoGTokens::Function     ,
                                                    rules.SRFunctionNotation  ,
                                                    std::get<3>(data.metadata),
                                                    std::get<2>(data.metadata),
                                                    std::get<1>(data.metadata),
                                                    data.function_return_type
                    );

                    break;
                }

                case HlCoGTokens::Print: {
                    //if(this->language == HLCoGLanguages::Python) {
                        HlCogDefs::FunctionPush(
                                this->language    ,
                                generated         ,
                                syntax            ,
                                HlCoGTokens::Print,
                                rules.SRPrint     ,
                                std::get<2>(data.metadata)
                        );
                    //}

                    break;
                }

                case HlCoGTokens::Return: {
                    //if(this->language == HLCoGLanguages::Python) {
                        HlCogDefs::ReturnPush(
                                this->language     ,
                                generated          ,
                                syntax             ,
                                HlCoGTokens::Return,
                                rules.SRReturn     ,
                                std::get<2>(data.metadata)
                        );

                        break;
                    //}
                }
            }
        }
    };
}


#endif // HLCOG_CG_MAIN_HPP