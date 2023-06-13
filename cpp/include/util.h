#pragma once
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace molcpp
{
    void bind_linalg(py::module &);
    void bind_atom(py::module &);
}