CHƯƠNG TRÌNH QUẢN LÍ NHÂN VIÊN
	Giả sử chương trình quản lí nhân viên kế toán trong cơ quan Nhà nước lưu trữ nội dung các thông tin dạng cấu trúc gồm :
-	Mã NV
-	Tên nhân viên
-	Chức vụ
-	Hệ số lương
-	Mức lương
-	Phụ cấp chức vụ
-	Lương
-	Thực Lĩnh

	Có các đối tượng kế toán sau : 

-	Kế toán viên cao cấp (CC)
-	Kế toán viên chính (C)
-	Kế toán viên (KTV)
-	Kế toán viên trung cấp (TC)
-	Kế toán viên sơ cấp (SC)

	Phụ cấp chức vụ được xác định như sau :

-	Nếu là kế toán viên cao cấp được phụ cấp : 1 500 000
-	Nếu là kế toán viên cao chính được phụ cấp : 1 200 000
-	Nếu là kế toán viên được phụ cấp : 1 000 000
-	Nếu là kế toán viên trung cấp cấp được phụ cấp :  700 000
-	Nếu là kế toán viên sơ cấp được phụ cấp : 300 000

	Chương trình có thể giải quyết các công việc sau :

1)	Tạo một danh sách nhân viên từ tệp input.txt gồm các thông tin của nhân viên là : Mã NV, Tên nhân viên, Chức vụ, Hệ số lương, Mức lương.
File có dạng mẫu như sau : (trong đó N là số nhân viên)
N
MaNV_1;TenNV_1;ChucVu_1;HeSoLuong_1;MucLuong_1
MaNV_2;TenNV_2;ChucVu_2;HeSoLuong_2;MucLuong_2
MaNV_3;TenNV_3;ChucVu_3;HeSoLuong_3;MucLuong_3
...
2)	Tính lương cho các nhân viên với công thức : Lương = Hệ số lương * Mức lương*1 000 000 và thực lĩnh = lương + phụ cấp chức vụ.
3)	In ra màn hình danh sách nhân viên với đầy đủ thông tin.
4)	Sắp xếp nhân viên theo chức vụ giảm dần(nếu cùng chức vụ thì sắp theo thứ tự AlphaBeta của tên) và in ra danh sách sau khi sắp xếp.
5)	In ra màn hình danh sách nhân viên có chức vụ là XX (XX được nhập từ bàn phím)
6)	Thêm một nhân viên vào danh sách nhân viên sao cho vẫn đảm bảo thứ tự sắp xếp
7)	Xóa một nhân viên bất kỳ (bằng mã nhân viên được nhập từ bàn phím).
8)	Thay đổi chức vụ cho một nhân viên. (Nhập chức vụ, hệ số lương, mức lương mới vào, ta sẽ tính lại lương và thực lĩnh cho nhân viên đấy luôn)
9)	Lưu danh sách nhân viên ra tệp output.txt 
File có dạng mẫu như sau : (trong đó N là số nhân viên)
N
MaNV_1;TenNV_1;ChucVu_1;HeSoLuong_1;MucLuong_1;PhuCap_1;Luong_1;ThucLinh_1
MaNV_2;TenNV_2;ChucVu_2;HeSoLuong_2;MucLuong_2;PhuCap_2;Luong_2;ThucLinh_2
MaNV_3;TenNV_3;ChucVu_3;HeSoLuong_3;MucLuong_3;PhuCap_3;Luong_3;ThucLinh_3
...

