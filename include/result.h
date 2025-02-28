#ifndef RESULT_H
#define RESULT_H

#include "string"

class Result {
   private:
	bool succeed{false};
	std::string error_text;

	Result(bool p_succeed, std::string p_error_text) {
		succeed = p_succeed;
		error_text = p_error_text;
	}

   public:
	static Result Success() {
		Result res(true, "");
		return res;
	}

	static Result Failure(const std::string error) {
		Result res(false, error);
		return res;
	}

	bool IsSuccess() { return succeed; }
};

#endif
