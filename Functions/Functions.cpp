#include "stdafx.h"
#include "Functions.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include <format>

//==================================================================
//�� �� ����SetSeed
//������������ʼ�����������
//���������
//�� �� ֵ��seed: unsigned
//==================================================================
unsigned SetSeed() {
	LARGE_INTEGER frequency;
	LARGE_INTEGER time;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&time);
	std::cout << "Random Engine Init...\n";
	std::cout << "Freq: " << frequency.QuadPart << " Hz, Time: " << time.QuadPart << " Cycle\n\n";
	isRandomInit = true;
	return (unsigned int)(time.QuadPart * 1000 / frequency.QuadPart);
}

//==================================================================
//�� �� ����Randint
//�����������������
//���������min: int, max: int
//�� �� ֵ��number: int
//==================================================================
int Randint(int min = 0, int max = RAND_MAX) {
	if (!isRandomInit) srand(SetSeed());
	return rand() % (max - min) + min;
}

//==================================================================
//�� �� ����Random
//�������������������
//���������min: double, max:double
//�� �� ֵ��number: double
//==================================================================
double Random(double min = 0, double max = RAND_MAX) {
	if (!isRandomInit) srand(SetSeed());
	return ((double)rand() / RAND_MAX) * (max - min) + min;
}

//==================================================================
//�� �� ����FgColor
//�����������趨����̨����ǰ��ɫ(��׼���)
//���������red: int, green: int, blue: int
//�� �� ֵ��ANSI: string
//==================================================================
std::string FgColor(int r, int g, int b) {
	return std::format("\033[38;2;{};{};{}m", r, g, b);
}

//==================================================================
//�� �� ����BgColor
//�����������趨����̨���ֱ���ɫ(��׼���)
//���������red: int, green: int, blue: int
//�� �� ֵ��ANSI: string
//==================================================================
std::string BgColor(int r, int g, int b) {
	return std::format("\033[48;2;{};{};{}m", r, g, b);
}

//==================================================================
//�� �� ����ResetColor
//�����������������̨����ǰ������ɫ(��׼���)
//���������
//�� �� ֵ��ANSI: string
//==================================================================
std::string ResetColor() {
	return "\033[m";
}

//==================================================================
//�� �� ����QFgColor
//�����������趨����̨����ǰ��ɫ(QtDebug���)
//���������red: int, green: int, blue: int
//�� �� ֵ��ANSI: QString
//==================================================================
QString QFgColor(int r, int g, int b) {
	return QString("\033[38;2;%0;%1;%2m").arg(r).arg(g).arg(b);
}

//==================================================================
//�� �� ����QBgColor
//�����������趨����̨���ֱ���ɫ(QtDebug���)
//���������red: int, green: int, blue: int
//�� �� ֵ��ANSI: QString
//==================================================================
QString QBgColor(int r, int g, int b) {
	return QString("\033[48;2;%0;%1;%2m").arg(r).arg(g).arg(b);
}

//==================================================================
//�� �� ����QResetColor
//�����������������̨����ǰ������ɫ(QtDebug���)
//���������
//�� �� ֵ��ANSI: QString
//==================================================================
QString QResetColor() {
	return QString("\033[m");
}

//==================================================================
//�� �� ����GetScreenScale
//������������ȡϵͳDPI
//���������
//�� �� ֵ��DPI: double
//==================================================================
double GetScreenScale() {
	int screenW = ::GetSystemMetrics(SM_CXSCREEN);
	int screenH = ::GetSystemMetrics(SM_CYSCREEN);
	//std::cout << "screenW =" << screenW << "screenH=" << screenH << std::endl;
	//HWND hwd = ::GetDesktopWindow();
	HDC hdc = ::GetDC(::GetDesktopWindow());
	int width = ::GetDeviceCaps(hdc, DESKTOPHORZRES);
	int height = ::GetDeviceCaps(hdc, DESKTOPVERTRES);
	//std::cout << "width=" << width << "height=" << height << std::endl;
	double scale = (double)width / screenW;
	return scale;
}