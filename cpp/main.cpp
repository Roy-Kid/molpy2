#include "util.h"

namespace py = pybind11;

namespace molcpp
{

    PYBIND11_MODULE(molcpp, m)
    {

        bind_linalg(m);
        // bind_atom(m);
        // bind_itemtype(m);
    }
}