#ifndef EXCEPTIONRESSOURCEINTROUVABLE_H
#define EXCEPTIONRESSOURCEINTROUVABLE_H

#include <exception>
#include <experimental/string_view>
#include <string>

class ExceptionResourceNotFound : public std::exception
{
    public:
        ExceptionResourceNotFound(std::experimental::string_view const& path);
        virtual const char* what() const noexcept override;

    protected:

    private:
        std::string errorMessage{};
};

#endif // EXCEPTIONRESSOURCEINTROUVABLE_H
