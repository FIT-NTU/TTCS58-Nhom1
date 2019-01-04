/*//using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
//using System.Windows.Forms;*/
#include <iostream>
namespace Game_Caro
{
    public partial class Form1 : Form
    {
        Graphics g;
        int r = 80; int c = 80; int dd = 20; int[,] arr; int d = 10; int flag;
        public Form1()
        {
            InitializeComponent();
            arr = new int[r, c];
            SetArr(arr, r, c);
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            g = this.CreateGraphics();
 
            for (int i = 0; i <= r; i++)
                g.DrawLine(new Pen(Color.Blue, 1), 0, i * dd, r * dd, i * dd);
            for (int j = 0; j <= c; j++)
                g.DrawLine(new Pen(Color.Blue, 1), j * dd, 0, j * dd, c * dd);
        }
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.X >= 10 && e.X < r * 15 && e.Y >= 10 && e.Y < c * 15)
            {
                int x = (int)((e.X) / dd);
                int y = (int)((e.Y) / dd);
                if (e.Button.ToString() == "Left")
                {
                    if (arr[x, y] == 0 && flag == 0)
                    {
                        arr[x, y] = 1;
                        Ve_X(x, y);
                        flag = 1;
                        if (Total_Check(x, y))
                        {
                            MessageBox.Show("X Thang O Thua");
                            Application.Restart();
                        }
                    }
                }
 
                if (e.Button.ToString() == "Right")
                {
                    if (arr[x, y] == 0 && flag == 1)
                    {
                        arr[x, y] = 2;
                        Ve_O(x, y);
                        flag = 0;
                        if (Total_Check(x, y))
                        {
                            MessageBox.Show("O Thang X Thua")
                            Application.Restart();
                        }
                   }
                }
 
            }
 
        }
        public void Ve_X(int c, int r)
        {           
            Pen p = new Pen(Color.Black, 2);
            g.DrawLine(p, c * dd, r * dd, (c + 1) * dd, (r + 1) * dd);          
            g.DrawLine(p, c * dd, (r + 1) * dd, (c + 1) * dd, r * dd);
        }
        public void Ve_O(int x, int y)
        {
            Pen p1 = new Pen(Color.Red, 2);
            g.DrawEllipse(p1, x * dd, y * dd, dd, dd);
        }
 
        public void SetArr(int[,] arr, int a, int b)
        {
            for (int i = 0; i < a; i++)
 
                for (int j = 0; j < b; j++)
                {
                    arr[i, j] = 0;
                }
        }
        public bool kt_Ngang(int a, int b)
        {
            int count = 1;
            int x = a + 1;
            while (x < d && arr[a, b] == arr[x, b])
            {
                count++;
                x++;
            }
            x = a - 1;
            while (x >= 0 && arr[a, b] == arr[x, b])
            {
                count++;
                x--;
            }
            return (count == 5) ? true : false;
        }
 
        public bool kt_Doc(int a, int b)
        {
            int count = 1;
            int y = b + 1;
            while (y < r && arr[a, b] == arr[a, y])
            {
                count++;
                y++;
            }
            y = b - 1;
            while (y >= 0 && arr[a, b] == arr[a, y])
            {
                count++;
                y--;
            }
            return (count == 5) ? true : false;
        }
 
 
        public bool kt_Cheo(int a, int b)
        {
            int count = 1;
            int x = a + 1;
            int y = b + 1;
            while (x < c && y < r && arr[a, b] == arr[x, y])
            {
                count = count + 1;
                x++;
                y++;
            }
            x = a - 1;
            y = b - 1;
            while (x >= 0 && y >= 0 && arr[a, b] == arr[x, y])
            {
                count = count + 1;
                x--;
                y--;
            }
            return (count == 5) ? true : false;
        }
        public bool kt_CheoPhu(int a, int b)
        {
            int count = 1;
            int x = a + 1;
            int y = b - 1;
            while (x < c && y >= 0 && arr[a, b] == arr[x, y])
            {
                count++;
                x++;
                y--;
            }
            x = a - 1;
            y = b + 1;
            while (x >= 0 && y < r && arr[a, b] == arr[x, y])
            {
                count++;
                x--;
                y++;
            }
            return (count == 5) ? true : false;
        }
        public bool Total_Check(int x, int y)
        {
            if (kt_Ngang(x, y) == true || kt_Doc(x, y) == true || kt_Cheo(x, y) == true || kt_CheoPhu(x, y))
                 
                return true;
            return false;
        }
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void newFToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            this.notifyIcon1.Icon = Properties.Resources.Icon1;
        }
 
        private void showToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Show();
        }
        private void exitToolStripMenuItem2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void hideToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.Hide();
        }      
    }
}    
