#include "sinhvien.cpp"
#include "thietbi.cpp"

class sinhvienthietbi
{
private:
    string id;
    Sinhvien sinhvien;
    Thietbi thietbi;
    int quantity;

public:
    sinhvienthietbi(){};
    sinhvienthietbi(string id, Sinhvien sinhvien, Thietbi thietbi)
    {
        this->id = id;
        this->sinhvien = sinhvien;
        this->thietbi = thietbi;
    }
    Sinhvien getSinhvien()
    {
        return this->sinhvien;
    }
    void setSinhvien(Sinhvien sinhvien)
    {
        this->sinhvien = sinhvien;
    }
    Thietbi getThietbi()
    {
        return this->thietbi;
    }
    void setThietbi(Thietbi thietbi)
    {
        this->thietbi = thietbi;
    }
    void setId(string id)
    {
        this->id = id;
    }
    string getId()
    {
        return this->id;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    int getQuantity()
    {
        return quantity;
    }
};
void muonThietbi(sinhvienthietbi svtb[], Sinhvien sinhvien[], Thietbi thietbi[])
{
    bool flag = false;
    bool flag1 = false;
    string id, id1;
    int soluong;
    for (int i = 0; i < index; i++)
    {
        sinhvien[i].display();
    }
    cout << "Nhap id sinh vien muon muon thiet bi: ";
    getline(cin, id);
    for (int i = 0; i < index; i++)
    {
        if (sinhvien[i].getId() == id)
        {
            svtb[count].setSinhvien(sinhvien[i]);
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        pressAnykey();
        system("cls");
        return;
    }
    system("cls");
    for (int i = 0; i < counter; i++)
    {
        thietbi[i].display();
    }
    cout << "Nhap id thiet bi cho muon: ";
    getline(cin, id1);
    for (int i = 0; i < counter; i++)
    {
        if (thietbi[i].getId() == id1)
        {
            do
            {
                cout << "Nhap so luong " << thietbi[i].getName() << " <= " << thietbi[i].getQuantity() << " muon muon ";
                cin >> soluong;
            } while (soluong > thietbi[i].getQuantity());

            svtb[count].setThietbi(thietbi[i]);
            svtb[count].setQuantity(soluong);
            thietbi[i].setQuantity(thietbi[i].getQuantity() - soluong);
            flag1 = true;
            break;
        }
    }
    if (flag1 == false)
    {
        pressAnykey();
        system("cls");
        return;
    }
    increment(count);
    pressAnykey();
    system("cls");
}
void trathietbi(sinhvienthietbi svtb[], Thietbi thietbi[])
{
    int choice;
    string id, id1;
    cout << "Nhap STT sinh vien tra thiet bi ";
    getline(cin, id);
    for (int i = 0; i < count; i++)
    {
        if (thietbi[i].getId() == id)
        {
            cout << "\nDa tim id sinh viem cam tra!\n\n";
            cout << "Xac nhan tra thiet bi?\n[1] Co\n[2] Khong\n\nLua chon: ";
            cin >> choice;
            if (choice == 1)
            {
                for (int j = 0; j < counter; j++)
                {
                    if (thietbi[j].getId() == svtb[i].getThietbi().getId())
                    {
                        thietbi[j].setQuantity(thietbi[j].getQuantity() + svtb[i].getQuantity());
                    }
                }
                for (int a = i; a < count; a++)
                {
                    svtb[a] = svtb[a + 1];
                    svtb[a].setId(to_string(a + 1));
                }
                decrement(count);
                cout << "\nDA TRA THIET BI THANH CONG!\n";
                pressAnykey();
                system("cls");
                return;
            }
        }
    }
    pressAnykey();
    system("cls");
}
void hienthichomuon(sinhvienthietbi svtb[])
{
    cout << "Danh sach cho muon\n";
    for (int i = 0; i < count; i++)
    {
        cout << "STT " << i + 1 << endl;
        cout << "------------------------\n";
        svtb[i].getSinhvien().display();
        cout << "------------------------\n";
        svtb[i].getThietbi().display1();
        cout << "\tSo luong: " << svtb[i].getQuantity() << endl;
    }
}

int count = 0;
void increment(int a)
{
    a++;
    count = a;
}

void decrement(int a)
{
    a--;
    count = a;
}