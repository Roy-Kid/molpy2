#include "util.h"
#include "linalg.hpp"

namespace molcpp
{
    void bind_linalg(py::module &m)
    {
        auto mm = m.def_submodule("linalg");

        py::class_<Vector3D>(mm, "Vector3D")
            .def(py::init<double, double, double>(), py::arg("x") = 0, py::arg("y") = 0, py::arg("z") = 0)
            .def(py::init<const Vector3D&>())
            .def("__repr__", [](const Vector3D& v) {
                return "<Vector3D: " + std::to_string(v[0]) + ", " + std::to_string(v[1]) + ", " + std::to_string(v[2]) + ">";
            })
            .def("__add__", [](const Vector3D& v1, const Vector3D& v2) {
                return v1 + v2;
            })
            .def("__sub__", [](const Vector3D& v1, const Vector3D& v2) {
                return v1 - v2;
            })
            .def("__mul__", [](const Vector3D& v1, double rhs) {
                return v1 * rhs;
            })
            .def("__truediv__", [](const Vector3D& v1, double rhs) {
                return v1 / rhs;
            })
            .def("__getitem__", [](const Vector3D& v, int i) {
                return v[i];
            })
            .def("__setitem__", [](Vector3D& v, int i, double value) {
                v[i] = value;
            });
        
    }
}