// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#ifndef HLCOG_CG_CONVERT_HPP
#define HLCOG_CG_CONVERT_HPP

#include "../hlcog_structure.hpp"

namespace HlCogConvert {
    static std::string Convert(
                HLCoGLanguages     language     ,
                HlCoGSyntax        target_syntax,
                HlCoGVariableTypes type
    ) {
        if(target_syntax.is_auto) {
            return "";
        }

        return target_syntax.variable_types[static_cast<const u8>(type)];
    }
}
#endif //HLCOG_HLCOG_CG_CONVERT_HPP
