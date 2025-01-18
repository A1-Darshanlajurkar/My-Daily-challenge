
/*
      Purpose: Finds and counts occurrences of anagrams of a pattern (pat) in a text (txt) using the Sliding Window Technique and frequency counting.

      Approach:
              Maintain a frequency counter (vector of size 26) for characters in pat.
              Use a sliding window of size k (length of pat) to traverse txt.
              Adjust frequency counts dynamically as the window slides.
              If all frequency counts are zero, an anagram is found.
              Time Complexity: O(N), where N is the length of txt.

      Example:
              Input: txt = "forxxorfxdofr", pat = "for"
              Output: The count of the anagram will be: 3 (Anagrams found at indices 0-2, 4-6, and 9-11).
              Optimizations:
              Use pass-by-reference (&) in allcountzero() to avoid unnecessary copies.
              Extend to handle uppercase characters and general ASCII characters.
              
*/







#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


bool allcountzero(vector<int> counter){
	for(int &i : counter){
		if(i != 0){
			return false;
		}
	}
	return true;
}

void count_occurence_anagram(string txt,string pat){
	int count =0;
	vector<int> counter(26,0);
	int n = txt.size();
	for(int i = 0;i<pat.size(); i++){
		char ch = pat[i]-'a';
		counter[ch]++;
	}
	int k = pat.size();
	int i =0;
	int j =0;
	
	while(j<n){
		counter[txt[j] - 'a']--;
		if(j-i+1 == k){
			if(allcountzero(counter)){
				count++;
			}
			counter[txt[i] - 'a']++;
			i++;
		}
		j++;
	}
	cout<<"The count of the annagram will be :- "<<count<<endl;
}


int main(){
	string txt =  "forxxorfxdofr";
	string pat = "for";
	count_occurence_anagram(txt,pat);
}