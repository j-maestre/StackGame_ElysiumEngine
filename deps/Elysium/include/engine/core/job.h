#ifndef __JOB_H__
#define __JOB_H__ 1

#include <queue>
#include <functional>
#include <future>

/**
 * @brief A class representing a job system that manages asynchronous tasks.
 */
class Job {
public:

	/**
	 * @brief Default constructor.
	 */
	Job();

	/**
	 * @brief Destructor.
	 */
	~Job();

	/**
	 * @brief Adds a new task to the job system.
	 * @tparam Function The type of the task function.
	 * @tparam Args The types of the task function arguments.
	 * @param task The task function to be executed asynchronously.
	 * @param args The arguments to be forwarded to the task function.
	 * @return A std::future representing the result of the task function.
	 */
	template<typename Function, typename... Args>
	auto add(Function&& task, Args&&... args)->std::future<decltype(task(args...))> {
		std::lock_guard<std::mutex> lock{ queue_mutex_ };
		using Ret = decltype(task(args...));
		auto t = std::make_shared<std::packaged_task<Ret()>>(task);
		std::future<Ret> future = t->get_future();

		jobs_.push([t]() { (*t)(); });

		queue_condition_.notify_one();

		return future;
	}

private:
	std::vector<std::thread> workers_; /**< A vector of worker threads. */
	std::queue<std::function<void()>> jobs_; /**< A queue of tasks to be executed. */
	std::mutex queue_mutex_; /**< A mutex to synchronize access to the task queue. */

	std::condition_variable queue_condition_;
	bool stop_threads_;
};


#endif