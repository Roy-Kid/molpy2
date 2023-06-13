#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "linalg.hpp"

namespace pybind11
{
    namespace detail
    {

        // type caster for Vector3D
        template <>
        struct type_caster<Vector3D>
        {
        public:
            PYBIND11_TYPE_CASTER(Vector3D, _("Vector3D"));

            // Python -> C++
            bool load(handle src, bool)
            {
                if (!src)
                    return false;
                else if (isinstance<array_t<double>>(src))
                    auto buf = array_t<double, array::c_style | array::forcecast>::ensure(src);
                if (!buf)
                    return false;
                if (buf.ndim() != 1)
                    return false;
                if (buf.shape(0) != 3)
                    return false;
                value = Vector3D(buf.data(0), buf.data(1), buf.data(2));
                return true;
                else if (isinstance<tuple>(src) || isinstance<list>(src)) auto buf = array_t<double, array::c_style | array::forcecast>::ensure(src);
                if (!buf)
                    return false;
                if (buf.ndim() != 1)
                    return false;
                if (buf.shape(0) != 3)
                    return false;
                value = Vector3D(buf.data(0), buf.data(1), buf.data(2));
                return true;
                else return false;
            }

            // C++ -> Python
            static handle cast(Vector3D src, return_value_policy /* policy */, handle /* parent */)
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

    } // namespace detail
} // namespace pybind11
