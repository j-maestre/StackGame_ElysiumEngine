#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__ 1

#include <thread>
#include <queue>
#include <mutex>
#include <functional>
#include <engine/core/window.h>
#include <engine/core/job.h>

/**
 * @class ResourceManager
 * @brief Manages the loading and retrieval of resources in a multi-threaded environment.
 */
class ResourceManager
{
public:

	/**
	 * @brief Constructor for ResourceManager.
	 * @param window A reference to the Window instance.
	 * @param job_system A reference to the Job system instance.
	 */
	ResourceManager(Window& window, Job& job_system);

	ResourceManager(const ResourceManager& other) = delete;
	ResourceManager(ResourceManager&& other) = delete;

	/**
	 * @brief Destructor for ResourceManager.
	 */
	~ResourceManager();

	/**
	 * @brief Loads a resource of type T asynchronously.
	 * @tparam T The type of the resource to load.
	 * @param string The identifier or path of the resource.
	 * @return A shared pointer to the loaded resource.
	 */

	template<typename T>
	std::shared_ptr<T> Load(const char* string) {
		auto res = std::make_shared<T>();
		std::future<std::shared_ptr<Resource>> fut_res = job_system_->add ([res, string] {
			auto new_res = std::make_shared<T>(string);
			*res = std::move(*new_res);
			return static_cast<std::shared_ptr<Resource>>(res);
		});
		window_->future_res_.push_back(std::move(fut_res));
		return res;
	}

private:

	Window* window_;
	Job* job_system_;

};



#endif