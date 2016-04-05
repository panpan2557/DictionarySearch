//
// Created by PUNPIKORN RATTANAWIROJKUL on 3/13/2016 AD.
//

#ifndef SOFTWAREPT_TRIE_H
#define SOFTWAREPT_TRIE_H

#include <string>
#include <vector>
#include "Node.h"

class Trie {
public:
    Trie() {
        root = new Node();
    };
    ~Trie() { };
    void addWord(std::string s, int id) {
        Node* current = root;

        if ( s.length() == 0 )
        {
            current->setWordMarker(); // an empty word
            return;
        }

        for ( int i = 0; i < s.length(); i++ )
        {
            Node* child = current->findChild(s[i]);
            if ( child != NULL )
            {
                current = child;
            }
            else
            {
                Node* tmp = new Node();
                tmp->setContent(s[i]);
                current->appendChild(tmp);
                current = tmp;
            }
            if ( i == s.length() - 1 ) {
                current->setWordMarker();
                current->setId(id);
            }
        }
    };
    int searchWord(std::string s) {
        Node* current = root;

        while ( current != NULL )
        {
            for ( int i = 0; i < s.length(); i++ )
            {
                Node* tmp = current->findChild(s[i]);
                if ( tmp == NULL )
                    return -1;
                current = tmp;
            }

            if ( current->wordMarker() ) {
                printf("found %d\n", current->id());
                return current->id();
            }
            else
                return -1;
        }
        return -1;
    };
    //void deleteWord(std::string s);
private:
    Node* root;
};

#endif //SOFTWAREPT_TRIE_H
