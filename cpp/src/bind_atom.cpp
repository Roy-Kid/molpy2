#include "utils.h"
#include "atom.h"
#include "bond.h"


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