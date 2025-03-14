#ifndef __GPTLIB_H__
#define __GPTLIB_H__

#include <string>

class GPT {
   private:
    std::string apikey;
    std::string mode;
    std::string url;
    std::string model;

    GPT(const std::string& p_mode, const std::string& p_model, const std::string& p_apikey = "")
        : apikey(p_apikey), mode(p_mode), model(p_model) {
        if (p_mode == "offline") {
            url = "http://172.29.192.1:11434/api/chat";
        }
    }

   public:
    static auto Create(const std::string& p_mode, const std::string& p_model,
                       const std::string& p_apikey = "") -> GPT {
        return GPT(p_mode, p_model, p_apikey);
    }

    auto GetMode() const -> std::string { return mode; }
    auto GetApiKey() const -> std::string { return apikey; }
    auto GetUrl() const -> std::string { return url; }
    auto GetModel() const -> std::string { return model; }
};

auto gpt_init(const std::string mode, const std::string model, const std::string apikey = "")
    -> GPT;

auto gpt_send_message(const GPT& gpt, const std::string& message) -> std::string;

#endif
