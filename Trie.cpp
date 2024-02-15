struct Node {
    Node * links[26] ;
    bool flag = false ;
    
    bool containsKey(char ch){
        return links[ch-'a'] != NULL ;
    }
    void putKey(char ch, Node* node){
        links[ch-'a'] = node ;
    }
    Node* getNext(char ch){
        return links[ch-'a'] ;
    }
    void setFlag(bool f){
        flag = f ;
    }
    bool isEnd(){
        return flag ;
    }
};

class Trie {
public:
    Node * root ;
    Trie() {
        root = new Node() ;
    }
    // O(N)
    void insert(string word) {
        Node * node = root ;
        for(int i = 0 ;  i< word.length(); i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }
            node = node->getNext(word[i]) ;
        }
        node->setFlag(true) ;
    }
    // O(N)
    bool search(string word) {
        Node *node = root ;
         for(int i = 0 ;  i< word.length(); i++){
            if(!node->containsKey(word[i])){
                return false ;
            }
            node = node->getNext(word[i]) ;
        }
        return node->isEnd();
    }
    // O(N)
    bool startsWith(string word) {
        Node *node = root ;
         for(int i = 0 ;  i< word.length(); i++){
            if(!node->containsKey(word[i])){
                return false ;
            }
            node = node->getNext(word[i]) ;
        }
        return true ;
    }
};
