#include "utils.h"
#include "atom.h"
#include "bond.h"

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
            static handle cast(const molcpp::AtomProperty &d, return_value_policy, handle)
            {

                switch (d.index())
                {
                case 0:
                    return py::cast(d.get<int>()).inc_ref();
                case 1:
                    return py::cast(d.get<double>()).inc_ref();
                case 2:
                    return py::cast(d.get<std::string>()).inc_ref();
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

namespace molcpp
{
    void bind_atom(py::module &m)
    {
        auto mm = m.def_submodule("atom", "Atom module");

        py::class_<Atom>(mm, "Atom")
            .def(py::init<const std::string&, Vector3D>(), py::arg("name") = "", py::arg("pos") = Vector3D(0, 0, 0))
            .def(py::init<const Atom&>())
            .def("equal_to", py::overload_cast<Atom*>(&Atom::equal_to))
            .def("has", &Atom::has)
            .def("get_id", &Atom::get_id)
            .def("set_type", &Atom::set_type)
            .def("get_type", &Atom::get_type)
            .def("__eq__", py::overload_cast<Atom*>(&Atom::equal_to))
            .def("__getitem__", [](Atom &atom, const std::string &key)
                 { return atom[key]; })
            .def("__setitem__", [](Atom &atom, const std::string &key, const AtomProperty value)
                 { atom[key] = value; });
    }
}