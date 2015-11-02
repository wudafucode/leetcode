class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* pdata[26];
	bool      flag[26];
    TrieNode() {
        memset(pdata,0,sizeof(pdata));
		memset(flag,0,sizeof(flag));
        
    }
	TrieNode* Insert(char temp)
	{
    	if(temp < 'a' || temp > 'z')
		return NULL;
		int index = temp -'a';
		if(pdata[index] == NULL)
		  pdata[index] = new TrieNode();
	
		return pdata[index];
	}
	TrieNode* Find(char temp)
	{
       if(temp < 'a' || temp > 'z')
	    return NULL;
	   return pdata[temp -'a'];
	}
	void SetEnd(char temp)
    {
       if(temp < 'a' || temp > 'z')
	    return ;
        flag[temp-'a'] = true; 
	}
	bool CheckEnd(char temp)
    {
    	if(temp < 'a' || temp > 'z')
	    return false;
        return flag[temp-'a'];
	}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
     TrieNode* pNext = NULL;

     if(word.size() == 0)
	 return ;
	 
     pNext = root;
	 int i;
     for( i=0; i< word.size(); i++)
     {
     	pNext = pNext->Insert(word[i]);
     }
	 pNext->SetEnd(word[i-1]);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* pNext = NULL,*pTemp = NULL;
		pNext = root;
		int i;
        for(i=0; i< word.size(); i++)
        {
         	pNext = pNext->Find(word[i]);
			if(pNext == NULL)
			return false;
		}
		
		return pNext->CheckEnd(word[i-1]);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* pNext = NULL,*pTemp = NULL;
		pNext = root;
		int i;
        for(i=0; i< prefix.size(); i++)
        {
         	pNext = pNext->Find(prefix[i]);
			if(pNext == NULL)
			return false;
		}
		return true;
        
    }

private:
    TrieNode* root;
};