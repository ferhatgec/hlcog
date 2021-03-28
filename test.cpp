#include <iostream>
#include "include/hlcog_structure.hpp"
#include "include/hlcog_syntax_rules.hpp"

#include "include/hlcog_cg_main.hpp"


#include "include/cg/hlcog_cg_python.hpp"
#include "include/cg/hlcog_cg_cpp.hpp"

int main() {
    HlCoG::HLCoG_Codegen cog(HLCoGLanguages::Python);

    HlCoG_Metadata meta;

    meta.metadata = std::make_tuple(HlCoGTokens::If, "", "test == 'Hi'", "");
    cog.VariableType(HlCoGTokens::If, meta, HlCoGPython::InitSyntax(), HlCoGPython::InitRules());

    // TODO: More syntax rules
    meta.metadata = std::make_tuple(HlCoGTokens::Print, "", "'Hello, world!'", "");

    cog.VariableType(HlCoGTokens::Print, meta, HlCoGPython::InitSyntax(), HlCoGPython::InitRules());

    meta.metadata = std::make_tuple(HlCoGTokens::Variable, "hi", "Hello, world!", "");

    cog.VariableType(HlCoGTokens::Variable, meta, HlCoGPython::InitSyntax(), HlCoGPython::InitRules());

    meta.metadata = std::make_tuple(HlCoGTokens::Return, "", "20", "");

    cog.VariableType(HlCoGTokens::Return, meta, HlCoGPython::InitSyntax(), HlCoGPython::InitRules());

    meta.metadata = std::make_tuple(HlCoGTokens::Function, "str", "idk", "my_variable");

    cog.VariableType(HlCoGTokens::Function, meta, HlCoGPython::InitSyntax(), HlCoGPython::InitRules());

    // Type converter does not supported yet.
    cog.VariableType(HlCoGTokens::Function, meta, HlCoGCPP::InitSyntax(), HlCoGCPP::InitRules());

    std::cout << cog.GetGenerated() << '\n';

    return 0;
}