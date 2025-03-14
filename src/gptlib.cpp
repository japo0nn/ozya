#include "gptlib.h"

#include "headers.h"

auto gpt_init(const std::string mode, const std::string model, const std::string apikey) -> GPT {
    return GPT::Create(mode, model, apikey);
}

auto gpt_send_message(const GPT& gpt, const std::string& message) -> std::string {
    nlohmann::json payload = {
        {"model", gpt.GetModel()},
        {"messages",
         nlohmann::json::array(
             {{{"role", "system"},
               {"content",
                "Ты - мой персональный, универсальный ассистент. И очень саркастичный."}},
              {{"role", "user"}, {"content", message}}})},
        {"stream", false}};
    Result<nlohmann::json> response = send_http_request(gpt.GetUrl(), MethodType::POST, payload);

    return response.getValue().dump();
}
