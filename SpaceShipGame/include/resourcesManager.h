#ifndef GESTIONNAIRERESSOURCES_H
#define GESTIONNAIRERESSOURCES_H

#include <experimental/string_view>
#include <unordered_map>

#include <iostream>
#include "ExceptionResourceNotFound.h"

template <typename T>
class ResourcesManager
{
    public:
        ResourcesManager() = delete;
        static T const& getRessource(std::experimental::string_view const& path) {
            auto result = resources.find(path);
            if (result == std::end(resources)) {
                if (!resources[path].loadFromFile(path.data())) {
                    throw ExceptionResourceNotFound{path};
                }
                return resources[path];
            }
            return result->second;
        }

    protected:

    private:
        static std::unordered_map<std::experimental::string_view, T> resources;
};

#endif // GESTIONNAIRERESSOURCES_H
