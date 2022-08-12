#include "sinhvien_thietbi.cpp"
#include <limits>

#define MAX 100
int main()
{
    Thietbi *thietbi = new Thietbi[MAX];
    Sinhvien *sinhvien = new Sinhvien[MAX];
    sinhvienthietbi *svtb = new sinhvienthietbi[MAX];
    std::ifstream myfile("danhsachthietbi.txt");
    std::ifstream myfile1("danhsachsinhvien.txt");
    string choice, choice2, choice3, key;
    for (int i = 0; i < 5; i++)
    {
        string id;
        string name;
        int quantity;
        myfile >> id >> name >> quantity;
        thietbi[i].setId(id);
        thietbi[i].setName(name);
        thietbi[i].setQuantity(quantity);
        incrementThietbi(counter);
    }
    for (int i = 0; i < 3; i++)
    {
        string id;
        string name;
        myfile1 >> id >> name;
        sinhvien[i].setId(id);
        sinhvien[i].setName(name);
        incrementSinhvien(index);
    }
    while (true)
    {
        system("cls");
        cout << "Menu:\n";
        cout << "[1] Quan ly cho muon thiet bi\n";
        cout << "[2] Quan ly thiet bi\n";
        cout << "[3] Quan ly sinh vien\n";
        cout << "[4] THOAT CHUONG TRINH\n";
        cout << "Lua chon: ";
        getline(cin, key);
        system("cls");
        if (key == "1")
        {

            while (true)
            {

                cout << "[1] Cho muon thiet bi\n[2] Tra thiet bi\n[3] Danh sach da cho muon\n[4] QUAY LAI TRANG CHU\nLua chon: ";
                getline(cin, choice3);
                system("cls");
                if (choice3 == "1")
                {
                    cout << "LUA CHON 1\n";
                    muonThietbi(svtb, sinhvien, thietbi);
                }
                else if (choice3 == "2")
                {
                    cout << "LUA CHON 2\n";
                    hienthichomuon(svtb);
                    trathietbi(svtb, thietbi);
                }
                else if (choice3 == "3")
                {
                    cout << "LUA CHON 3\n";
                    hienthichomuon(svtb);
                    pressAnykey();
                    system("cls");
                }
                else if (choice3 == "4")
                {
                    break;
                }
            }
        }
        else if (key == "2")
        {
            while (true)
            {
                system("cls");
                cout << "QUAN LY THIET BI (TAI SAN) NHA TRUONG\n\n";
                cout << "[1] Them thiet bi\n";
                cout << "[2] Xoa thiet bi\n";
                cout << "[3] Chinh sua thong tin thiet bi\n";
                cout << "[4] Tim kiem thong tin thiet bi\n";
                cout << "[5] Hien thi danh sach thiet bi hien co\n";
                cout << "[6] QUAY LAI TRANG CHU\n\n";

                cout << "Lua chon: ";
                getline(cin, choice);
                system("cls");
                if (choice == "1")
                {
                    themThietbi(thietbi, counter);
                }
                else if (choice == "2")
                {
                    xoaThietbi(thietbi, counter);
                }
                else if (choice == "3")
                {
                    suaThietbi(thietbi, counter);
                }
                else if (choice == "4")
                {
                    timThietbi(thietbi, counter);
                }
                else if (choice == "5")
                {
                    hienthiThietbi(thietbi, counter);
                    cout << "\nNhap phim bat ki de tiep tuc . . . . ";
                    _getch();
                }
                else if (choice == "6")
                {
                    break;
                }
            }
        }
        else if (key == "3")
        {
            while (true)
            {
                system("cls");
                cout << "QUAN LY SINH VIEN TRONG NHA TRUONG\n\n";
                cout << "[1] Them sinh vien\n";
                cout << "[2] Xoa sinh vien\n";
                cout << "[3] Chinh sua thong tin sinh vien\n";
                cout << "[4] Tim kiem thong tin sinh vien\n";
                cout << "[5] Hien thi danh sach sinh vien hien co\n";
                cout << "[6] QUAY LAI TRANG CHU\n\n";

                cout << "Lua chon: ";
                getline(cin, choice2);
                system("cls");
                if (choice2 == "1")
                {
                    themSinhvien(sinhvien, index);
                }
                else if (choice2 == "2")
                {
                    xoaSinhvien(sinhvien, index);
                }
                else if (choice2 == "3")
                {
                    suaSinhvien(sinhvien, index);
                }
                else if (choice2 == "4")
                {
                    timSinhvien(sinhvien, index);
                }
                else if (choice2 == "5")
                {
                    hienthiSinhvien(sinhvien, index);
                    cout << "\nNhap phim bat ki de tiep tuc . . . . ";
                    _getch();
                }
                else if (choice2 == "6")
                {
                    break;
                }
            }
        }
        else if (key == "4")
        {
            int temp;
            cout << "Ban co muon thoat chuong trinh quan ly khong?\n[1] Co\n[2] Khong\nLua chon: ";
            cin >> temp;
            if (temp == 1)
            {
                system("cls");
                cout << "DA THOAT CHUONG TRINH!";
                quit();
            }
            else
            {
            }
        }
    }
    return 0;
}