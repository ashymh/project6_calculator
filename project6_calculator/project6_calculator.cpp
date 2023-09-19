#include <iostream>

using namespace std;

class calculator { //입력값과 결과 출력을 선언하는 부모클래스
protected:
	double num_1;
	double num_2;
	char mark;
public:
	virtual double operation(double num_1, double num_2) {
		return 0;
	}

	static double result;

	virtual void show_result(){
		cout << "결과: " << result << endl << "----------------------------------------------------" << endl;
	}
};

class add : public calculator { // 부모클래스를 상속받은 +의 클래스 
public:
	double operation(double num_1, double num_2) {
		return num_1 + num_2;
	}
};

class sub : public calculator { // 부모클래스를 상속받은 -의 클래스 
public:
	double operation(double num_1, double num_2) {
		return num_1 - num_2;
	}
};

class mul : public calculator {// 부모클래스를 상속받은 *의 클래스 
public:
	double operation(double num_1, double num_2) {
		return num_1 * num_2;
	}
};

class division : public calculator {// 부모클래스를 상속받은 /의 클래스 div란 함수가 있어 오류날수 있기에 division으로 변경
public:
	double operation(double num_1, double num_2) {
		return num_1 / num_2;
	}
};


double calculator::result = 0;

int main()
{
	calculator* cal = NULL; //부모클래스 선언이후 초기화
	
	while (1) {
		double num_1, num_2; 
		char mark;
		string op;
		cout << "숫자를 입력해주세요 : ";
		cin >> num_1;
		cout << "연산자를 입력해주세요 : ";
		cin >> mark;
		cout << "숫자를 입력해주세요 : ";
		cin >> num_2;
		cout << "----------------------------------------------------" << endl;
		
		// 각각의 연산자를 받아 해당하는 클래스 선언
		if(mark == '+' ) {
			cal = new add(); 
		}
		if (mark == '-') {
			cal = new sub();
		}
		if (mark == '*') {
			cal = new mul();
		}
		if (mark == '/') {
			cal = new division();
		}
		calculator::result = cal->operation(num_1, num_2);

		cal->show_result();

		while (1) {
			cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC: 초기화, EXIT: 종료)";
			cin >> op;
			if (op == "Y") { //계속적인 연산을 할때 새로운 숫자와 부호 입력후 결과 출력

				char new_mark;
				double new_num = 0;

				cout << "연산자를 입력해주세요 : "; 
				cin >> new_mark;
				cout << "숫자를 입력해주세요 : ";
				cin >> new_num;

				if (new_mark == '+') {
					cal = new add();
				}
				if (new_mark == '-') {
					cal = new sub();
				}
				if (new_mark == '*') {
					cal = new mul();
				}
				if (new_mark == '/') {
					cal = new division();
				}
				calculator::result = cal->operation(calculator::result, new_num);
				cal->show_result();
				continue;
			}
			if (op == "AC") { //계산 이후 기능 루프를 탈출하기 위해 break 
				calculator::result = 0;
				delete cal;

				break;
			}
			if (op == "EXIT") { // 0을 반환해 프로그램 종료
				delete cal;
				return 0;
			}
		}
   }
	return 0;
}

