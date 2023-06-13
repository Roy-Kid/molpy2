#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

namespace py = pybind11;

namespace molcpp
{
    // declearation
    void bind_atom(py::module &m);
    void bind_linalg(py::module &m);
    // void bind_itemtype(py::module &m);
}