#pragma once
class Reservoir
{
private:
	char* name;
	char* type;
	int width;
	int length;
	int depth;
public:
	Reservoir() : Reservoir(nullptr, nullptr, 0, 0, 0) {}
	explicit Reservoir(char* name_p) : Reservoir(name_p, nullptr, 0, 0, 0) {}
	Reservoir(char* name_p, char* type_p, int width_p, int length_p, int depth_p) : name {name_p ? new char[strlen(name_p) + 1]}
};

