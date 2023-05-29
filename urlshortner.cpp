#include <bits/stdc++.h>
using namespace std;

string convIDtoURL(int n) {
  
    // Char array having all chars (A to Z), (a to z) and (0 to 9)
    char alphaMap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"
        "ghijklmnopqrstuvwxyz0123456789";

  string url;

  while (n > 0) { 
    // converting urlID to url
    url.push_back(alphaMap[n%62]);
    n /= 62;
  }

  reverse(url.begin(), url.end());

  return url;
}

int convURLtoID(string shortURL) {
  int urlID = 0; 

  for (int i=0; i < shortURL.length(); i++) {
     // if char is in between A and Z
     if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
        urlID = urlID*62 + shortURL[i] - 'A';

     // if char is in between a and z (till 26 we have A to Z)
     if ('a' <= shortURL[i] && shortURL[i] <= 'z')
        urlID = urlID*62 + shortURL[i] - 'a' + 26;
    
     // if char is in between 0 and 9 (till 52 we have a to b)
     if ('0' <= shortURL[i] && shortURL[i] <= '9')
        urlID = urlID*62 + shortURL[i] - '0' + 52;
  }

  return urlID;
}

int main() {

    int n;
    cout<<"\nEnter the integer ID: ";
    cin>>n;
    cout<<endl;
    string url = convIDtoURL(n);
    cout << "Generated short url is www.urlShortner.com/" << url << endl;
    cout << "ID from URL is " << convURLtoID(url);
  
    return 0;
}