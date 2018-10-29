#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include "Journal.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int id;
	char from[20];
	char to[20];
	char date[20];
	char time[20];
	int duration;
	char back_to_menu;
	int main_menu = 0, index;
	Journal journal;
	journal.Read();

	while (main_menu != 11)
	{
		system("cls");
		cout << "1. �������� ������\n";
		cout << "2. �������\n";
		cout << "3. �������� ������\n";
		cout << "4. ���������� �� ������������\n";
		cout << "5. �������� ������ �� ����\n";
		cout << "6. �������� ������ �� ������������\n";
		cout << "7. �������� ������ �� ��������\n";
		cout << "8. �������� ������ ��������\n";
		cout << "9. ��������� ���������\n";
		cout << "10. �����\n";
		cin >> main_menu;
		switch (main_menu)
		{
		case 1:
			system("cls");
			cin.ignore();
			cout << "ID: ";
			cin >> id;
			cout << "FROM: ";
			cin >> from;
			cout << "TO: ";
			cin >> to;
			cout << "DATE: ";
			cin >> date;
			cout << "TIME: ";
			cin >> time;
			cout << "DURATION: ";
			cin >> duration;
			journal.Add(Call(id, from, to, date, time, duration));
			cout<<"������!\n��������� � ����? (y/n)";
			cin>>back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 2:
			system("cls");
			cin.ignore();
			cout << "����� ������ : ";
			cin >> index;
			journal.Delete(index - 1);
			cout << "������!\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 3:
			system("cls");
			cin.ignore();
			journal.Print();
			cout << "\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 4:
			system("cls");
			cin.ignore();
			journal.Sort();
			cout << "������!\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 5:
			system("cls");
			cin.ignore();
			cout << "����������� ����: ";
			cin >> time;
			cout << "������������ ����: ";
			cin >> date;
			journal.FindDATE(time, date);
			cout << "\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 6:
			system("cls");
			cin.ignore();
			cout << "����������� ������������: ";
			cin >> id;
			cout << "������������ ������������: ";
			cin >> duration;
			journal.FindDURATION(id, duration);
			cout << "\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 7:
			system("cls");
			cin.ignore();
			cout << "TO: ";
			cin >> to;
			journal.FindTO(to);
			cout << "\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 8:
			system("cls");
			cin.ignore();
			cout << "FROM: ";
			cin >> from;
			journal.FindFROM(from);
			cout << "\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		case 9:
			system("cls");
			cin.ignore();
			journal.Write();
			cout << "\n��������� � ����? (y/n)";
			cin >> back_to_menu;
			if (back_to_menu != 'y')
				return 0;
			break;
		}
	}
}