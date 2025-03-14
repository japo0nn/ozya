#ifndef RESULT_H
#define RESULT_H

#include <optional>

#include "string"

template <typename TData>
class Result {
   private:
    bool succeed{true};
    std::string error_text;
    std::optional<TData> data;

    Result(bool p_succeed, const std::string& p_error_text,
           std::optional<TData> p_data = std::nullopt)
        : succeed(p_succeed), error_text(p_error_text), data(p_data) {}

   public:
    static Result Success(TData p_value) { return Result(true, "", p_value); }

    // Фабричный метод для ошибки
    static Result Failure(const std::string& p_error_text) { return Result(false, p_error_text); }

    auto isSuccess() -> bool { return succeed; }

    auto getValue() const -> TData {
        if (!succeed) throw std::runtime_error("No value, operation failed");
        return *data;
    }

    std::string getError() const { return error_text; }
};

#endif
