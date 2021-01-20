#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

std::string encode_rail_fence_cipher(std::string msg, int key) {
      if (msg.empty()) return "";

      int nrow = key, ncol = msg.length();
	    char rail_matrix[nrow][ncol]; 
	  
	    for (int i=0; i < nrow; i++)
	        for (int j = 0; j < ncol; j++)
	            rail_matrix[i][j] = '|'; 
  
	    bool downward = false; 
	    int r = 0, c = 0; 
	    std::string ciphertext; 
	  
	    for (int i=0; i < msg.length(); i++) {
	        if (r == 0 || r == key-1) downward = !downward; 
	        rail_matrix[r][c++] = msg[i]; 
	        downward ? ++r : --r; 
	    } 
	    
	    for (int i=0; i < key; i++)
	        for (int j=0; j < msg.length(); j++)
	            if (rail_matrix[i][j] != '|') 
	                ciphertext.push_back(rail_matrix[i][j]);

    return ciphertext;
}

std::string decode_rail_fence_cipher(std::string msg, int key) {
      int nrow = key, ncol = msg.length();
	    char rail_matrix[nrow][ncol]; 
	    std::string plaintext;
	  
	    for (int i=0; i < nrow; i++)
	        for (int j = 0; j < ncol; j++)
	            rail_matrix[i][j] ='^'; 

	    bool downward; 
	    int r = 0, c= 0; 
	  
	    for (int i=0; i < msg.length(); i++) {
	        if (r == 0) downward = true; 
	        if (r == key-1) downward = false; 
	        rail_matrix[r][c++] = '~'; 
	  
	        downward? ++r : --r; 
	    } 
	  
	    int indx = 0; 
	    for (int i = 0; i < key; ++i)
	        for (int j = 0; j < msg.length(); ++j)
	            if (rail_matrix[i][j] == '~' && indx < msg.length()) 
	     			    rail_matrix[i][j] = msg[indx++]; 
         
	  
	    r = 0, c = 0; 
	    for (int i = 0; i < msg.length(); ++i) 
	    { 
	        if (r == 0) downward = true; 
	        if (r == key-1) downward = false; 
	  

	        if (rail_matrix[r][c] != '~') plaintext.push_back(rail_matrix[r][c++]);
	        downward?r++: r--; 
	    }  
  
      return plaintext;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << encode_rail_fence_cipher("WEAREDISCOVEREDFLEEATONCE", 3) << " " << "WECRLTEERDSOEEFEAOCAIVDEN" << endl;
    cout << encode_rail_fence_cipher("Hello, World!", 3) << " " << "Hoo!el,Wrdl l" << endl;
    cout << encode_rail_fence_cipher("Hello, World!", 4) << " " << "H !e,Wdloollr" << endl;
    cout << encode_rail_fence_cipher("", 3) << " " << "" << endl;

    cout << "Encryption works" << endl;
    cout << decode_rail_fence_cipher("H !e,Wdloollr", 4) << " " << "Hello, World!" << endl;
    cout << decode_rail_fence_cipher("WECRLTEERDSOEEFEAOCAIVDEN", 3) << " " << "WEAREDISCOVEREDFLEEATONCE" << endl;
    cout << decode_rail_fence_cipher("", 3) << " " << "" << endl;
    return 0;
}