#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Reservoir
{
private:
	string name;
	string type;
	int width;
	int length;
	int depth;
public:
	//������������
	Reservoir() : Reservoir("", "", 0, 0, 0) {}
	explicit Reservoir(string name_p) : Reservoir(name_p, "", 0, 0, 0) {}
	explicit Reservoir(int depth_p) : Reservoir("", "", 0, 0, depth_p) {}
	Reservoir(string name_p, string type_p, int width_p, int length_p, int depth_p) : name{ name_p }, type{ type_p }, width{ width_p },
		length{ length_p }, depth{ depth_p } {}
	Reservoir(const Reservoir& reserv) : name{ reserv.name }, type{ reserv.type }, width{ reserv.width }, length{ reserv.length }, depth{ reserv.depth } {}
	//���������
	string get_name() const noexcept { return name; }
	string get_type() const noexcept { return type; }
	int get_width() const noexcept { return width; }
	int get_length() const noexcept { return length; }
	int get_depth() const noexcept { return depth; }
	//������������
	void set_name(string name_p) noexcept { name = name_p; }
	void set_type(string type_p) noexcept { type = type_p; }
	void set_width(int width_p) noexcept { width = width_p; }
	void set_length(int length_p) noexcept { length = length_p; }
	void set_depth(int depth_p) noexcept { depth = depth_p; }

	void print() const noexcept { cout << "�������� - " << name << '\n' << "��� - " << type << '\n' << "������ - " << width << '\n' << "����� - " << length << '\n' << "������� - " << depth << '\n'; }

	int volume() const noexcept { return width * length * depth; }

	int surface() const noexcept { return width * length; } //�����������, ��� ����� ������ �������������

	bool check_type(const Reservoir& reserv) const noexcept { return type == reserv.type ? true : false; }

	int surf_compare(const Reservoir& reserv) const noexcept;

	//���������� �� ���������
	~Reservoir() = default;
};

