

#include "vector_int.h"

#include <sstream>

VectorInt::VectorInt() :
  _vec(),
  _access(Access::READWRITE) { }

VectorInt::VectorInt(const size_t n) :
  _vec(n),
  _access(Access::READWRITE) { }

VectorInt::iterator VectorInt::begin() {
  return _vec.begin();
}

VectorInt::iterator VectorInt::end() {
  return _vec.end();
}

void VectorInt::push_back(const int val) {
  _vec.push_back(val);
}

void VectorInt::push_back(const int val, const size_t n) {
  for ( size_t i = 0; i < n; ++i ) {
    _vec.push_back(val);
  }
}

int VectorInt::get(const size_t idx) const {
  return _vec[idx];
}

size_t VectorInt::size() const {
  return _vec.size();
}

bool VectorInt::is_empty() const {
  return _vec.empty();
}

void VectorInt::clear() {
  _vec.clear();
}

std::string VectorInt::to_string() const {
  std::stringstream ss;
  ss << "[";
  for ( size_t i = 0; i < size() - 1; ++i ) {
    ss << get(i) << ", ";
  }
  ss << get(size() - 1) << "]";
  return ss.str();
}


