#include "basebuilder.h"
#include <string>
#include <algorithm>

using namespace std;



basebuilder::basebuilder() {
    
    defaults.autoQuoteTableNames = false;
    defaults.autoQuoteFieldNames = false;
    defaults.autoQuoteAliasNames = true;
    defaults.useAsForTableAliasNames = false;
    defaults.nameQuoteCharacter = '`';
    defaults.tableAliasQuoteCharacter = '`';
    defaults.fieldAliasQuoteCharacter = '"';
    defaults.parameterCharacter = '?';
    defaults.numberedParameters = false;
    defaults.numberedParametersPrefix = '$';
    defaults.numberedParametersStartAt = 1;
    defaults.replaceSingleQuotes = false;
    defaults.singleQuoteReplacement = "\'\'";
    defaults.separator = ' ';
    defaults.stringFormatter = "";
    defaults.rawNesting = false;
    
}

std::string basebuilder::escapeValue(std::string v){
    if (!defaults.replaceSingleQuotes)
        return v;
    else
        return basebuilder::ReplaceAll(v,"\'", defaults.singleQuoteReplacement);
}

std::string basebuilder::formatTableName(std::string item){
    
    if(defaults.autoQuoteTableNames){
        return defaults.nameQuoteCharacter + item + defaults.nameQuoteCharacter;
    }
    
    return item;
}

std::string basebuilder::formatFieldAlias(std::string item){
    if(defaults.autoQuoteAliasNames){
        return defaults.fieldAliasQuoteCharacter + item + defaults.fieldAliasQuoteCharacter;
    }
    
    return item;
}

std::string basebuilder::formatTableAlias(std::string item){
    if(defaults.autoQuoteAliasNames){
        item = defaults.tableAliasQuoteCharacter + item + defaults.tableAliasQuoteCharacter;
    }
    
    if(defaults.useAsForTableAliasNames)
        return "AS " + item;
    else
        return item;
}