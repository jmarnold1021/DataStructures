
#ifndef TERNARYTRIE_HPP
#define TERNARYTRIE_HPP



using namespace std;

class Trie {

    private:
        class TrieNode {
            public:
                char data;
                bool prefix;
                
                TrieNode* left = nullptr;
                TrieNode* right = nullptr;
                TrieNode* center = nullptr;
                
                TrieNode(char data, bool prefix){
                    this -> data = data;
                    this -> prefix = prefix;
                }    
        };

        void destroyTrie( TrieNode* node ) {

            if(node != nullptr) {
                destroyTrie(node -> left);
                destroyTrie(node -> center);
                destroyTrie(node -> right);
                delete node;
            }
        }

    public:
        TrieNode* root;

        Trie() {
            this -> root = nullptr;
        }

        Trie( string word ) {
            
            bool prefix = false;
            
            if( word.size() == 1 ){
                prefix = true;
            }
            
            this -> root = new TrieNode(word[0], prefix);

            TrieNode* itr = this -> root;

            for( int i = 1; i < word.size(); ++i ){
                
                if( i != word.size() - 1 ){
                    itr -> center = new TrieNode(word[i], false); 
                } else {
                    itr -> center = new TrieNode(word[i], true);
                }
                
                itr = itr -> center;
            } 
        }

        ~Trie() {
            destroyTrie(this -> root);
        }

        void add( string word ){
            
            int i = 0;
            bool PREFIX = false;
            bool STORE = false;
            
            if( this -> root == nullptr ) {
                
                if( word.size() == 1 ){
                    this -> root = new TrieNode(word[0], true);
                    return;
                }
                
                this -> root = new TrieNode(word[0], PREFIX );
                STORE = true;
                ++i;
            }
            
            TrieNode* itr = this -> root;

            while( i < word.size() ) {

                if( i == word.size() - 1 ){
                    PREFIX = true;
                }

                while( true ) {
                    
                    if( STORE ) {

                        itr -> center = new TrieNode(word[i], PREFIX);

                        STORE = true;
                        itr = itr -> center;
                        ++i;
                        break;  
                    }

                    if( word[i] == itr -> data ){

                        if( itr -> center == nullptr ) {
                            STORE = true;
                        } else {
                            
                            if( i == word.size() - 1 ) {
                                itr -> prefix = true; // cause they are not insterting in lexigraphical
                                ++i;                  // order so may have to insert prefixes of words already there.
                                break;
                            }
                            
                            itr = itr -> center;
                        }

                        ++i;
                        break;
                    } else if( word[i] < itr -> data ) {

                        if( itr -> left == nullptr ) {

                            itr -> left = new TrieNode(word[i], PREFIX);

                            STORE = true;
                            itr = itr -> left;
                            ++i;
                            break;   
                        }

                        itr = itr -> left;
                        continue;
                    } else if( word[i] > itr -> data ) {

                        if( itr -> right == nullptr ) {
                            
                            itr -> right = new TrieNode(word[i], PREFIX);

                            STORE = true;
                            itr = itr -> right;
                            ++i;
                            break;    
                        }

                        itr = itr -> right;
                        continue;
                    }
                }
            }
        }
 
        bool contains( string word ) {
            
            TrieNode* itr = this -> root;

            for( int i = 0; i < word.size(); ++i ) {
                while( true ) {
                    if( word[i] == itr -> data ) {
                        if( i < word.size() - 1 ) {
                            if( itr -> center != nullptr ){
                                itr = itr -> center;
                                break;
                            }
                            return false;
                        }
                        break;
                    } else if( word[i] < itr -> data ) {
                        if( itr -> left != nullptr ){
                            itr = itr -> left;
                            continue;
                        }
                        return false;
                    } else if(  word[i] > itr -> data ){
                        if( itr -> right != nullptr ){
                            itr = itr -> right;
                            continue;
                        }
                        return false;
                    }
                }
            }

            if( itr && itr -> prefix == true ){
                return true;
            }

            return false;
        }

        bool starts_with( string prefix ) {
        
            TrieNode* itr = this -> root;

            for( int i = 0; i < prefix.size(); ++i ) {
                while( true ) {
                    
                    if( prefix[i] == itr -> data ) {
                        
                        if( i < prefix.size() - 1 ) {
                            
                            if( itr -> center != nullptr ) {
                                itr = itr -> center;
                                break;
                            }
                            return false;
                        }

                        return true; // just added this to search...in search if were on a == path we
                                     // go until the end of the itr and check the prefix otherwise here
                                     // here just the end of the word needs to be in == territory
                    } else if( prefix[i] < itr -> data ) {
                        
                        if( itr -> left != nullptr ){
                            itr = itr -> left;
                            continue;
                        }
                        return false;
                    } else if( prefix[i] > itr -> data ){
                        
                        if( itr -> right != nullptr ){
                            itr = itr -> right;
                            continue;
                        }
                        return false;
                    }
                }
            }
            return false;
        }
};


#endif

    