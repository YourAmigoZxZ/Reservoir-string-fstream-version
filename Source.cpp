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

	cout << "Введите путь к файлу, с которым будете работать: ";
	getline(cin, path);

	do
	{
		system("cls");
		cout << "1.Посмотреть все водоёмы\n2.Добавить водоём в список\n3.Рассчитать объём водоёма\n4.Рассчитать площадь водоёма\n5.Проверить водоёмы по типу\n6.Сравнить водоёмы по площади\n7.Записать информацию в файл\n0.Выход\n";
		cin >> user_choice;

		switch (user_choice)
		case PRINT:
		{
			system("cls");

			if (!size)
			{
				cout << "Список водоёмов пуст\n";
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

			cout << "Введите название, тип, ширину, длину и максимальную глубину нового водоёма: ";
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
				cout << "Список водоёмов пуст\n";
				system("pause");
				break;
			}

			cout << "Выберите водоём, объём которого хотите рассчитать: ";

			do
			{//int_buf выступает в качестве номера, а не индекса, как и в последующих подобных циклах
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "Объём данного водоёма - " << Reservoirs[int_buf - 1].volume() << '\n';

			system("pause");
			break;
		case SURFACE:
			system("cls");

			if (!size)
			{
				cout << "Список водоёмов пуст\n";
				system("pause");
				break;
			}

			cout << "Выберите водоём, площадь которого хотите рассчитать: ";

			do
			{
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "Площадь данного водоёма - " << Reservoirs[int_buf - 1].surface() << '\n';

			system("pause");
			break;
		case CHECKTYPE:
			system("cls");

			if (!size)
			{
				cout << "Список водоёмов пуст\n";
				system("pause");
				break;
			}

			cout << "Выберите первый водоём для сравнения по типу: ";

			do
			{
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "Выберите второй водоём для сравнения по типу: ";

			do
			{
				cin >> int_buf2;
			} while (int_buf2 < 0 || int_buf2 > size);

			if (Reservoirs[int_buf - 1].check_type(Reservoirs[int_buf2 - 1]) == false)
			{
				cout << "Эти водоёмы разного типа!\n";
			}
			else
			{
				cout << "Эти водоёмы одного типа!\n";
			}

			system("pause");
			break;
		case COMPSURF:
			system("cls");

			if (!size)
			{
				cout << "Список водоёмов пуст\n";
				system("pause");
				break;
			}

			cout << "Выберите первый водоём для сравнения по площади: ";

			do
			{
				cin >> int_buf;
			} while (int_buf < 0 || int_buf > size);

			cout << "Выберите второй водоём того же типа для сравнения по площади: ";

			do
			{
				cin >> int_buf2;
			} while (int_buf2 < 0 || int_buf2 > size);
			
			if (Reservoirs[int_buf - 1].surf_compare(Reservoirs[int_buf2 - 1]) == 0)
			{
				cout << "Водоёмы равны по площади!\n";
			}
			else if (Reservoirs[int_buf - 1].surf_compare(Reservoirs[int_buf2 - 1]) == 1)
			{
				cout << "Площадь первого водоёма больше площади второго!\n";
			}
			else if (Reservoirs[int_buf - 1].surf_compare(Reservoirs[int_buf2 - 1]) == 2)
			{
				cout << "Площадь второго водоёма больше площади первого!\n";
			}
			else
			{
				cout << "Выбраны водоёмы разного типа!\n";
			}

			system("pause");
			break;
		case ADDFILE:
		{
			system("cls");

			if (!size)
			{
				cout << "Список водоёмов пуст\n";
				system("pause");
				break;
			}

			fstream myfile(path, ios::out);

			if (!myfile)
			{
				cout << "Не удалось открыть файл для записи!";
				break;
			}

			for (int i{ 0 }; i < size; i++)
			{
				myfile << i+ 1 << '.' << "Название - " << Reservoirs[i].get_name() << "\nТип - " << Reservoirs[i].get_type() << "\nШирина - " << Reservoirs[i].get_width() << "\nДлина - " << Reservoirs[i].get_length() << "\nГлубина - " << Reservoirs[i].get_depth();
			}

			myfile.close();

			cout << "Данные успешно записаны в файл!\n";

			system("pause");
			break;
		}
		case EXIT:
			break;
		}
	} while (user_choice != 0);

	return 0;
}