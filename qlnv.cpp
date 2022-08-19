#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<math.h>
#include<iomanip>
using namespace std;

struct ThongTin {
	char* MaNV;
	char* Ten;
	char* ChucVu;
	float HeSoLuong;
	float MucLuong;
	int PhuCapChucVu;
	float Luong;
	float ThucLinh;
};

struct NV {
	ThongTin tt;
	NV* next;
};

struct DSNV {
	NV* head;
	NV* tail;
	int sonv;
};

NV* TaoMotNhanVien(ThongTin tt);
void ThemVaoCuoiDanhSach(DSNV& d, ThongTin tt);
int PhuCap(char ChucVu[]);
void TaoDSNV(DSNV& d);
void TinhTienLuongChoCacNhanVien(DSNV& d);
void InRaDSNV(DSNV d);
int QuyDoiChucVu(char ChucVu[]);
int CountCharacter(char* s);
string* PhanTachTu(char* str, int n);
int checkAlphaBeta(char* str1, char* str2);
void Push(DSNV& d, ThongTin tt);
NV* getTail(NV* cur);
NV* partition(NV* l, NV* r, DSNV& new_left, DSNV& new_right);
NV* QuickSort_Recur(NV* l, NV* r);
void quickSort(DSNV& head);
void InRaDSNVChucVuXX(DSNV d);
void ThemMotNhanVien(DSNV& d);
void XoaMotNhanVien(DSNV& d);
void ThayDoiChucVu(DSNV& d);
void LuuDSNV(DSNV d);

NV* TaoMotNhanVien(ThongTin tt) {
	NV* NV_moi = new NV;
	if (NV_moi == NULL)return NULL;
	NV_moi->tt = tt;
	NV_moi->next = NULL;
	return NV_moi;
}

void ThemVaoCuoiDanhSach(DSNV& d, ThongTin tt) {
	NV* p = TaoMotNhanVien(tt);
	if (d.head == NULL) {
		d.head = p;
		d.tail = p;
	}
	else {
		d.tail->next = p;
		d.tail = p;
	}
}

int PhuCap(char ChucVu[]) {
	if (strcmp(ChucVu, "CC") == 0) {
		return 1500000;
	}
	else if (strcmp(ChucVu, "C") == 0) {
		return 1200000;
	}
	else if (strcmp(ChucVu, "KTV") == 0) {
		return 1000000;
	}
	else if (strcmp(ChucVu, "TC") == 0) {
		return 700000;
	}
	else {
		return 300000;
	}
}

void TaoDSNV(DSNV& d) {
	ifstream ifs;
	ifs.open("input.txt");
	string s;
	ThongTin tt;
	getline(ifs, s);
	d.sonv = stoi(s,0,10);
	int i = 0;
	while (!ifs.eof()) {
		getline(ifs, s, ';');
		tt.MaNV = _strdup(s.c_str());
		getline(ifs, s, ';');
		tt.Ten = _strdup(s.c_str());
		getline(ifs, s, ';');
		tt.ChucVu = _strdup(s.c_str());
		getline(ifs, s, ';');
		tt.HeSoLuong = stof(s);
		getline(ifs, s);
		tt.MucLuong = stof(s);
		tt.PhuCapChucVu = PhuCap(tt.ChucVu);
		ThemVaoCuoiDanhSach(d, tt);
		i++;
	}
	ifs.close();
}

void TinhTienLuongChoCacNhanVien(DSNV& d) {
	for (NV* p = d.head; p; p = p->next) {
		p->tt.Luong = p->tt.HeSoLuong * p->tt.MucLuong * 1000000;
		p->tt.ThucLinh = p->tt.Luong + p->tt.PhuCapChucVu;
	}
}

void InRaDSNV(DSNV d) {
	int i = 1;
	cout << setw(5) << "STT" << setw(15) << "Ma nhan vien" << setw(51) << "Ten nhan vien"
		<< setw(8) << "Chuc vu" << setw(7) << "HSL" << setw(10) << "Muc luong"
		<< setw(12) << "PCCV" << setw(15) << "Luong" << setw(15) << "Thuc linh" << endl;
	for (NV* p = d.head; p; p = p->next) {
		cout << setw(5) << i << setw(15) << p->tt.MaNV << setw(51) << p->tt.Ten
			<< setw(8) << p->tt.ChucVu << setprecision(2) <<fixed<< setw(7) << p->tt.HeSoLuong 
			<< setprecision(4) << setw(10) << p->tt.MucLuong
			<< setw(12) << p->tt.PhuCapChucVu;
		cout << setprecision(0) << fixed << setw(15) << p->tt.Luong << setw(15) << p->tt.ThucLinh << endl;
		i++;
 	}
}

