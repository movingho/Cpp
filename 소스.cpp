#include <iostream>
#include <fstream>

// 기본 클래스
class CalculatorBase {
public:
    virtual double calculate(double operand1, double operand2) const = 0;  // 가상 함수
};

// 계산기 클래스 템플릿
template <typename T>
class Calculator : public CalculatorBase {
public:
    T calculate(T operand1, T operand2) const override {
        return operand1 + operand2;  // 기본적으로 덧셈을 수행하도록 예시로 구현함
    }
};

int main() {
    // 미리 작성된 계산
    double operand1 = 10.5;
    double operand2 = 5.5;

    CalculatorBase* calculator = new Calculator<double>();

    // 예외 처리를 위한 try-catch 블록
    try {
        // 계산 수행
        double result = calculator->calculate(operand1, operand2);

        // 결과 출력을 파일로 저장
        std::ofstream output("result.txt");
        output << result;
        output.close();

        std::cout << "계산 결과가 result.txt 파일에 저장되었습니다." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "오류: " << e.what() << std::endl;
    }

    delete calculator;  // 동적 할당된 객체 메모리 해제

    return 0;
}
