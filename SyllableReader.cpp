//
// Created by PUNPIKORN RATTANAWIROJKUL on 2/18/2016 AD.
//
#include <stdexcept>
#include <iconv.h>
#include "SyllableReader.h"

using namespace std;

namespace SyllableReader
{

    bool SyllableReader::readFile(char *filepath) {
        trie = new Trie();

        strcpy(path, filepath);
        input.open(path, ios::in|ios::out);
        input.seekg(256); //skip the header

        SYLLABLE_DATA_RECORD* record = (SYLLABLE_DATA_RECORD*) malloc(sizeof(SYLLABLE_DATA_RECORD));


        //until the end of file or the output exceeds
        while(!input.eof()) {
            //read the record
            input.read(reinterpret_cast<char*>(record), sizeof(SYLLABLE_DATA_RECORD) - (sizeof(char)*1024));

            //read szText
            sizeOfRecord = record->ui10Len + 1;
            temp = (char*)malloc(sizeOfRecord);
            input.read(temp, sizeOfRecord);

            //translate the input text
            iconv_t charset = iconv_open("UTF8", "CP874");
            size_t inSize = MAX_SYLLABLE_TEXTSIZE;
            size_t outSize = MAX_SYLLABLE_TEXTSIZE;
            char *input = &temp[0];
            char *output = &record->szText[0];
            iconv(charset, &input, &inSize, &output, &outSize);

            //add data to trie
            printf("ID: %d, Text: %s\n", record->ui32SylID, record->szText);
            trie->addWord(record->szText, record->ui32SylID);
        }

        input.close();
        return true;
    }

    Trie* SyllableReader::getTrie() {
        return trie;
    }
}
