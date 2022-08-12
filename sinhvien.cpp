
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Sinhvien
{
private:
    string id, name;

public:
    void
    setId(string a) { id = a; }
    void setName(string b) { name = b; }

    string getId() { return id; }
    string getName() { return name; }
    void display()
    {
        cout << "Id sinh vien: " << id << endl;
        cout << "Ho ten: " << name << endl;
    }
};
void themSinhvien(Sinhvien sinhvien[], int index);
void xoaSinhvien(Sinhvien sinhvien[], int index);
void suaSinhvien(Sinhvien sinhvien[], int index);
void timSinhvien(Sinhvien sinhvien[], int index);
void hienthiSinhvien(Sinhvien sinhvien[], int index);
void quit();

int index = 0;
void incrementSinhvien(int a)
{
    a++;
    index = a;
}

void decrementSinhvien(int a)
{
    a--;
    index = a;
}

void themSinhvien(Sinhvien sinhvien[], int index)
{
    string Id, Name;

    cout << "THEM SINH VIEN\n\n";
    cout << "Nhap ten: ";
    getline(cin, Name);
    sinhvien[index].setId(to_string(index + 1));
    sinhvien[index].setName(Name);

    incrementSinhvien(index);
    cout << "\nTHEM SINH VIEN THANH CONG!\n\nNhap phim bat ki de tiep tuc  . . . . ";
    _getch();
    return;
}

void xoaSinhvien(Sinhvien sinhvien[], int index)
{
    string id;
    int choice;
    cout << "XOA SINH VIEN\n\n";
    if (index == 0)
    {
        cout << "KHONG CO SINH VIEN DE XOA!\n\nNhap phim bat ki de tiep tuc . . . . ";
        _getch();
        return;
    }
    cout << "Nhap ID: ";
    getline(cin, id);

    for (int i = 0; i < index; i++)
    {
        if (sinhvien[i].getId() == id)
        {
            cout << "\nDa tim thay sinh vien can xoa!\n\n";
            cout << "Ban co muon xoa sinh vien khong?\n[1] Co\n[2] Khong\n\nLua chon: ";
            cin >> choice;
            if (choice == 1)
            {

                for (int a = i; a < index; a++)
                {
                    sinhvien[a] = sinhvien[a + 1];
                    sinhvien[a].setId(to_string(a + 1));
                }
                decrementSinhvien(index);
                cout << "\nSINH VIEN DA XOA THANH CONG!\n\nNhap phim bat ki de tiep tuc . . . . ";
                _getch();
                return;
            }
        }
    }
    cout << "\nKHONG TIM THAY SINH VIEN!\n\nNhap phim bat ki de tiep tuc . . . . ";
    _getch();
}
void suaSinhvien(Sinhvien sinhvien[], int index)
{
    system("cls");
    string editId, choice;
    string Name;

    cout << "\nCHINH SUA SINH VIEN\n\n";
    if (index == 0)
    {
        cout << "KHONG TIM THAY SINH VIEN DE CHINH SUA!\n\nNhap phim bat ki de tiep tuc . . . . ";
        _getch();
        return;
    }
    cout << "Nhap Id: ";
    getline(cin, editId);
    for (int i = 0; i < index; i++)
    {
        if (sinhvien[i].getId() == editId)
        {
            cout << "\nTIM THAY SINH VIEN!\n\n";
            cout << "Id: " << sinhvien[i].getId() << endl;
            cout << "SINH VIEN: " << sinhvien[i].getName() << endl;

            cout << "\nBan co muon chinh sua?\n[1] Co\n[2] Khong\n\nLua chon: ";
            getline(cin, choice);
            if (choice == "1")
            {
                cout << "Nhap ten SINH VIEN: ";
                getline(cin, Name);

                sinhvien[i].setName(Name);

                cout << "\nCHINH SUA SINH VIEN THANH CONG!\n\nNhap phim bat ki de tiep tuc . . . . ";
                _getch();
                return;
            }
            else
            {
                return;
            }
        }
    }
    cout << "\nKHONG TIM THAY SINH VIEN!\n\nNhap phim bat ki de tiep tuc . . . . ";
    _getch();
}
void timSinhvien(Sinhvien sinhvien[], int index)
{
    string Id;
    int choice;
    bool print = false;
    cout << "TIM KIEM SINH VIEN\n\n";
    if (index == 0)
    {
        cout << "KHONG TIM THAY SINH VIEN!\n\nNhap phim bat ki de tiep tuc  . . . . ";
        _getch();
        return;
    }
    cout << "Nhap Id: ";
    getline(cin, Id);
    for (int i = 0; i < index; i++)
    {
        if (sinhvien[i].getId() == Id)
        {
            cout << "\nTIM THAY SINH VIEN!\n\n";
            cout << "Id: " << sinhvien[i].getId() << endl;
            cout << "SINH VIEN: " << sinhvien[i].getName() << endl;

            print = true;
        }
    }
    if (print)
    {
        cout << "\n\nNhap phim bat ki de tiep tuc . . . . ";
        _getch();
        return;
    }
    else
    {
        cout << "\nKHONG TIM THAY SINH VIEN!\n\nNhap phim bat ki de tiep tuc . . . . ";
        _getch();
        return;
    }
}
void hienthiSinhvien(Sinhvien sinhvien[], int index)
{
    if (index == 0)
    {
        cout << "KHONG CO SINH VIEN NAO CA!\n\nNhap phim bat ki de tiep tuc  . . . . ";
        _getch();
        return;
    }
    cout << "DANH SACH SINH VIEN\n";
    for (int i = 0; i < index; i++)
    {
        cout << endl;
        cout << "Id: " << sinhvien[i].getId() << endl;
        cout << "SINH VIEN: " << sinhvien[i].getName() << endl;
    }
}
void quit()
{
    _exit(1);
}
