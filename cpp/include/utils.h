#pragma once
#include <pybind11/pybind11.h>
#include <xtensor-python/pyarray.hpp>

namespace py = pybind11;

namespace molcpp
{
    // declearation
    void bind_atom(py::module &m);

}