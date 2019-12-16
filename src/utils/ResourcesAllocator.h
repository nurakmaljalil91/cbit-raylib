#ifndef RESOURCESALLOCATOR_H
#define RESOURCESALLOCATOR_H

#include <map>
#include <memory>
#include <string>

template <typename T>
class ResourcesAllocatorBase
{
private:
    int current_id;
    std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;

public:
    int Add(const std::string &filepath)
    {
        auto iter = resources.find(filepath);
        if (iter != resources.end())
        {
            return iter->second.first;
        }

        std::shared_ptr<T> resource = std::make_shared<T>();
        if (!resource->loadFromFile(filepath))
        {
            return -1;
        }

        resources.insert(std::make_pair(filepath, std::make_pair(current_id, resource)));

        return current_id++;
    }

    void Remove(int id)
    {
        for (auto iter = resources.begin(); iter != resources.end(); ++iter)
        {
            if (iter->second.first == id)
            {
                resources.erase(iter->first);
            }
        }
    }

    std::shared_ptr<T> Get(int id)
    {
        for (auto iter = resources.begin(); iter != resources.end(); ++iter)
        {
            if (iter->second.first == id)
            {
                return iter->second.second;
            }
        }

        return nullptr;
    }
}; // class ResourcesAllocator

#endif // RESOURCESALLOCATOR_H