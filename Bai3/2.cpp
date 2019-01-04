
#include <iostream.h>
#include <vector.h>
#include <string.h>
class Nguoi
{
    private:
    int maso;   // m� s?
    char *hoten; // h? t�n
    float hsl; //h? s? luong
    public:
    Nguoi *tiep;
    //C�c h�m th�nh ph?n
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
        //D�ng d? trao d?i d? li?u gi?a 2 d?i tu?ng tr�n dslk m� kh�ng l�m v? c?u tr�c danh s�ch
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
        cout<<"Nh?p m� s?: "; cin>>maso;
        hoten  = new char[25];
        cout<<"Nh?p h? t�n: "; cin.get(hoten,25);
        cout<<"Nh?p h? s? luong: "; cin>>hsl;
        tiep = NULL;
    }
    void HienThi()
    {   cout<<maso<<"\t"<<hoten<<"\t"<<hsl<<"\t"<<endl;     }
};
class QuanLy
{
    private: Nguoi *dau; // con tro dau tr? t?i d?u ds
    public: // C�c h�m th�nh ph?n
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
        cout<<"Nh?p s? nh�n vi�n: "<<endl; cin>>n;
        for(int i =0; i < n; i++)
        {
            cout<<"Nh?p th�ng tin cho nh�n vi�n th? "<<i+1<<endl;
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
        cout<<"Nh?p m� s? nh�n vi�n c?n x�a: "; cin>>id;
        Nguoi *p_Nguoi1,*p_Nguoi2;
        p_Nguoi1 = dau;
        while ((p_Nguoi1->getmaso()!= id) && (p_Nguoi1 != NULL))
            p_Nguoi1 = p_Nguoi1->gettiep();
        if (p_Nguoi1 == NULL)
            cout<<"Kh�ng t?n t?i nh�n vi�n c� m� s? tuong ?ng"<<endl;
        else
        {
            p_Nguoi2 = dau;
            while(p_Nguoi2->gettiep() != p_Nguoi1)
                p_Nguoi2 = p_Nguoi2->gettiep();
            p_Nguoi2->settiep(p_Nguoi1->gettiep());
            delete(p_Nguoi1);
            cout<<"�� x�a nh�n vi�n c� m� s? "<<id<<endl;
        }
    }
    void InDanhSachNhanVien()
    {
        cout<<"M� s?: \t H? t�n \t H? s? luong"<<endl;
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
    cout<<"Danh s�ch nh�n vi�n chua du?c s?p x?p:"<<endl;
    ob_QuanLy.InDanhSachNhanVien();
    ob_QuanLy.SapXep_HoTen();
    cout<<"Danh s�ch nh�n vi�n du?c s?p theo th? t? tang d?n c?a h? t�n: "<<endl;
    ob_QuanLy.InDanhSachNhanVien();
    ob_QuanLy.Xoa();
    cout<<"Danh s�ch nh�n vi�n sau khi x�a: "<<endl;
    ob_QuanLy.InDanhSachNhanVien();
    getch();
}
