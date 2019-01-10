
#include <iostream.h>
#include <vector.h>
#include <string.h>
class Nguoi
{
    private:
    int maso;   // mã s?
    char *hoten; // h? tên
    float hsl; //h? s? luong
    public:
    Nguoi *tiep;
    //Các hàm thành ph?n
    Nguoi()
    {}
    Nguoi(int id, char *ht, float salary)
    {
        maso = id;
        hoten = ht;
        hsl = salary;
        tiep = NULL;
    }
    int getmaso()
    {   return maso;    }
    char *gethoten()
    {   return hoten;   }
    float gethsl()
    {   return hsl;     }
    void setDuLieu(Nguoi ob_Nguoi)
    {  
        //Dùng d? trao d?i d? li?u gi?a 2 d?i tu?ng trên dslk mà không làm v? c?u trúc danh sách
        maso = ob_Nguoi.getmaso();
        hoten = ob_Nguoi.gethoten();
        hsl = ob_Nguoi.gethsl();
    }
//  
    Nguoi *gettiep()
    {   return tiep;    }
    void settiep(Nguoi *p)
    {   tiep = p;   }
//  
    void Nhap()
    {
        cout<<"Nh?p mã s?: "; cin>>maso;
        hoten  = new char[25];
        cout<<"Nh?p h? tên: "; cin.get(hoten,25);
        cout<<"Nh?p h? s? luong: "; cin>>hsl;
        tiep = NULL;
    }
    void HienThi()
    {   cout<<maso<<"\t"<<hoten<<"\t"<<hsl<<"\t"<<endl;     }
};
class QuanLy
{
    private: Nguoi *dau; // con tro dau tr? t?i d?u ds
    public: // Các hàm thành ph?n
    QuanLy()
    {   dau = NULL; }
    void ChenDau(Nguoi *p_Nguoi)
    {  
        p_Nguoi->settiep(dau);
        dau = p_Nguoi->gettiep();
    }
    void TaoDanhSach()
    {
        int n;
        Nguoi *p_Nguoi;
        cout<<"Nh?p s? nhân viên: "<<endl; cin>>n;
        for(int i =0; i < n; i++)
        {
            cout<<"Nh?p thông tin cho nhân viên th? "<<i+1<<endl;
            p_Nguoi = new Nguoi;
            p_Nguoi->Nhap();
            ChenDau(p_Nguoi);
        }
    }
    void SapXep_HoTen()
    {
        Nguoi *p_Nguoi1, *p_Nguoi2;
        p_Nguoi1 = dau;
        while (p_Nguoi1->gettiep() != NULL)
        {
            p_Nguoi2 = p_Nguoi1->gettiep();
            while (p_Nguoi2!=NULL)
            {
                if (strcmp(p_Nguoi1->gethoten(),p_Nguoi2->gethoten()) > 0)
                {
                    Nguoi temp = *p_Nguoi1;
                    p_Nguoi1->setDuLieu(*p_Nguoi2);
                    p_Nguoi2->setDuLieu(temp);
                }
                p_Nguoi2 = p_Nguoi2->gettiep();
            }
            p_Nguoi1 = p_Nguoi1->gettiep();
        }
    }
    void Xoa()
    {
        int id;
        cout<<"Nh?p mã s? nhân viên c?n xóa: "; cin>>id;
        Nguoi *p_Nguoi1,*p_Nguoi2;
        p_Nguoi1 = dau;
        while ((p_Nguoi1->getmaso()!= id) && (p_Nguoi1 != NULL))
            p_Nguoi1 = p_Nguoi1->gettiep();
        if (p_Nguoi1 == NULL)
            cout<<"Không t?n t?i nhân viên có mã s? tuong ?ng"<<endl;
        else
        {
            p_Nguoi2 = dau;
            while(p_Nguoi2->gettiep() != p_Nguoi1)
                p_Nguoi2 = p_Nguoi2->gettiep();
            p_Nguoi2->settiep(p_Nguoi1->gettiep());
            delete(p_Nguoi1);
            cout<<"Ðã xóa nhân viên có mã s? "<<id<<endl;
        }
    }
    void InDanhSachNhanVien()
    {
        cout<<"Mã s?: \t H? tên \t H? s? luong"<<endl;
        Nguoi *p_Nguoi = dau;
        while(p_Nguoi != NULL)
        {
            p_Nguoi->HienThi();
            p_Nguoi = p_Nguoi->gettiep();
        }
    }
};
void main()
{
    clrscr();
    QuanLy ob_QuanLy;
    ob_QuanLy.TaoDanhSach();
    cout<<"Danh sách nhân viên chua du?c s?p x?p:"<<endl;
    ob_QuanLy.InDanhSachNhanVien();
    ob_QuanLy.SapXep_HoTen();
    cout<<"Danh sách nhân viên du?c s?p theo th? t? tang d?n c?a h? tên: "<<endl;
    ob_QuanLy.InDanhSachNhanVien();
    ob_QuanLy.Xoa();
    cout<<"Danh sách nhân viên sau khi xóa: "<<endl;
    ob_QuanLy.InDanhSachNhanVien();
    getch();
}
