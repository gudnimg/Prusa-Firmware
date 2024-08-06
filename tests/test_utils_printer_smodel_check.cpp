#include "catch2/catch_test_macros.hpp"
#include "util.h"

bool printer_smodel_check(const char *pStrPos, const char *actualPrinterSModel) {
    unquoted_string smodel = unquoted_string(pStrPos);

    if(smodel.WasFound()) {
        const uint8_t compareLength = strlen(actualPrinterSModel);

        if(compareLength == smodel.GetLength()) {
            if (strncmp_P(smodel.GetUnquotedString(), actualPrinterSModel, compareLength) == 0) return 1;
        }
    }

    return 0;
}


TEST_CASE( "MK3SMMU2S", "[MK3SMMU2S]" ) {
    const char * pStrPos = ""MK3SMMU2S"";
    REQUIRE( printer_smodel_check(pStrPos, "MK3SMMU2S") == 1 );
    REQUIRE( printer_smodel_check(pStrPos, "MK3SMMU3") == 1 );
}
