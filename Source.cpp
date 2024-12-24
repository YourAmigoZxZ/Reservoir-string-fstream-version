#include "Reservoir.h"

void arr_maker(Reservoir*& Reservoirs, int& size);

int main()
{
	setlocale(LC_ALL, "rus");

	Reservoir* Reservoirs = nullptr;
	string path;
	int user_choice, size = 0, int_buf, int_buf2;
	string buf;
	enum menu {EXIT, PRINT, ADD, VOLUME, SURFACE, CHECKTYPE, COMPSURF, ADDFILE};

	cout << "������� ���� � �����, � ������� ������ ��������: ";
	getline(cin, path);

	do
	{
		system("cls");
		cout << "1.���������� ��� ������\n2.�������� ����� � ������\n3.���������� ����� ������\n4.���������� ������� ������\n5.��������� ������ �� ����\n6.�������� ������ �� �������\n7.�������� ���������� � ����\n0.�����\n";
		cin >> user_choice;

		switch (user_choice)
		case PRINT:
		{
			system("cls");

			if (!size)
			{
				cout << "������ ������� ����\n";
				system("pause");
				break;
			}

			for (int i = 0; i < size; i++)
			{
				cout << "\n" << i + 1 << '.';
				Reservoirs[i].print();
			}

			system("pause");
			break;
		case ADD:
			system("cls");

			arr_maker(Reservoirs, size);

			cout << "������� ��������, ���, ������, ����� � ������������ ������� ������ ������: ";
			cin.ignore();
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
			system("cls");

			if (!size)
			{
				cout << "������ ������� ����\n";
				system("pause");
				break;
			}

			cout << "�������� �����, ����� �������� ������ ����������: ";

			do
			{//int_buf ��������� � �������� ������, � �� �������, ��� � � ����������� �������� ������
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "����� ������� ������ - " << Reservoirs[int_buf - 1].volume() << '\n';

			system("pause");
			break;
		case SURFACE:
			system("cls");

			if (!size)
			{
				cout << "������ ������� ����\n";
				system("pause");
				break;
			}

			cout << "�������� �����, ������� �������� ������ ����������: ";

			do
			{
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "������� ������� ������ - " << Reservoirs[int_buf - 1].surface() << '\n';

			system("pause");
			break;
		case CHECKTYPE:
			system("cls");

			if (!size)
			{
				cout << "������ ������� ����\n";
				system("pause");
				break;
			}

			cout << "�������� ������ ����� ��� ��������� �� ����: ";

			do
			{
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "�������� ������ ����� ��� ��������� �� ����: ";

			do
			{
				cin >> int_buf2;
			} while (int_buf2 < 0 || int_buf2 > size);

			if (Reservoirs[int_buf - 1].check_type(Reservoirs[int_buf2 - 1]) == false)
			{
				cout << "��� ������ ������� ����!\n";
			}
			else
			{
				cout << "��� ������ ������ ����!\n";
			}

			system("pause");
			break;
		case COMPSURF:
			system("cls");

			if (!size)
			{
				cout << "������ ������� ����\n";
				system("pause");
				break;
			}

			cout << "�������� ������ ����� ��� ��������� �� �������: ";

			do
			{
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "�������� ������ ����� ���� �� ���� ��� ��������� �� �������: ";

			do
			{
				cin >> int_buf2;
			} while (int_buf2 < 0 || int_buf2 > size);
			
			if (Reservoirs[int_buf - 1].surf_compare(Reservoirs[int_buf2 - 1]) == 0)
			{
				cout << "������ ����� �� �������!\n";
			}
			else if (Reservoirs[int_buf - 1].surf_compare(Reservoirs[int_buf2 - 1]) == 1)
			{
				cout << "������� ������� ������ ������ ������� �������!\n";
			}
			else if (Reservoirs[int_buf - 1].surf_compare(Reservoirs[int_buf2 - 1]) == 2)
			{
				cout << "������� ������� ������ ������ ������� �������!\n";
			}
			else
			{
				cout << "������� ������ ������� ����!\n";
			}

			system("pause");
			break;
		case ADDFILE:
		{
			system("cls");

			if (!size)
			{
				cout << "������ ������� ����\n";
				system("pause");
				break;
			}

			fstream myfile(path, ios::out);

			if (!myfile)
			{
				cout << "�� ������� ������� ���� ��� ������!";
				break;
			}

			for (int i{ 0 }; i < size; i++)
			{
				myfile << i+ 1 << '.' << "�������� - " << Reservoirs[i].get_name() << "\n��� - " << Reservoirs[i].get_type() << "\n������ - " << Reservoirs[i].get_width() << "\n����� - " << Reservoirs[i].get_length() << "\n������� - " << Reservoirs[i].get_depth();
			}

			myfile.close();

			cout << "������ ������� �������� � ����!\n";

			system("pause");
			break;
		}
		case EXIT:
			break;
		}
	} while (user_choice != 0);

	return 0;
}