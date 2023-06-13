#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "itemtype.h"

namespace pybind11
{
    namespace detail
    {

        // template <>
        // struct type_caster<molcpp::Vector3D>
        // {
        // public:
        //     PYBIND11_TYPE_CASTER(molcpp::Vector3D, const_name("Vector3D"));

        //     static handle cast(molcpp::Vector3D v, return_value_policy, handle)
        //     {
        //         return py::array(py::buffer_info(
        //             v.data(),
        //             sizeof(double),
        //             py::format_descriptor<double>::format(),
        //             1,
        //             {3},
        //             {3 * sizeof(double)}));
        //     }

        //     bool load(handle src, bool)
        //     {

        //         if (isinstance<py::list>(src))
        //         {
        //             auto l = reinterpret_borrow<py::list>(src);
        //             if (l.size() != 3)
        //                 return false;
        //             value[0] = l[0].cast<double>();
        //             value[1] = l[1].cast<double>();
        //             value[2] = l[2].cast<double>();
        //             return true;
        //         }
        //         else if (isinstance<py::array>(src))
        //         {
        //             auto a = reinterpret_borrow<py::array>(src);
        //             if (a.ndim() != 1 || a.shape(0) != 3)
        //                 return false;
        //             value[0] = *(static_cast<const double*>(a.data(0)));
        //             value[1] = *(static_cast<const double*>(a.data(1)));
        //             value[2] = *(static_cast<const double*>(a.data(2)));
        //             return true;
        //         }
        //         else
        //             return false;
        //     }
        // };

        // template <>
        // struct type_caster<molcpp::AtomProperty>
        // {
        // public:
        //     PYBIND11_TYPE_CASTER(molcpp::AtomProperty, const_name("AromProperty"));

        //     // Conversion part 1 (C++ -> Python): convert a C++ type into a PyObject
        //     static handle cast(molcpp::AtomProperty d, return_value_policy, handle)
        //     {
        //         switch (d.index())
        //         {
        //         case 0:
        //             return py::cast(d.get<int>());
        //         case 1:
        //             return py::cast(d.get<double>());
        //         case 2:
        //             return py::cast(d.get<std::string>());
        //         // case 3:
        //         //     return py::cast(d.get<molcpp::Vector3D>());
        //         default:
        //             throw std::runtime_error("Unknown type");
        //         }
        //     }

        //     // Conversion part 2 (Python->C++): convert a PyObject into a C++ type
        //     bool load(handle src, bool)
        //     {

        //         if (isinstance<py::int_>(src))
        //         {
        //             value = molcpp::AtomProperty(py::cast<int>(src));
        //         }
        //         else if (isinstance<py::float_>(src))
        //         {
        //             value = molcpp::AtomProperty(py::cast<double>(src));
        //         }
        //         else if (isinstance<py::str>(src))
        //         {
        //             value = molcpp::AtomProperty(py::cast<std::string>(src));
        //         }
        //         // else if (isinstance<py::list>(src))
        //         // {
        //         //     value = molcpp::AtomProperty(py::cast<molcpp::Vector3D>(src));
        //         // }

        //         else
        //             return false;
        //         return true;
        //     }
        // };

        // template <>
        // struct type_caster<molcpp::AtomPropertyDict>
        // {

        // public:
        //     PYBIND11_TYPE_CASTER(molcpp::AtomPropertyDict, const_name("Dict"));

        //     // Conversion part 1 (C++ -> Python): convert a C++ type into a PyObject
        //     static handle cast(molcpp::AtomPropertyDict d, return_value_policy, handle)
        //     {

        //         return py::cast(d.get_map());
        //     }

        //     // Conversion part 2 (Python->C++): convert a PyObject into a C++ type
        //     bool load(handle src, bool)
        //     {
        //         if (isinstance<py::dict>(src))
        //         {

        //             value = molcpp::AtomPropertyDict(py::cast<std::map<std::string, molcpp::AtomProperty>>(src));
        //         }
        //         else
        //             return false;
        //         return true;
        //     }
        // };

    } // namespace detail
} // namespace pybind11
