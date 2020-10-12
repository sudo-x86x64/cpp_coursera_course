#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            return this->last_fetched_time = AskTimeServer();
        } catch(system_error&) {
            return this->last_fetched_time;
        } catch (exception& e) {
            throw runtime_error(e.what());
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
 
    return 0;
}
