#pragma once  // 헤더가드 (전처리기)

/*
	컴파일 에러의 경우, 해당 라인으로 접근이 용이하기 때문에 더블클릭으로 해당 위치에 갈 수 있지만, 
	링크에러의 경우, 해당 라인으로 접근이 어렵기 때문에 잘 해야함
	또한, 함수의 프로토타입만 선언되어 있으면 (forward declaration) 컴파일은 되지만,
	실제 함수 정의가(definition) 없으면 링크 단계에서 문제생김
*/


/*
	헤더 본문에 함수 정의 들어가도 상관없지만,
	각자 cpp로 관리하고 헤더에 프로토타입만 나열하는 습관이 나음?
	나중에 클래스 선언하고 객체지향들어가면 이렇게하는게 나음
*/

int addTwoNumbers(int num_a, int num_b); // 함수 프로토타입 (prototype)
int productTwoNumbers(int num_a, int num_b);
int subtractTwoNumbers(int num_a, int num_b);
