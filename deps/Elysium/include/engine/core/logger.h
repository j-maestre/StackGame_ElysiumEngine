/**
 * @file Logger.h
 * @brief Definition of the Logger class.
 */

#ifndef __LOGGER_H__
#define __LOGGER_H__ 1

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <iomanip>
#include <ctime>
#include <imgui.h>

 /**
  * @class Logger
  * @brief A class for logging messages using SPDLog.
  */
class Logger
{
public:
	/**
	 * @brief Constructor for the Logger class.
	 */
	Logger();

	/**
	 * @brief Destructor for the Logger class.
	 */
	~Logger();

	/**
	 * @brief Displays the log using ImGui.
	 */
	void ShowLog();

private:
	std::shared_ptr<spdlog::logger> user_logger_; /**< Logger for user messages. */
	std::shared_ptr<spdlog::logger> engine_logger_; /**< Logger for engine messages. */
	bool show_log_; /**< Flag indicating log display. */
	bool show_error_engine_; /**< Flag indicating display of engine errors. */
	bool show_warning_engine_; /**< Flag indicating display of engine warnings. */
	bool show_info_engine_; /**< Flag indicating display of engine info. */
	bool show_debug_log_; /**< Flag indicating display of debug logs. */
	int last_log_count_; /**< Count of the last log entry. */
};

/**
 * @brief Enum defining different log types.
 */
enum LogTypes {
	kEngineError,
	kEngineInfo,
	kEngineWarning,
	kDebug,
};

/**
 * @brief Structure representing saved log data.
 */
struct VectorSaveData {
	LogTypes type;
	std::string text;
	std::string time;

	/**
	 * @brief Constructor for VectorSaveData.
	 * @param logType Type of log entry.
	 * @param logText Text of the log entry.
	 */
	VectorSaveData(LogTypes logType, const std::string& logText)
		: type(logType), text(logText) {
		std::time_t t = std::time(nullptr);
		char buffer[9];
		#if defined(_MSC_VER)
			struct tm timeInfo;
			if (localtime_s(&timeInfo, &t) == 0) {
				if (strftime(buffer, sizeof(buffer), "%T", &timeInfo) > 0) {
					time = buffer;
				}
				else {
					time = "Unknown Time";
				}
			}
			else {
				time = "Unknown Time";
			}
		#else
			std::strftime(buffer, sizeof(buffer), "%T", std::localtime(&t));
			time = buffer;
		#endif
	}
};

/**
 * @brief Vector to store log data.
 */
extern std::vector<VectorSaveData> LogVector;

/**
 * @brief Macro for logging engine errors.
 * @param message Error message.
 */
#define ENGINE_ERROR(message, ...) \
spdlog::get("EngineLogger")->error(message, __VA_ARGS__); \
LogVector.push_back(VectorSaveData(LogTypes::kEngineError,fmt::format(message, __VA_ARGS__)));

#define ENGINE_INFO(message, ...) \
spdlog::get("EngineLogger")->info(message, __VA_ARGS__); \
LogVector.push_back(VectorSaveData(LogTypes::kEngineInfo,fmt::format(message, __VA_ARGS__)));

#define ENGINE_WARNING(message, ...) \
spdlog::get("EngineLogger")->warn(message, __VA_ARGS__); \
LogVector.push_back(VectorSaveData(LogTypes::kEngineWarning,fmt::format(message, __VA_ARGS__)));

#define DEBUG_LOG(message, ...) \
spdlog::get("Log")->debug(message, __VA_ARGS__); \
LogVector.push_back(VectorSaveData(LogTypes::kDebug,fmt::format(message, __VA_ARGS__)));

#endif