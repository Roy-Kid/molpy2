#pragma once
#include <pybind11/pybind11.h>
#include "itemtype.h"

namespace py = pybind11;

namespace pybind11
{
    namespace detail
    {

        template <>
        struct type_caster<molcpp::AtomProperty>
        {
        public:
            PYBIND11_TYPE_CASTER(molcpp::AtomProperty, const_name("Data"));

            // Conversion part 1 (C++ -> Python): convert a C++ type into a PyObject
            static handle cast(molcpp::AtomProperty &d, return_value_policy, handle)
            {

                switch (d.index())
                {
                case 0:
                    return py::cast(d.get<int>());
                case 1:
                    return py::cast(d.get<double>());
                case 2:
                    return py::cast(d.get<std::string>());
                case 3:
                    return py::array(py::buffer_info(
                        d.get<molcpp::Vector3D>().data(),
                        sizeof(double),
                        py::format_descriptor<double>::format(),
                        1,
                        {3},
                        {3 * sizeof(double)}));
                default:
                    throw std::runtime_error("Unknown type");
                }
            }

            // Conversion part 2 (Python->C++): convert a PyObject into a C++ type
            bool load(handle src, bool)
            {

                if (isinstance<py::int_>(src))
                {
                    std::cout << "int" << std::endl;
                    value = molcpp::AtomProperty(py::cast<int>(src));
                }
                else if (isinstance<py::float_>(src))
                {
                    std::cout << "float" << std::endl;
                    value = molcpp::AtomProperty(py::cast<double>(src));
                }
                else if (isinstance<py::str>(src))
                {
                    std::cout << "str" << std::endl;
                    value = molcpp::AtomProperty(py::cast<std::string>(src));
                }
                else
                    return false;
                return true;
            }
        };

        template <>
        struct type_caster<molcpp::AtomPropertyDict>
        {

        public:
            PYBIND11_TYPE_CASTER(molcpp::AtomPropertyDict, const_name("Dict"));

            // Conversion part 1 (C++ -> Python): convert a C++ type into a PyObject
            static handle cast(const molcpp::AtomPropertyDict &d, return_value_policy, handle)
            {

                return py::cast(d.get_map()).inc_ref();
            }

            // Conversion part 2 (Python->C++): convert a PyObject into a C++ type
            bool load(handle src, bool)
            {
                if (isinstance<py::dict>(src))
                {

                    value = molcpp::AtomPropertyDict(py::cast<std::map<std::string, molcpp::AtomProperty>>(src));
                }
                else
                    return false;
                return true;
            }
        };

    } // namespace detail
} // namespace pybind11
