#pragma once
#include <pybind11/pybind11.h>

#include <iostream>

namespace py = pybind11;

namespace molcpp
{
    // declearation
    void bind_atom(py::module &m);
    void bind_linalg(py::module &m);
}