#include <iostream>
#include <fstream>

// �⺻ Ŭ����
class CalculatorBase {
public:
    virtual double calculate(double operand1, double operand2) const = 0;  // ���� �Լ�
};

// ���� Ŭ���� ���ø�
template <typename T>
class Calculator : public CalculatorBase {
public:
    T calculate(T operand1, T operand2) const override {
        return operand1 + operand2;  // �⺻������ ������ �����ϵ��� ���÷� ������
    }
};

int main() {
    // �̸� �ۼ��� ���
    double operand1 = 10.5;
    double operand2 = 5.5;

    CalculatorBase* calculator = new Calculator<double>();

    // ���� ó���� ���� try-catch ���
    try {
        // ��� ����
        double result = calculator->calculate(operand1, operand2);

        // ��� ����� ���Ϸ� ����
        std::ofstream output("result.txt");
        output << result;
        output.close();

        std::cout << "��� ����� result.txt ���Ͽ� ����Ǿ����ϴ�." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "����: " << e.what() << std::endl;
    }

    delete calculator;  // ���� �Ҵ�� ��ü �޸� ����

    return 0;
}
