#include<queue>
using namespace std;
class WordDictionary {
public:
	

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
        if(temp == '.')
        {
           for(int i = 0; i< 26; i++)
           {
              if(flag[i] == true)
              {
              	return true;
			  }
		   }
           return false;
		}
    	if(temp < 'a' || temp > 'z')
	    return false;
        return flag[temp-'a'];
	}
	void Search(char word, queue<TrieNode*>& temp)
	{
       if(word == '.')
       {
       	  for(int i = 0; i<26; i++)
       	  {
          	 if(pdata[i] != NULL)
			   temp.push(pdata[i]);
		  }
		  return;
	   }
	   temp.push(pdata[word - 'a']);
	   
	}
};
		TrieNode root;
    // Adds a word into the data structure.
    void addWord(string word) {
     TrieNode* pNext = NULL;

     if(word.size() == 0)
	 return ;
	 
     pNext = &root;
	 int i;
     for( i=0; i< word.size(); i++)
     {
     	pNext = pNext->Insert(word[i]);
     }
	 pNext->SetEnd(word[i-1]);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
       IterWord temp;
	   temp.Init(&root);
	   if(word.size() == 0)
	   	return false;
	   int i;
       for(i=0; i< word.size(); i++)
       {
           temp.Search(word[i]);

	   }
       return temp.CheckEnd(word[i-1]);
    }
	class IterWord
	{
	       queue<TrieNode*>   buf[2]; 
		   int used;
		   int free;
     public:
	 	  void Init(TrieNode* root)
	 	   {
               used = 0;
			   free = 1;
			   buf[used].push(root);
			  
		   }
		  void Search(char temp)
		   {
		      TrieNode* pNode;
              while(!buf[used].empty())
              {
                 pNode = buf[used].front();
				 if(pNode != NULL)
				 pNode->Search(temp,buf[free]);
				 buf[used].pop();
			  }
			  swap(used,free);
		   }
		   bool CheckEnd(char temp)
		   {
		      while(!buf[used].empty())
              {
                 TrieNode* pNode;
                 pNode = buf[used].front();
				 if(pNode != NULL)
				 {
                    if(pNode->CheckEnd(temp) == true)
					return true;
				 }
				 buf[used].pop();
			  }
              return false;
		   }

	};
};

