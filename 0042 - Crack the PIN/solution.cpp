#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>

std::string crack(std::string hash) {
    std::stringstream a;
    for (int i = 0; i < 100000; ++i){
      a << std::setfill('0') << std::setw(5) << i;
      
      unsigned char digest[MD5_DIGEST_LENGTH];
      std::string temp = a.str();
      
      MD5((unsigned char*)temp.c_str(), temp.length(), (unsigned char*)&digest);    
   
      char mdString[33];
 
      for(int i = 0; i < 16; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
      
      std::string md(mdString);
      
      if (md == hash) break;
      
      a.str(std::string());
      a.clear();
    }
  
  return a.str();
}