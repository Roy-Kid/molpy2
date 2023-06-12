#include "utils.h"
#include "itemtype.h"

namespace py = pybind11;

namespace pybind11
{
    namespace detail
    {

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
    void bind_itemtype(py::module &m)
    {
        auto mm = m.def_submodule("itemtype");

        py::class_<AtomType>(mm, "AtomType")
        .def(py::init<const std::string&>(), py::arg("name"))
        .def("get_name", &AtomType::get_name)
        // .def("set_name", &AtomType::set_name, py::arg("name"))
        .def("equal_to", py::overload_cast<AtomType*>(&AtomType::equal_to))
        .def("__eq__", py::overload_cast<AtomType*>(&AtomType::equal_to))
        .def("equal_to", py::overload_cast<AtomType&>(&AtomType::equal_to))
        .def("__eq__", py::overload_cast<AtomType&>(&AtomType::equal_to))
        .def("__getitem__", [](AtomType &atom, const std::string &key)
             { return atom[key]; })
        .def("__setitem__", [](AtomType &atom, const std::string &key, const AtomProperty value)
             { atom[key] = value; });

        py::class_<AtomTypeManager>(mm, "AtomTypeManager")
        .def(py::init<>())
        .def("def", &AtomTypeManager::def, py::arg("name"))
        .def("get", &AtomTypeManager::get, py::arg("name"))
        .def("get_ntypes", &AtomTypeManager::get_ntypes)
        .def("__len__", &AtomTypeManager::get_ntypes)
        .def("__getitem__", [](AtomTypeManager &m, const std::string &name)
             { return m.get(name); });
        
    }
}