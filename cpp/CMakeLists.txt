# Use -fPIC even if statically compiled
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)

# compile cpp kernel
add_subdirectory(external/molcpp)
set_target_properties(molcpp PROPERTIES MOLCPP_BUILD_SHARED OFF)

# --- add deps ---
## find python then pybind11
find_package(Python REQUIRED COMPONENTS Interpreter Development NumPy)
find_package(pybind11 REQUIRED CONFIG QUIET)

if (NOT pybind11_FOUND)
    # pybind11 not found, try to find it as a submodule
    # else add it as a submodule at enternal/pybind11
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/pybind11/CMakeLists.txt")
        message(STATUS "pybind11 submodule found")
        add_subdirectory(pybind11)
    else()
        message(STATUS "pybind11 submodule not found, downloading from github")
        include(FetchContent)
        FetchContent_Declare(
            pybind11
            GIT_REPOSITORY 
        )
        FetchContent_MakeAvailable(pybind11)
    endif()
else()
    message(STATUS "pybind11 found")
endif()

# --- compile python module ---
pybind11_add_module(cpp_kernel
    src/bind_linalg.cpp
    src/bind_atom.cpp
    # src/bind_itemtype.cpp
    main.cpp
)
target_include_directories(
    cpp_kernel 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(cpp_kernel PUBLIC molcpp pybind11::module Python::NumPy)

set_target_properties(
    cpp_kernel
    PROPERTIES
    LIBRARY_OUTPUT_NAME molcpp
)

# --- Install libs so python module can import it ---

# Handle where to install the resulting Python package
if(CALL_FROM_SETUP_PY)
    # The CMakeExtension will set CMAKE_INSTALL_PREFIX to the root
    # of the resulting wheel archive
    set(KERNEL_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
else()
    # The Python package is installed directly in the folder of the
    # detected interpreter (system, user, or virtualenv)
    set(KERNEL_INSTALL_PREFIX ${Python3_SITELIB})
endif()

# Install the pybind11 library
install(
    TARGETS cpp_kernel
    # COMPONENT bindings
    LIBRARY DESTINATION ${KERNEL_INSTALL_PREFIX}
    ARCHIVE DESTINATION ${KERNEL_INSTALL_PREFIX}
    RUNTIME DESTINATION ${KERNEL_INSTALL_PREFIX}
)