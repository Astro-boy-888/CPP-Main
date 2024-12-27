#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// 自定义异常类
class OutOfRangeException : public exception {
private:
    string message;

public:
    OutOfRangeException(int parameter, int value)
        : message("The parameter " + to_string(parameter) +
                  " is " + to_string(value) + " which out of range (0-100).") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
// 计算平均值的函数
float calculateAverage(int a, int b, int c, int d) {
    int marks[] = {a, b, c, d};
    for (int i = 0; i < 4; ++i) {
        if (marks[i] < 0 || marks[i] > 100) {
            throw OutOfRangeException(i + 1, marks[i]);
        }
    }
    return (a + b + c + d) / 4.0;
}

int main() {
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        try {
            int a, b, c, d;
            cout << "Please enter marks for 4 courses: ";
            cin >> a >> b >> c >> d;

            // 计算平均值
            float average = calculateAverage(a, b, c, d);
            cout << "The average of the four courses is " << average << endl;
        } catch (const OutOfRangeException& e) {
            // 捕获 OutOfRangeException 异常并输出信息
            cout << e.what() << endl;
        }

        // 询问用户是否继续输入
        cout << "Would you want to enter another marks for 4 courses (y/n)? ";
        cin >> choice;
    }

    cout << "Bye, see you next time." << endl;
    return 0;
}
