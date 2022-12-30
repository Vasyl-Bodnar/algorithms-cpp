#pragma once

namespace hashmap {
template <class T, class Y>
class HashMap {
public:
  void insert();
  Y getVal(T key);
  Y* getAllVals();
private:
  
};
}