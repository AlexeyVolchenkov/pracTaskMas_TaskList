#include <iostream>
using namespace std;


const int MASSIZE = 1000;
int mas[MASSIZE];

// ������� 0:
// �������� ������� ������������� size ��������� ������� �������� ��������� val.
void initByZeroMas(int* imas, int size) {

	if (size > MASSIZE)
		size = MASSIZE;
	for (int i = 0; i < size; i++) {
		mas[i] = 0;
	}
}



// ������� 1:
// �������� ������� ������������� size ��������� ������� �������� ��������� val.
void initMas(int* imas, int size, int val) {

}

//������� 2:
// �������� ������� ����������� size ��������� ������� source � ������ dest

void copyMas(int* source, int* dest, int size) {

}


//������� 3:
//�������� ������� ��������� size ��������� ��������  source � dest. ���� ������� ����� 0, ���� �� ����� -1

int compareMas(int* source, int* dest, int size) {
	return 0;
}

//������� 4:
//�������� �������� �� ������� ����� n-�� �������� �������. ������ ������� ������ ����������� ������.
void deleteFromMas(int* source, int n, int size) {

}

// ������� 5:
// �������� ������� ������ ������ �� n-��������� � ����������� ������� ��������� ������

void rShiftMas(int* source, int n, int size) {

}



// ������� 6:
// �������� ������� ������ ����� �� n-��������� � ����������� ������� ��������� ������
void lShiftMas(int* source, int n, int size) {

}


// ������� 7:
// �������� ������� ������ ����� �� n-��������� � ��������� ����������� ��������� � �����
void lRoundShiftMas(int* source, int n, int size) {
	int a = 0;
	for (int j = 0; j < n; j++) {
		a = source[0];
		for (int i = 0; i < size; i++) {
			if (size == i + 1) {
				break;
			}
			source[i] = source[i + 1];
		}
		if (j + 1 > n) break;
		source[size - 1] = a;
	}
}


// ������� 8:
// �������� ���������� � ����� ������ �� ������� ������ ��������� �������. ������ ������� ������ ���������.
void pushToMas(int* source, int val, int size) {

}



// ������� 8:
// �������� ������� ���������� �������� �������� ��������� �������.
int averageMas(int* source, int size) {
	return 0;
}

// ������� 9:
//�������� ������� ���������� ������ ��������������� ���������� ��������� �������.
int SkoFromMas(int* source, int size) {
	return 0;
}


// �����

// ������� 0:
// �������� ������� ������������� size ��������� ������� �������� ��������� val.
int testInitByZeroMas() {
	// �������������� ....
	// initByZeroMas(int* imas, int size)
	return 0;
}




// ������� 1:
// �������� ������� ������������� size ��������� ������� �������� ��������� val.

int testInitMas() {
	return -1;
}

//������� 2:
// �������� ������� ����������� size ��������� ������� source � ������ dest

int testCopyMas() {
	return -1;
}


//������� 3:
//�������� ������� ��������� size ��������� ��������  source � dest. ���� ������� ����� 0, ���� �� ����� -1

int testCompareMas() {
	int source[] = { 0,1,2,3,4,5,6,7,8,9 };
	int dest[] = { 0,1,2,3,4,5,6,7 };

	if (compareMas(source, dest, 8) != 0)
		return -1;

	int source1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int dest1[] = { 1,1,2,3,4,5,6,7 };

	if (compareMas(source1, dest1, 8) != -1)
		return -1;

	return 0;
}

//������� 4:
//�������� �������� �� ������� ����� n-�� �������� �������. ������ ������� ������ ����������� ������.
int testDeleteFromMas() {
	return -1;
}

// ������� 5:
// �������� ������� ������ ������ �� n-��������� � ����������� ������� ��������� ������

int testrShiftMas() {
	return -1;
}



// ������� 6:
// �������� ������� ������ ����� �� n-��������� � ����������� ������� ��������� ������
int testlShiftMas() {
	return -1;
}


// ������� 7:
// �������� ������� ������ ����� �� n-��������� � ��������� ����������� ��������� � �����
bool CompareMas(int* a, int* b, int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] != b[i]) return false;

	return true;
}
bool testlRoundShiftMas(int* first1, int* first2) {
	lRoundShiftMas(first1, 3, 5);
	return CompareMas(first1, first2, 5);
}


// ������� 8:
// �������� ���������� � ����� ������ �� ������� ������ ��������� �������. ������ ������� ������ ���������.
int testPushToMas() {
	return -1;
}


// ������� 8:
// �������� ������� ���������� �������� �������� ��������� �������.
int testAverageMas() {
	return -1;
}

// ������� 9:
//�������� ������� ���������� ������ ��������������� ���������� ��������� �������.
int testSkoFromMas() {
	return -1;
}


void runTest(int (*testFunction)(), const std::string& testName)
{
	if (testFunction() == 0)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}



int main() {
	const int size = 5;
	int first1[size] = { 1, 2, 3, 4, 5 };
	int first2[size] = { 4, 5, 1, 2, 3 };
	int second1[size] = { 5, -4, 3, -2, 1 };
	int second2[size] = { -2, 1, 5, -4, 3 };
	int source[size] = { 1,2,3,4,5 };
	if (testlRoundShiftMas(first1, first2)) cout << "Test ok";
	else cout << "Test not ok" << endl;
	if (testlRoundShiftMas(second1, second2)) cout << "Test ok";
	else cout << "Test not ok";
}

