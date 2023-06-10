#include "utils.h"

namespace molcpp
{
    PYBIND11_MODULE(molcpp, m)
    {

        bind_atom(m);

    }
}