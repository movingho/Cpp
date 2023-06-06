#include <iostream>
#include <fstream>

// 기본 클래스
class Calculator0 {
public:
	virtual double calculate(double operand1, double operand2) const = 0;  // 가상 함수
};

// 계산기 클래스 템플릿
template <typename T>
class Calculator1 : public Calculator0 {
public:
	T calculate(T operand1, T operand2) const override {
		return operand1 + operand2;  // 기본적으로 덧셈을 수행하도록 예시로 구현함
	}
};

template <typename T>
class Calculator2 : public Calculator0 {
public:
	T calculate(T operand1, T operand2) const override {
		return operand1 - operand2;  // 기본적으로 덧셈을 수행하도록 예시로 구현함
	}
};

template <typename T>
class Calculator3 : public Calculator0 {
public:
	T calculate(T operand1, T operand2) const override {
		return operand1 * operand2;  // 기본적으로 덧셈을 수행하도록 예시로 구현함
	}
};

template <typename T>
class Calculator4 : public Calculator0 {
public:
	T calculate(T operand1, T operand2) const override {
		if (operand2 == 0) {
			throw std::runtime_error("0으로 나눌 수 없습니다.");
		}
		return operand1 / operand2;
	}
};

int main() {
	// 미리 작성된 계산
	double operand1 = 10.5;
	double operand2 = 1;

	Calculator0* Calculator = new Calculator4<double>();

	// 예외 처리를 위한 try-catch 블록
	try {
		// 계산 수행
		double result = Calculator->calculate(operand1, operand2);

		// 결과 출력을 파일로 저장
		std::ofstream output("result.txt");
		output << "결과: " << result << std::endl;
		output.close();

		std::cout << "계산 결과가 result.txt 파일에 저장되었습니다." << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "오류: " << e.what() << std::endl;
	}

	delete Calculator;  // 동적 할당된 객체 메모리 해제

	return 0;
}
