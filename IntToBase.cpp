string itob(int n, int base){
  string key = "0123456789ABCDEF";
  string bin = "";
  while(n != 0){
    bin = key[n%base] + bin;
    n /= base;
  }
  return bin;
}
