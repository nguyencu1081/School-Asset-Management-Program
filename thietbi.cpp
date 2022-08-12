
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Thietbi
{
private:
    string id, name;
    int quantity;

public:
    void
    setId(string a) { id = a; }
    void setName(string b) { name = b; }
    void setQuantity(int c) { quantity = c; }

    string getId() { return id; }
    string getName() { return name; }
    int getQuantity() { return quantity; }
    void display()
    {
        cout << "\tId thiet bi: " << id << endl;
        cout << "\tThiet bi: " << name << endl;
        cout << "\tSo luong: " << quantity << endl
             << endl;
    }
    void display1()
    {
        cout << "\tId thiet bi: " << id << endl;
        cout << "\tThiet bi: " << name << endl;
    }
};
void themThietbi(Thietbi thietbi[], int counter);
void xoaThietbi(Thietbi thietbi[], int counter);
void suaThietbi(Thietbi thietbi[], int counter);
void timThietbi(Thietbi thietbi[], int counter);
void hienthiThietbi(Thietbi thietbi[], int counter);
void quitThietbi();

void pressAnykey();
void pressAnykey()
{
    cout << "\nNhap phim bat ki de tiep tuc . . . . ";
    _getch();
    cout << endl;
}
int counter = 0;
void incrementThietbi(int a)
{
    a++;
    counter = a;
}

void decrementThietbi(int a)
{
    a--;
    counter = a;
}

void themThietbi(Thietbi thietbi[], int counter)
{
    string Id, Name;
    int quantity;
    cout << "THEM THIET BI\n\n";
    cout << "Nhap ten: ";
    getline(cin, Name);
    cout << "Nhap so luong: ";
    // getline(cin, quantity);
    cin >> quantity;
    thietbi[counter].setId(to_string(counter + 1));
    thietbi[counter].setName(Name);
    thietbi[counter].setQuantity(quantity);
    incrementThietbi(counter);
    cout << "\nTHEM THIET BI THANH CONG!\n\nNhap phim bat ki de tiep tuc  . . . . ";
    _getch();
    return;
}

void xoaThietbi(Thietbi thietbi[], int counter)
{
    string id;
    int choice;
    cout << "XOA THIET BI\n\n";
    if (counter == 0)
    {
        cout << "KHONG CO THIET BI DE XOA!\n\nNhap phim bat ki de tiep tuc . . . . ";
        _getch();
        return;
    }
    cout << "Nhap ID: ";
    getline(cin, id);

    for (int i = 0; i < counter; i++)
    {
        if (thietbi[i].getId() == id)
        {
            cout << "\nDa tim thay thiet bi can xoa!\n\n";
            cout << "Ban co muon xoa thiet bi khong?\n[1] Co\n[2] Khong\n\nLua chon: ";
            cin >> choice;
            if (choice == 1)
            {

                for (int a = i; a < counter; a++)
                {
                    thietbi[a] = thietbi[a + 1];
                    thietbi[a].setId(to_string(a + 1));
                }
                decrementThietbi(counter);
                cout << "\nTHIET BI DA XOA THANH CONG!\n\nNhap phim bat ki de tiep tuc . . . . ";
                _getch();
                return;
            }
        }
    }
    cout << "\nKHONG TIM THAY THIET BI!\n\nNhap phim bat ki de tiep tuc . . . . ";
    _getch();
}
void suaThietbi(Thietbi thietbi[], int counter)
{
    system("cls");
    string editId, choice;
    string Name;
    int quantity;
    cout << "\nCHINH SUA THIET BI\n\n";
    if (counter == 0)
    {
        cout << "KHONG TIM THAY THIET BI DE CHINH SUA!\n\nNhap phim bat ki de tiep tuc . . . . ";
        _getch();
        return;
    }
    cout << "Nhap Id: ";
    getline(cin, editId);
    for (int i = 0; i < counter; i++)
    {
        if (thietbi[i].getId() == editId)
        {
            cout << "\nTIM THAY THIET BI!\n\n";
            cout << "Id: " << thietbi[i].getId() << endl;
            cout << "Thiet bi: " << thietbi[i].getName() << endl;
            cout << "So luong: " << thietbi[i].getQuantity() << endl;
            cout << "\nBan co muon chinh sua?\n[1] Co\n[2] Khong\n\nLua chon: ";
            getline(cin, choice);
            if (choice == "1")
            {
                cout << "Nhap ten thiet bi: ";
                getline(cin, Name);
                cout << "Nhap so luong: ";
                // getline(cin, quantity);
                cin >> quantity;
                thietbi[i].setName(Name);
                thietbi[i].setQuantity(quantity);

                cout << "\nCHINH SUA THIET BI THANH CONG!\n\nNhap phim bat ki de tiep tuc . . . . ";
                _getch();
                return;
            }
            else
            {
                return;
            }
        }
    }
    cout << "\nKHONG TIM THAY THIET BI!\n\nNhap phim bat ki de tiep tuc . . . . ";
    _getch();
}
void timThietbi(Thietbi thietbi[], int counter)
{
    string Id;
    int choice;
    bool print = false;
    cout << "TIM KIEM THIET BI\n\n";
    if (counter == 0)
    {
        cout << "KHONG TIM THAY THIET BI!\n\nNhap phim bat ki de tiep tuc  . . . . ";
        _getch();
        return;
    }
    cout << "Nhap Id: ";
    getline(cin, Id);
    for (int i = 0; i < counter; i++)
    {
        if (thietbi[i].getId() == Id)
        {
            cout << "\nTIM THAY THIET BI!\n\n";
            cout << "Id: " << thietbi[i].getId() << endl;
            cout << "Thiet bi: " << thietbi[i].getName() << endl;
            cout << "So luong: " << thietbi[i].getQuantity() << endl;
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
        cout << "\nKHONG TIM THAY THIET BI!\n\nNhap phim bat ki de tiep tuc . . . . ";
        _getch();
        return;
    }
}
void hienthiThietbi(Thietbi thietbi[], int counter)
{
    if (counter == 0)
    {
        cout << "KHONG CO THIET BI NAO CA!\n\nNhap phim bat ki de tiep tuc  . . . . ";
        _getch();
        return;
    }
    cout << "DANH SACH THIET BI\n";
    for (int i = 0; i < counter; i++)
    {
        cout << endl;
        cout << "Id: " << thietbi[i].getId() << endl;
        cout << "Thiet bi: " << thietbi[i].getName() << endl;
        cout << "So luong: " << thietbi[i].getQuantity()
             << endl;
    }
}
void quitThietbi()
{
    _exit(1);
}
