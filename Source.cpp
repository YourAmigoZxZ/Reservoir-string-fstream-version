#include "Reservoir.h"

void arr_maker(Reservoir*& Reservoirs, int& size);

int main()
{
	setlocale(LC_ALL, "rus");

	Reservoir* Reservoirs = nullptr;
	int user_choice, size = 0, int_buf;
	string buf;
	enum menu {EXIT, PRINT, ADD, VOLUME, SURFACE, CHECKTYPE, COMPSURF, ADDFILE};

	do
	{
		cout << "1.���������� ��� ������\n2.�������� ����� � ������3.���������� ����� ������\n4.���������� ������� ������\n5.��������� ������ �� ����\n6.�������� ������ �� �������\n7.�������� ���������� � ����\n0.�����";
		cin >> user_choice;

		switch (user_choice)
		{
		case PRINT:
			system("cls");

			if (!size)
			{
				cout << "������ ������� ����\n";
				system("pause");
				break;
			}

			for (int i = 0; i < size; i++)
			{
				Reservoirs[i].print();
			}

			system("pause");
			break;
		case ADD:
			system("cls");

			arr_maker(Reservoirs, size);

			cout << "������� ��������, ���, ������, ����� � ������������ ������� ������ ������: ";
			getline(cin, buf);
			Reservoirs[size - 1].set_name(buf);
			getline(cin, buf);
			Reservoirs[size - 1].set_type(buf);
			cin >> int_buf;
			Reservoirs[size - 1].set_width(int_buf);
			cin >> int_buf;
			Reservoirs[size - 1].set_length(int_buf);
			cin >> int_buf;
			Reservoirs[size - 1].set_depth(int_buf);
			cin.ignore();
			break;
		case VOLUME:
			cout << "�������� �����, ������� �������� ������ ����������: ";

			do
			{//int_buf ��������� � �������� ������, � �� �������
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);



		}
	}

	return 0;
}