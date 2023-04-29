#define FORCE_IMPORT_ARRAY
#include "utils.h"

namespace molcpp
{
    PYBIND11_MODULE(molcpp, m)
    {

        xt::import_numpy();

        bind_atom(m);

    }
}