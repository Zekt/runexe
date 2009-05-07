#ifndef _INVOCATION_PARAMS_H_
#define _INVOCATION_PARAMS_H_

#include <string>
#include <vector>

namespace runexe
{
    class InvocationParams
    {
    private:
        long long timeLimit;
        long long memoryLimit;
        std::string redirectInput;
        std::string redirectOutput;
        std::string redirectError;
        std::string homeDirectory;
        std::string commandLine;
        bool trustedProcess;

        std::string buildCommandLine(const std::vector<std::string>& params,
            size_t fromIndex);
        long long parseTimeLimit(const std::string& s);
        long long parseIdlenessLimit(const std::string& s);
        double parseRequiredLoad(const std::string& s);
        long long parseMemoryLimit(const std::string& s);

    public:
        InvocationParams(const std::vector<std::string>& cmdLineParams);

        long long getTimeLimit() const;
        long long getMemoryLimit() const;
        std::string getRedirectInput() const;
        std::string getRedirectOutput() const;
        std::string getRedirectError() const;
        std::string getHomeDirectory() const;
        std::string getCommandLine() const;
        bool isTrustedProcess() const;
    };
}

#endif
