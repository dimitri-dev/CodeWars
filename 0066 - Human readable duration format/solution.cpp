#include <string>

std::string format_duration(int seconds) {
  if (seconds == 0) return "now";
  
  int yrs  = seconds / 31536000;
  int days = (seconds % 31536000) / 86400;
  int hrs  = ((seconds % 31536000) % 86400) / 3600;
  int mins = (((seconds % 31536000) % 86400) % 3600) / 60;
  int secs = (((seconds % 31536000) % 86400) % 3600) % 60;
  
  std::string res = "";
  
  if (yrs != 0) {
    res += (yrs == 1) ? "1 year" : (std::string() + std::to_string(yrs) + " years");
  }
  
  if (days != 0) {
    if (res.empty() == false){ 
      if (hrs != 0 || mins != 0 || secs != 0) res += ", ";
      else res += " and ";
    }
    res += (days == 1) ? "1 day" : (std::string() + std::to_string(days) + " days");
  }
  
  if (hrs != 0) {
    if (res.empty() == false){ 
      if (mins != 0 || secs != 0) res += ", ";
      else res += " and ";
    }
    res += (hrs == 1) ? "1 hour" : (std::string() + std::to_string(hrs) + " hours");
  }
  
  if (mins != 0) {
    if (res.empty() == false){ 
      if (secs != 0) res += ", ";
      else res += " and ";
    }
    res += (mins == 1) ? "1 minute" : (std::string() + std::to_string(mins) + " minutes");
  }
  
  if (secs != 0) {
    if (res.empty() == false) res += " and ";
    res += (secs == 1) ? "1 second" : (std::string() + std::to_string(secs) + " seconds");
  }
  
  return res;
}