int QuyDoiChucVu(char ChucVu[]) {
	if (strcmp(ChucVu, "CC") == 0) {
		return 1;
	}
	else if (strcmp(ChucVu, "C") == 0) {
		return 2;
	}
	else if (strcmp(ChucVu, "KTV") == 0) {
		return 3;
	}
	else if (strcmp(ChucVu, "TC") == 0) {
		return 4;
	}
	else if( strcmp(ChucVu, "SC") == 0) {
		return 5;
	}
	else {
		return 0;
	}
}

int CountCharacter(char* s) {
	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')cnt++;
	}
	cnt++;
	return cnt;
}

string* PhanTachTu(char* str, int n) {
	string* A = new string[n];
	int cnt = 0, id = 0;
	string s;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != ' ') {
			s += str[i];
			if (i == strlen(str) - 1) {
				A[cnt] = _strdup(s.c_str());
				break;
			}
		}
		else {
			A[cnt] = _strdup(s.c_str());
			s = "";
			cnt++;
		}
	}
	return A;
}

int checkAlphaBeta(char* str1, char* str2) {
	int n1 = CountCharacter(str1), n2 = CountCharacter(str2);

	string* s1 = PhanTachTu(str1, n1);
	string* s2 = PhanTachTu(str2, n2);
	int _break = 0;
	while (n1 > 0 && n2 > 0) {
		if (s1[n1 - 1] < s2[n2 - 1]) {
			return -1;
		}
		else if (s1[n1 - 1] > s2[n2 - 1]) {
			return 1;
		}
		else {
			n1--;
			n2--;
		}
	}
	return 0;
}

void Push(DSNV& d,ThongTin tt) {
	NV* p = new NV;
	if (p == NULL) return;
	if (d.head == NULL) {
		d.tail = p;
		d.head = p;
	}
	else {
		p->tt = tt;
		p->next = d.head;
		d.head = p;
	}
}

