#ifndef GAMEENTRY_H
#define GAMEENTRY_H

#include <iostream>
#include <string>

using namespace std;

class GameEntry{
private:
  string name;
  int score;
public:
  GameEntry(string name,int score) {
    this->name=name;
    this->score=score;    
  };

  bool operator>(const GameEntry& other) const {
    return this->score > other.score;
  }

  friend ostream& operator<<(ostream& out, const GameEntry& entry) {
    out << "[" << entry.name << "]" << entry.score;
    return out;
  }
};

#endif