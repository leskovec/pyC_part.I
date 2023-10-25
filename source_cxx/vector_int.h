#pragma once

#include <vector>
#include <string>

enum Access {
  READONLY,
  READWRITE
};

class VectorInt {

  using iterator = typename std::vector<int>::iterator;

 public:
  VectorInt();
  VectorInt(const size_t n);

  iterator begin();
  iterator end();

  void push_back(const int val);
  void push_back(const int val, const size_t n);
  int get(const size_t idx) const;
  size_t size() const;
  bool is_empty() const;
  void clear();
  std::string to_string() const;

 private:
  std::vector<int> _vec;

 public:
  Access _access;
};


