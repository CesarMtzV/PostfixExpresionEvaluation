#include <iostream>
#include <sstream>

using namespace std;


int main() {
  string d,data;
 
  getline(cin, data);
  while (data != "#") {
    stringstream ss;
    ss << data;
    while (ss >> d){
      cout << d << endl;
    }
    cout << "Termine Linea" << endl;
    getline(cin, data); 
  }
}