vector<string> split(string s, char delimiter){
  s.push_back(delimiter);
  string temp = "";
  vector<string> res;
  for(int x = 0; x < s.length(); x++){
    if(s[x] == delimiter){
      if(temp.length() == 0)
        continue;
      res.push_back(temp);
      temp = "";
    }
    else{
      temp.push_back(s[x]);
    }
  }
  return res;
}
