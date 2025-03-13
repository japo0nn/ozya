#ifndef __GPTLIB_H__
#define __GPTLIB_H__

#include <string>

class GPT {
   private:
    std::string apikey;
    std::string mode;

    GPT(const std::string& p_mode, const std::string& p_apikey = "")
        : apikey(p_apikey), mode(p_mode) {}

   public:
    static auto Create(const std::string& p_mode, const std::string& p_apikey = "") -> GPT {
        return GPT(p_mode, p_apikey);
    }

    auto GetMode() -> std::string { return mode; }
    auto GetApiKey() -> std::string { return apikey; }
};

#endif
