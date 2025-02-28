#include "http_request.h"
#include "iostream"
#include "result.h"

using namespace std;

int main() {
	Result res = send_http_request("sds", "sds");
	cout << "Result success: " << res.IsSuccess() << endl;
	return 0;
}
