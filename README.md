#  Quản Lý Thông Tin Khóa Học

> **Bài tập lớn môn Nhập môn Lập trình**  
> Đề tài 5: Quản lý thông tin khóa học

---

##  Mô tả

Chương trình quản lý thông tin khóa học sử dụng **Danh sách liên kết đôi (Doubly Linked List)** tự xây dựng và **Lập trình hướng đối tượng (OOP)** trong C++.

---

##  Chức năng

| STT | Chức năng | Mô tả |
|:---:|-----------|-------|
| 1 | Thêm khóa học | Thêm mới với kiểm tra trùng mã, tín chỉ > 0, SV >= 0 |
| 2 | Hiển thị tất cả | In danh sách khóa học dạng bảng |
| 3 | Tìm kiếm | Tìm theo mã khóa học |
| 4 | Thống kê Max | Khóa học có nhiều SV đăng ký nhất |
| 5 | Thống kê Min | Khóa học có ít SV đăng ký nhất |
| 0 | Thoát | Thoát chương trình |

---

##  Cấu trúc dự án

```
nhapmonlt/
├── Course.h              # Header - Lớp Khóa học
├── Course.cpp            # Implementation - Lớp Khóa học
├── Node.h                # Header - Cấu trúc Node (prev, next)
├── DoublyLinkedList.h    # Header - Lớp Danh sách liên kết đôi
├── DoublyLinkedList.cpp  # Implementation - Danh sách liên kết đôi
├── Utils.h               # Header - Các hàm tiện ích giao diện
├── Utils.cpp             # Implementation - Các hàm tiện ích
├── main.cpp              # File chính - Hàm main()
├── Makefile              # File tự động hóa biên dịch
├── .gitignore            # Danh sách file Git bỏ qua
└── README.md             # File hướng dẫn (file này)
```

---

##  Cài đặt và Chạy

### Yêu cầu
- Trình biên dịch C++ (g++ hoặc tương đương)
- Hỗ trợ C++11 trở lên

### Tải mã nguồn

**Cách 1: Clone từ Git**
```bash
git clone https://github.com/HoangTuBangGia/nhapmonlt.git
cd nhapmonlt
```

**Cách 2: Tải file ZIP**
1. Nhấn nút **Code** → **Download ZIP** trên GitHub
2. Giải nén file `nhapmonlt-main.zip`
3. Mở terminal và di chuyển vào thư mục:
```bash
cd nhapmonlt-main
```

### Biên dịch và chạy

```bash
# Biên dịch
make

# Biên dịch và chạy chương trình
make run

# Hoặc chỉ chạy (không biên dịch lại)
make exec
```

### Các lệnh Make khác

| Lệnh | Mô tả |
|------|-------|
| `make` | Biên dịch chương trình |
| `make run` | Biên dịch (nếu cần) + chạy |
| `make exec` | Chỉ chạy file đã biên dịch |
| `make clean` | Xóa file .o, giữ file thực thi |
| `make cleanall` | Xóa tất cả file biên dịch |
| `make rebuild` | Biên dịch lại từ đầu |

---

##  Cấu trúc dữ liệu

### Danh sách liên kết đôi (Doubly Linked List)

```
nullptr <── [Node1] ←→ [Node2] ←→ [Node3] ──> nullptr
              ↑                       ↑
            head                    tail
```

Mỗi **Node** gồm:
- `data`: Đối tượng Course (khóa học)
- `prev`: Con trỏ đến Node trước
- `next`: Con trỏ đến Node sau

### Lớp Course (Khóa học)

| Thuộc tính | Kiểu | Mô tả |
|------------|------|-------|
| `courseId` | string | Mã khóa học (duy nhất) |
| `courseName` | string | Tên khóa học |
| `credits` | int | Số tín chỉ (> 0) |
| `studentCount` | int | Số SV đăng ký (>= 0) |

---

##  Giao diện

Chương trình có giao diện console đẹp với:
- ✅ Bảng dữ liệu thẳng hàng (dùng `iomanip`)
- ✅ Khung viền Unicode
- ✅ Tiêu đề nổi bật cho mỗi chức năng
- ✅ Xóa màn hình khi chuyển menu
- ✅ Dừng màn hình để đọc kết quả

---

