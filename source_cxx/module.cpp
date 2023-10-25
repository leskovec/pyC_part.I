


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include <sstream>

#include "vector_int.h"

namespace py = pybind11;

PYBIND11_MODULE(vecint, m) {
  m.doc() = "A vector storing integers";
  py::class_<VectorInt>(m, "PyVectorInt", py::dynamic_attr())
    // Default constructor
    .def(py::init<>())
    // Initializes a vector of size n
    .def(py::init<const size_t>())
    // print(vec)
    .def("__repr__", &VectorInt::to_string)
    // str(vec)
    .def("__str__", &VectorInt::to_string)
    // Access operator -> vec[0]
    .def("__getitem__", &VectorInt::get)
    // Length of vector -> len(vec)
    .def("__len__", &VectorInt::size)
    // Iterator -> for elem in vec: ...
    .def("__iter__", [](VectorInt& vec) {
        return py::make_iterator(vec.begin(), vec.end());
      }, py::keep_alive<0,1>())
    // Binds attribute access to member _access of VectorInt and allows
    // to read and write the attribute
    .def_readwrite("access", &VectorInt::_access)
    // Binds public functions of C++ class to Python class
    .def("push_back", static_cast<void (VectorInt::*)(const int)>(&VectorInt::push_back),
      "Inserts an element at the end of the vector", py::arg("elem"))
    .def("push_back", static_cast<void (VectorInt::*)(const int, const size_t)>(&VectorInt::push_back),
      "Inserts an element n times into the vector the vector",
      py::arg("elem"), py::arg("n"))
    .def("get", &VectorInt::get,
      "Returns the number at position i",
      py::arg("i"))
    .def_property_readonly("length", &VectorInt::size)
    .def("size", &VectorInt::size,
      "Returns the number of elements in the vector")
    .def("is_empty", &VectorInt::is_empty,
      "Returns true, if the vector does not contain an element")
    .def("clear", &VectorInt::clear,
      "Clears the vector")
    // Function takes a lambda function and calls the function
    // for each element
    .def("doForAllElements",
      [](VectorInt& vec,
         std::function<void(int)>& f) {
           for ( int elem : vec ) {
             f(elem);
           }
         });

  // Enum Type
  py::enum_<Access>(m, "Access")
    .value("READONLY", Access::READONLY)
    .value("READWRITE", Access::READWRITE);
}


