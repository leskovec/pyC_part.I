
import vecint as vecint
import numpy as np

# create my class - use the default constructor
# .def(py::init<>())
vec = vecint.PyVectorInt()

# add elements to vec using push_back
for i in range(10):
  vec.push_back(np.random.randint(0,100))

print("== printing the contents ==")
# string representation of the vector:
# // print(vec)
# .def("__repr__", &VectorInt::to_string)
print("__repr__:",vec.__repr__())
# same as
print("vec:     ",vec)
# also same as:
# // str(vec)
# .def("__str__", &VectorInt::to_string)
vecstr = str(vec)
print("str(vec):",vecstr)

print("== properties ==")
# Properties
# .def_property_readonly("length", &VectorInt::size)
print("vec.length:   ",vec.length)
# // Length of vector -> len(vec)
# .def("__len__", &VectorInt::size)
print("vec.__len__():",vec.__len__())
# size of vec
print("vec.size():    ",vec.size())
# check if vec is empty
print("vec.is_empty():",vec.is_empty())

print("== adding and removing elements ==")
# .def("clear", &VectorInt::clear,
#   "Clears the vector")
vec.clear()

# .def("push_back", static_cast<void 
# (VectorInt::*)(const int)>(&VectorInt::push_back),
vec.push_back(1)
vec.push_back(2)

# .def("push_back", static_cast<void 
# (VectorInt::*)(const int, const size_t)>(&VectorInt::push_back),
vec.push_back(3, 3)

#print vector
print("vec:",vec)

print("== access type ==")
# handy if we want to set the vector and then make it read only
# by default its readwrite
print("vec access [RW]:",vec.access)
# set access to readonly
vec.access = vecint.Access.READONLY
print("vec access [RO]:",vec.access)

print("== lambda expressions ==")
vec.clear()

# make a vector of [0,1,2,3,4,5,6,7,8,9]
for i in range(10):
  vec.push_back(i)
print("vec:",vec)

# .def("doForAllElements",
# apply a function to all elements of the vector and place it somewhere
new_vec = []
vec.doForAllElements(lambda x : new_vec.append(x * x) )
print("new_vec:",new_vec)
print("vec:    ",vec)



print("== iterator ==")

# the cool python iterator:
# // Iterator -> for elem in vec: ...
# .def("__iter__", [](VectorInt& vec) {
#     return py::make_iterator(vec.begin(), vec.end());
#   }, py::keep_alive<0,1>())
print("vec:")
for i in vec:
  print(i)
print("xx")

# get i-th element:
print("vec.get(i):")
for i in range(vec.size()):
  print(vec.get(i))
print("xx")


# use a fixed size constructor
vec2 = vecint.PyVectorInt(10)
print("vec2 size:",vec2.size())
# set the vector values -  well for that we didnt build a method in our class...
  
