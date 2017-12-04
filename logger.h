#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <string>

class LoggerPrivate;

class Logger
{
public:
    enum class Level
    {
        Error = 0,
        Debug = 1,
        Trace = 2
    };

    enum class Device
    {
        Console = 0x01,
        File    = 0x02,
        Both    = Console | File
    };

private:
    Logger(Level level,
           Device device,
           const std::string& fileName = "");

public:
    ~Logger();

    Logger(const Logger& other) = delete;
    Logger& operator= (const Logger& other) = delete;

    Logger(Logger&& other) = default;
    Logger& operator= (Logger&& other) = default;

    static Logger& initialize(Level level,
                              Device device = Device::Console,
                              std::string fileName = "");
    static Logger& instance();

    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
    void debug(const std::string& message);
    void trace(const std::string& message);

private:
    static std::unique_ptr<Logger> m_instance;

    std::unique_ptr<LoggerPrivate> m_pimpl;

};

#endif // LOGGER_H
