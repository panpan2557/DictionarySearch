//
// Created by PUNPIKORN RATTANAWIROJKUL on 3/13/2016 AD.
//

#ifndef SOFTWAREPT_NODE_H
#define SOFTWAREPT_NODE_H

class Node {
public:
    Node() { mContent = ' '; mMarker = false; }
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    Node* findChild(char c) {
        for ( int i = 0; i < mChildren.size(); i++ )
        {
            Node* tmp = mChildren.at(i);
            if ( tmp->content() == c )
            {
                return tmp;
            }
        }

        return NULL;
    }
    void appendChild(Node* child) { mChildren.push_back(child); }
    std::vector<Node*> children() { return mChildren; }
    int id() { return mId; }
    void setId(int id) { mId = id; }
private:
    char mContent;
    int mId;
    bool mMarker;
    std::vector<Node*> mChildren;
};

#endif //SOFTWAREPT_NODE_H
