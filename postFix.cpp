#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <string>

using namespace std;


int main() {
  string d,data;

  stack<int> stackMemory; 
  queue<int> queueMemory;
  priority_queue<int, vector<int>, greater<int> > priorityMemory;
  
  int number;
  int stackX,stackY,stackResult;
  int queueX,queueY,queueResult;
  int priorityX,priorityY,priorityResult;
 
  getline(cin, data);
  while (data != "#") {
    stringstream ss;
    ss << data;
    while (ss >> d){
      if(d != "+" && d != "-" && d != "*"){
        number = stoi(d);
        stackMemory.push(number);
        queueMemory.push(number);
        priorityMemory.push(number);
      }else{

        stackY = stackMemory.top(); stackMemory.pop();
        stackX = stackMemory.top(); stackMemory.pop();
        
        queueY = queueMemory.front(); queueMemory.pop();
        queueX = queueMemory.front(); queueMemory.pop();

        priorityY = priorityMemory.top(); priorityMemory.pop();
        priorityX = priorityMemory.top(); priorityMemory.pop();

        if(d=="+"){
          stackResult = stackX + stackY;
          queueResult = queueX + queueY;
          priorityResult = priorityX + priorityY;
        }else if(d=="-"){
          stackResult = stackX - stackY;
          queueResult = queueX - queueY;
          priorityResult = priorityX - priorityY;
        }else if(d=="*"){
          stackResult = stackX * stackY;
          queueResult = queueX * queueY;
          priorityResult = priorityX * priorityY;
        }
        stackMemory.push(stackResult);
        queueMemory.push(queueResult);
        priorityMemory.push(priorityResult);
      }
    }
    cout <<stackResult<< " " <<queueResult<<" "<<priorityResult<<endl;
    //Cleaning the memory for the next input
    while(stackMemory.size() > 0){
      stackMemory.pop();
      queueMemory.pop();
      priorityMemory.pop();
    }
    
    getline(cin, data); 
  }
}