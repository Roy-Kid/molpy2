#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "linalg.hpp"
#include "itemtype.h"

namespace pybind11
{
    namespace detail
    {

        // type caster for Vector3D
        template <>
        struct type_caster<molcpp::Vector3D>
        {
        public:
            PYBIND11_TYPE_CASTER(molcpp::Vector3D, _("Vector3D"));

            // Python -> C++
            bool load(handle src, bool)
            {
                if (!src)
                    return false;
                else if (isinstance<py::tuple>(src) || isinstance<py::list>(src)|| isinstance<array_t<double>>(src))
                {
                    auto buf = array_t<double, array::c_style | array::forcecast>::ensure(src);
                    if (!buf)
                        return false;
                    if (buf.ndim() != 1)
                        return false;
                    if (buf.shape(0) != 3)
                        return false;
                    value = molcpp::Vector3D(buf.at(0), buf.at(1), buf.at(2));
                    return true;
                }
                else
                    return false;
            }

            // C++ -> Python
            static handle cast(molcpp::Vector3D src, return_value_policy /* policy */, handle /* parent */)
            {
                return py::array(py::buffer_info(
                    src.data(),                              /* data as contiguous array  */
                    sizeof(double),                          /* size of one scalar        */
                    py::format_descriptor<double>::format(), /* data type                 */
                    1,                                       /* number of dimensions      */
                    {3},                                     /* shape of the matrix       */
                    {sizeof(double)}                         /* strides for each axis     */

                    ));
            }
        };

        template <>
        struct type_caster<molcpp::AtomProperty>
        {
        public:
            PYBIND11_TYPE_CASTER(molcpp::AtomProperty, _("AtomProperty"));

            // Python -> C++
            bool load(handle src, bool)
            {
                if (!src)
                    return false;
                else if (isinstance<py::int_>(src))
                    value = molcpp::AtomProperty(src.cast<int>());
                else if (isinstance<py::float_>(src))
                    value = molcpp::AtomProperty(src.cast<double>());
                else if (isinstance<py::str>(src))
                    value = molcpp::AtomProperty(src.cast<std::string>());
                else if (isinstance<py::list>(src) || isinstance<py::tuple>(src))
                    value = molcpp::AtomProperty(src.cast<molcpp::Vector3D>());
                else if (isinstance<py::none>(src))
                    value = molcpp::AtomProperty();
                else
                    return false;
            }

            // C++ -> Python
            static handle cast(molcpp::AtomProperty src, return_value_policy /* policy */, handle /* parent */)
            {
                if (src.is<int>())
                    return py::int_(src.get<int>());
                else if (src.is<double>())
                    return py::float_(src.get<double>());
                else if (src.is<std::string>())
                    return py::str(src.get<std::string>());
                else if (src.is<molcpp::Vector3D>())
                    return py::cast(src.get<molcpp::Vector3D>());
                else
                    return py::none();
            }
        };

    } // namespace detail
} // namespace pybind11