NV* getTail(NV* cur) {
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

NV* partition(NV* l, NV* r, DSNV& new_left, DSNV& new_right) {
	NV* pivot = r;
	NV* prev = NULL, * cur = l, * tail = pivot;

	while (cur != pivot) {
		int data_cur = QuyDoiChucVu(cur->tt.ChucVu);
		int data_pivot = QuyDoiChucVu(pivot->tt.ChucVu);
		if (data_cur <= data_pivot) {
			if (data_cur < data_pivot) {
				if (new_left.head == NULL)
					new_left.head = cur;
				prev = cur;
				cur = cur->next;
			}
			else {
				if (checkAlphaBeta(cur->tt.Ten, pivot->tt.Ten) < 0) {
					if (new_left.head == NULL)
						new_left.head = cur;
					prev = cur;
					cur = cur->next;
				}
				else {
					if (prev) prev->next = cur->next;
					NV* tmp = cur->next;
					cur->next = NULL;
					tail->next = cur;
					tail = cur;
					cur = tmp;
				}
			}
		}
		else 
		{
			if (prev) prev->next = cur->next;
			NV* tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	if (new_left.head == NULL)
		new_left.head = pivot;
	new_right.head = tail;
	return pivot;
}

NV* QuickSort_Recur(NV* l, NV* r) {
	if (l == NULL || l == r) return l;
	DSNV new_left, new_right;
	new_left.head = NULL, new_right.head = NULL;
	NV* pivot = partition(l, r, new_left, new_right);

	if (new_left.head != pivot) {

		NV* temp = new_left.head;
		while (temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;
		new_left.head = QuickSort_Recur(new_left.head, temp);
		temp = getTail(new_left.head);
		temp->next = pivot;
	}

	pivot->next = QuickSort_Recur(pivot->next, new_right.head);

	return new_left.head;
}

void quickSort(DSNV& head) {
	head.head = QuickSort_Recur(head.head, getTail(head.head));
	return;
}

void InRaDSNVChucVuXX(DSNV d) {
	int i = 1;
	DSNV tmp = d;
	quickSort(tmp);
	char ChucVu[4];
	cout << "Nhap vao chuc vu : ";
	cin >> ChucVu;
	int c = QuyDoiChucVu(ChucVu);
	while (c == 0) {
		cout << "Vui long nhap lai chuc vu cho dung : ";
		cin >> ChucVu;
		c = QuyDoiChucVu(ChucVu);
	}
	cout << setw(5) << "STT" << setw(15) << "Ma nhan vien" << setw(51) << "Ten nhan vien"
		<< setw(8) << "Chuc vu" << setw(7) << "HSL" << setw(10) << "Muc luong"
		<< setw(12) << "PCCV" << setw(15) << "Luong" << setw(15) << "Thuc linh" << endl;
	for (NV* p = tmp.head; p; p = p->next) {
		int p_tmp = QuyDoiChucVu(p->tt.ChucVu);
		if (c == p_tmp) {
			cout << setw(5) << i << setw(15) << p->tt.MaNV << setw(51) << p->tt.Ten
				<< setw(8) << p->tt.ChucVu << setprecision(2) << fixed << setw(7) << p->tt.HeSoLuong 
				<< setprecision(4) << fixed << setw(10) << p->tt.MucLuong
				<< setw(12) << p->tt.PhuCapChucVu << setprecision(0) << fixed << setw(15) << p->tt.Luong << setw(15) << p->tt.ThucLinh << endl;
			i++;
		}
		else if (p_tmp > c)break;
	}
}

void ThemMotNhanVien(DSNV& d) {
	ThongTin t;
	string s;
	cout << "Nhap vao Ma nhan vien : ";
	cin >> s;
	t.MaNV = _strdup(s.c_str());
	cin.ignore();
	cout << "Nhap vao Ten nhan vien : ";
	getline(cin, s);
	t.Ten = _strdup(s.c_str());
	cout << "Nhap vao Chuc vu : ";
	cin >> s;
	t.ChucVu = _strdup(s.c_str());
	int c = QuyDoiChucVu(t.ChucVu);
	while (c == 0) {
		cout << "Vui long nhap lai chuc vu cho dung : ";
		cin >> s;
		t.ChucVu = _strdup(s.c_str());
		c = QuyDoiChucVu(t.ChucVu);
	}
	cout << "Nhap vao He so luong : ";
	cin >> t.HeSoLuong;
	cout << "Nhap vao Muc luong : ";
	cin >> t.MucLuong;
	t.Luong = t.HeSoLuong * t.MucLuong * 1000000;
	t.PhuCapChucVu = PhuCap(t.ChucVu);
	t.ThucLinh = t.Luong + t.PhuCapChucVu;
	NV* prev = NULL;
	NV* insert = TaoMotNhanVien(t);
	bool flag = false;
	for (NV* p = d.head; p; p = p->next) {
		int p_tmp = QuyDoiChucVu(p->tt.ChucVu);
		int prev_tmp = 10;
		if (prev != NULL) {
			prev_tmp = QuyDoiChucVu(prev->tt.ChucVu);
		}
		else {
			if ( c==p_tmp && checkAlphaBeta(t.Ten, p->tt.Ten) < 0) {
				insert->next = d.head;
				d.head = insert;
				d.sonv++;
				break;
			}
		}
		if (c >= prev_tmp && c <= p_tmp) {
			bool ok = false;
			if (c == prev_tmp && c == p_tmp) {
				if ((checkAlphaBeta(t.Ten, prev->tt.Ten) > 0 && checkAlphaBeta(t.Ten, p->tt.Ten) < 0)) {
					ok = true;
				}
			}
			else if (c == prev_tmp && c < p_tmp) {
				ok = true;
			}
			else if (c > prev_tmp && c == p_tmp) {
				if (checkAlphaBeta(t.Ten, p->tt.Ten) < 0) ok = true;
			}
			if (ok) {
				insert->next = p;
				prev->next = insert;
				flag = true;
				d.sonv++;
				break;
			}
		}
		prev = p;
	}
	if (prev == NULL) {
		if (d.head == NULL) {
			d.head = insert;
		}
		else {
			if (c > QuyDoiChucVu(d.head->tt.ChucVu)) {
				d.head->next = insert;
			}
			else if (c < QuyDoiChucVu(d.head->tt.ChucVu)) {
				insert->next = d.head;
				d.head = insert;
			}
		}
		flag = true;
		d.sonv++;
	}
	if (flag == false) {
		prev->next = insert;
		d.tail = insert;
		flag = true;
		d.sonv++;
	}
}

void XoaMotNhanVien(DSNV& d) {
	string s;
	cout << "Nhap vao ma nhan vien : ";
	cin >> s;
	NV* del = NULL;
	NV* prev = NULL;
	for (NV* p = d.head; p; p = p->next) {
		if (strcmp(p->tt.MaNV, s.c_str()) == 0) {
			del = p;
			break;
		}
		else {
			prev = p;
		}
	}
	if (del != NULL) {
		if (del == d.head) {
			NV* tmp = d.head;
			d.head = d.head->next;
			delete tmp;
		}
		else {
			NV* tmp = del;
			prev->next = del->next;
			delete tmp;
		}
		d.sonv--;
	}
}

void ThayDoiChucVu(DSNV& d) {
	string s;
	cout << "Nhap vao ma nhan vien muon thay doi chuc vu : ";
	cin >> s;
	NV* want = NULL;
	for (NV* p = d.head; p; p = p->next) {
		if (strcmp(p->tt.MaNV, s.c_str()) == 0) {
			want = p;
			break;
		}
	}
	if (want) {
		cout << "Nhap chuc vu sau thay doi : ";
		cin >> s;
		strcpy(want->tt.ChucVu, s.c_str());
		int c = QuyDoiChucVu(want->tt.ChucVu);
		while (c == 0) {
			cout << "Vui long nhap lai chuc vu cho dung : ";
			cin >> s;
			strcpy(want->tt.ChucVu, s.c_str());
			c = QuyDoiChucVu(want->tt.ChucVu);
		}
		cout << "Nhap he so luong sau thay doi : ";
		cin >> want->tt.HeSoLuong;
		cout << "Nhap muc luong sau thay doi : ";
		cin >> want->tt.MucLuong;
		want->tt.Luong = want->tt.HeSoLuong * want->tt.MucLuong * 1000000;
		want->tt.PhuCapChucVu = PhuCap(want->tt.ChucVu);
		want->tt.ThucLinh = want->tt.Luong + want->tt.PhuCapChucVu;
	}
}

void LuuDSNV(DSNV d) {
	ofstream ofs;
	ofs.open("output.txt");
	ofs << d.sonv << endl;
	for (NV* p = d.head;p; p=p->next) {
		ofs << p->tt.MaNV << ";" << p->tt.Ten << ";" << p->tt.ChucVu << ";" << p->tt.HeSoLuong << ";"
			<< p->tt.MucLuong << ";" << p->tt.PhuCapChucVu << ";" << p->tt.Luong << ";" << p->tt.ThucLinh << endl;
	}
	ofs.close();
}

int main() {
	DSNV d;
	d.head = NULL;
	d.tail = NULL;
	int choice = 0, _continue = 1;
	while (_continue == 1) {
		cout << "----------------------------------------QUAN LI NHAN VIEN----------------------------------------" << endl;
		cout << "1. Tao mot danh sach nhan vien tu tep input.txt" << endl;
		cout << "2. Tinh luong va thuc linh cho cac nhan vien" << endl;
		cout << "3. In ra man hinh danh sach nhan vien voi day du thong tin" << endl;
		cout << "4. Sap xep danh sach nhan vien theo chuc vu giam dan (neu cung chuc vu thi sap xep theo AlphaBeta cua ten)" << endl;
		cout << "5. In ra man hinh danh sach sinh vien co chuc vu XX" << endl;
		cout << "6. Them mot nhan vien vao danh sach nhan vien sao cho van dam bao thu tu sap xep" << endl;
		cout << "7. Xoa mot nhan vien bat ky" << endl;
		cout << "8. Thay doi chuc vu cho mot nhan vien" << endl;
		cout << "9. Luu danh sach nhan vien ra tep output.txt" << endl;
		cout << "Nhap vao chuc nang ban muon (1->9) : ";
		cin >> choice;
		while (choice < 1 || choice>9) {
			cout << "Vui long nhap lai (1->9) : ";
			cin >> choice;
		}
		switch (choice) {
		case 1: {
			TaoDSNV(d);
			break;
		}
		case 2: {
			TinhTienLuongChoCacNhanVien(d);
			break;
		}
		case 3: {
			InRaDSNV(d);
			break;
		}
		case 4: {
			quickSort(d);
			break;
		}
		case 5: {
			InRaDSNVChucVuXX(d);
			break;
		}
		case 6: {
			ThemMotNhanVien(d);
			break;
		}
		case 7: {
			XoaMotNhanVien(d);
			break;
		}
		case 8: {
			ThayDoiChucVu(d);
			break;
		}
		case 9: {
			LuuDSNV(d);
			break;
		}
		}
		cout << "Ban co muon tiep tuc thuc hien cac chuc nang khac khong ? (1-Co,2-Khong) : ";
		cin >> _continue;
		while (_continue < 1 || _continue>2) {
			cout << "Vui long nhap lai (1->2) : ";
			cin >> _continue;
		}
	}
	return 0;
}