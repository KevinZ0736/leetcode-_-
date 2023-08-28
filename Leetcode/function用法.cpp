#include <iostream>
#include <functional>

int sum(int a, int b) {
	return a + b;
}

int main() {
	// 包装 sum 函数
	std::function<int(int, int)> sumFunction = sum;

	// 定义参数
	int a_val = 3;
	int b_val = 4;

	// 创建无参数、无返回值的函数 a，捕获参数并调用 sumFunction
	std::function<void()> a = [a_val, b_val, &sumFunction]() {
		int result = sumFunction(a_val, b_val); // 调用 sum 函数计算和
		std::cout << "Sum: " << result << std::endl;
	};

	// 调用无参数、无返回值的函数 a
	a();

	return 0;
}

//class MyClass {
//public:
//    int multiply(int a, int b) {
//        return a * b;
//    }
//};
//
//int main() {
//    MyClass obj;
//
//    // 包装 MyClass 的成员函数，使用 std::bind，同时传递参数
//    int a_val = 3;
//    int b_val = 4;
//    std::function<void()> memberFunctionWrapper = [&obj, a_val, b_val]() {
//        // 调用成员函数，并输出返回值
//        int result = obj.multiply(a_val, b_val);
//        std::cout << "Result: " << result << std::endl;
//    };
//
//    // 调用包装的成员函数
//    memberFunctionWrapper();
//
//    return 0;
//}