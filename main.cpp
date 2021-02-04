/* Viết chương trình tìm và in ra số lượng, giá trị và vị trí của tất cả các phần tử cực trị trong mảng số nguyên
bất kỳ và tính tổng tất cả các giá trị đó */

#include<iostream>
using namespace std;

void fNhapMang(int a[][10], int& m, int& n);
void fXuatMang(int a[][10], int& m, int& n);
void fCucTriCucDai(int a[][10], int& m, int& n, int x[], int y[], int& count1, int* ctMax, int* p1, int* q1);
void fCucTriCucTieu(int a[][10], int& m, int& n, int x[], int y[], int& count2, int* ctMin, int* p2, int* q2);
void fXuatGiaTri(int* ctMax, int* ctMin, int& count1, int& count2, int* p1, int* q1, int* p2, int* q2);
int fTongCacCucTri(int* ctMax, int* ctMin, int& count1, int& count2, int& sum);

int main()
{
	int a[10][10], m = 0, n = 0, count1 = 0, count2 = 0, * ctMax, * ctMin, * p1, * q1, * p2, * q2;
	int x[] = { -1,-1,-1,0,1,1,1,0 }, y[] = { -1,0,1,1,1,0,-1,-1 };
	ctMax = new int; ctMin = new int; 
	p1 = new int; p2 = new int; q1 = new int; q2 = new int;
	fNhapMang(a, m, n);
	fXuatMang(a, m, n);
	fCucTriCucDai(a, m, n, x, y, count1, ctMax, p1, q1);
	fCucTriCucTieu(a, m, n, x, y, count2, ctMin, p2, q2);
	fXuatGiaTri(ctMax, ctMin, count1, count2, p1, q1, p2, q2);
	int sum = 0;
	sum = fTongCacCucTri(ctMax, ctMin, count1, count2, sum);
	cout << endl;
	cout << "Tong cac phan tu cuc tri trong mang la: " << sum << endl;
	return 0;
}

void fNhapMang(int a[][10], int& m, int& n)
{
	cout << "Nhap so dong: "; cin >> m;
	cout << "Nhap so cot: "; cin >> n;
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void fXuatMang(int a[][10], int& m, int& n)
{
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void fCucTriCucDai(int a[][10], int& m, int& n, int x[], int y[], int& count1, int* ctMax, int* p1, int* q1)
{
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			int max = a[i][j];
			for (int k = 0; k <= 7; k++)
			{
				if ((i + x[k]) < 0 || (j + y[k]) < 0 || (i + x[k]) >= m || (j + y[k]) >= n)
				{
					if (k == 7)
					{
						ctMax[count1] = a[i][j];
						p1[count1] = i; q1[count1] = j;
						count1 = count1 + 1;
					}
					continue;
				}
				else
				{
					int kt = max - a[i + x[k]][j + y[k]];
					if (kt <= 0) { break; }
					else
					{
						if (k == 7)
						{
							ctMax[count1] = a[i][j];
							p1[count1] = i; q1[count1] = j;
							count1 = count1 + 1;
						}
					}
				}
			}
		}
	}
}
void fCucTriCucTieu(int a[][10], int& m, int& n, int x[], int y[], int& count2, int* ctMin, int* p2, int* q2)
{
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			int min = a[i][j];
			for (int k = 0; k <= 7; k++)
			{
				if ((i + x[k]) < 0 || (j + y[k]) < 0 || (i + x[k]) >= m || (j + y[k]) >= n)
				{
					if (k == 7)
					{
						ctMin[count2] = a[i][j];
						p2[count2] = i; q2[count2] = j;
						count2 = count2 + 1;
					}
					continue;
				}
				else
				{
					int kt = min - a[i + x[k]][j + y[k]];
					if (kt >= 0) { break; }
					else
					{
						if (k == 7)
						{
							ctMin[count2] = a[i][j];
							p2[count2] = i; q2[count2] = j;
							count2 = count2 + 1;
						}
					}
				}
			}
		}
	}
}
void fXuatGiaTri(int* ctMax, int* ctMin, int& count1, int& count2, int* p1, int* q1, int* p2, int* q2)
{
	cout << "Mang co tong cong " << count1 + count2 << " cuc tri " << endl;
	cout << "Gom " << count1 << " cuc dai va " << count2 << " cuc tieu" << endl;
	cout << endl;
	cout << "Cuc dai: " << endl;
	if (count1 == 1)
	{
		cout << "Cuc dai co gia tri la " << ctMax[0] << " nam o vi tri " << p1[0] << "x" << q1[0] << endl;
	}
	else 
	{
		for (int i = 0; i <= count1 - 1; i++)
		{
			cout << "Cuc dai thu " << i + 1 << " co gia tri " << ctMax[i] << " nam o vi tri " << p1[i] << "x" << q1[i] << endl;
		}
	}
	cout << endl;
	cout << "Cuc tieu: " << endl;
	if (count2 == 1)
	{
		cout << "Cuc tieu co gia tri la " << ctMin[0] << " nam o vi tri " << p2[0] << "x" << q2[0] << endl;
	}
	else
	{
		for (int i = 0; i <= count2 - 1; i++)
		{
			cout << "Cuc tieu thu " << i + 1 << " co gia tri " << ctMin[i] << " nam o vi tri " << p2[i] << "x" << q2[i] << endl;
		}
	}
	
}
int fTongCacCucTri(int* ctMax, int* ctMin, int& count1, int& count2, int& sum)
{
	for (int i = 0; i <= count1 - 1; i++)
	{
		sum = sum + ctMax[i];
	}
	for (int i = 0; i <= count2 - 1; i++)
	{
		sum = sum + ctMin[i];
	}
	return sum;
}