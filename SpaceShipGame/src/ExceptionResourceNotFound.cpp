#include "ExceptionResourceNotFound.h"

using namespace std::string_literals;

ExceptionResourceNotFound::ExceptionResourceNotFound(std::experimental::string_view const& path) : errorMessage("Error, resource not found : "s + path.data())
{
    //ctor
}

const char* ExceptionResourceNotFound::what() const noexcept {
    return errorMessage.c_str();
}
