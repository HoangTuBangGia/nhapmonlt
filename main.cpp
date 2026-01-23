/*
 * ============================================================================
 * BÀI TẬP LỚN: QUẢN LÝ THÔNG TIN KHÓA HỌC
 * Môn học: Nhập môn Lập trình
 * Đề tài 5: Quản lý thông tin khóa học
 * ============================================================================
 * File: main.cpp
 * Mô tả: File chính chứa hàm main và các chức năng xử lý menu
 * ============================================================================
 * Cấu trúc dự án:
 *   - Course.h / Course.cpp       : Lớp Khóa học
 *   - Node.h                      : Cấu trúc Node cho danh sách liên kết đôi
 *   - DoublyLinkedList.h / .cpp   : Lớp Danh sách liên kết đôi
 *   - Utils.h / Utils.cpp         : Các hàm tiện ích (giao diện)
 *   - main.cpp                    : File chính
 * ============================================================================
 */

#include <iostream>
#include <limits>
#include "Course.h"
#include "Node.h"
#include "DoublyLinkedList.h"
#include "Utils.h"

using namespace std;

// ============================================================================
// PHẦN 1: CÁC HÀM CHỨC NĂNG CHÍNH
// ============================================================================

/*
 * Hàm: addNewCourse(DoublyLinkedList& list)
 * Mục đích: Thêm một khóa học mới vào danh sách
 * Tham số: list - Tham chiếu đến danh sách khóa học
 * 
 * LOGIC:
 * 1. Nhập mã khóa học, kiểm tra trùng lặp
 * 2. Nhập tên khóa học
 * 3. Nhập số tín chỉ, kiểm tra > 0
 * 4. Nhập số SV đăng ký, kiểm tra >= 0
 * 5. Tạo đối tượng Course và thêm vào danh sách
 */
void addNewCourse(DoublyLinkedList& list) {
    clearScreen();
    printHeader("THEM KHOA HOC MOI");

    string courseId, courseName;
    int credits, studentCount;

    // ========================================================================
    // Bước 1: Nhập và kiểm tra mã khóa học (không được trùng)
    // ========================================================================
    while (true) {
        cout << "    Nhap ma khoa hoc: ";
        getline(cin, courseId);
        
        // Kiểm tra không được để trống
        if (courseId.empty()) {
            cout << "    [!] Loi: Ma khoa hoc khong duoc de trong!\n";
            continue;
        }
        
        // Kiểm tra trùng lặp
        if (list.isIdExist(courseId)) {
            cout << "    [!] Loi: Ma khoa hoc '" << courseId << "' da ton tai!\n";
            cout << "    Vui long nhap ma khac.\n\n";
            continue;
        }
        
        break;  // Mã hợp lệ, thoát vòng lặp
    }

    // ========================================================================
    // Bước 2: Nhập tên khóa học
    // ========================================================================
    while (true) {
        cout << "    Nhap ten khoa hoc: ";
        getline(cin, courseName);
        
        if (courseName.empty()) {
            cout << "    [!] Loi: Ten khoa hoc khong duoc de trong!\n";
            continue;
        }
        break;
    }

    // ========================================================================
    // Bước 3: Nhập và kiểm tra số tín chỉ (phải > 0)
    // ========================================================================
    while (true) {
        cout << "    Nhap so tin chi (> 0): ";
        
        // Kiểm tra nhập đúng kiểu số nguyên
        if (!(cin >> credits)) {
            cout << "    [!] Loi: Vui long nhap so nguyen!\n";
            cin.clear();  // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Bỏ qua input sai
            continue;
        }
        
        // Kiểm tra giá trị hợp lệ
        if (credits <= 0) {
            cout << "    [!] Loi: So tin chi phai lon hon 0!\n";
            continue;
        }
        
        break;  // Giá trị hợp lệ
    }

    // ========================================================================
    // Bước 4: Nhập và kiểm tra số lượng sinh viên (phải >= 0)
    // ========================================================================
    while (true) {
        cout << "    Nhap so luong sinh vien dang ky (>= 0): ";
        
        if (!(cin >> studentCount)) {
            cout << "    [!] Loi: Vui long nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (studentCount < 0) {
            cout << "    [!] Loi: So luong sinh vien phai >= 0!\n";
            continue;
        }
        
        break;
    }

    // ========================================================================
    // Bước 5: Tạo đối tượng Course và thêm vào danh sách liên kết đôi
    // ========================================================================
    Course newCourse(courseId, courseName, credits, studentCount);
    list.addCourse(newCourse);

    // Thông báo thành công
    cout << "\n";
    cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
    cout << "    ║     [✓] DA THEM KHOA HOC THANH CONG!                         ║\n";
    cout << "    ╚══════════════════════════════════════════════════════════════╝\n";

    pauseScreen();
}

/*
 * Hàm: displayAllCourses(DoublyLinkedList& list)
 * Mục đích: Hiển thị tất cả khóa học trong danh sách dạng bảng
 * Tham số: list - Tham chiếu đến danh sách khóa học
 * 
 * GIẢI THÍCH LOGIC DUYỆT DANH SÁCH:
 * - Bắt đầu từ head (Node đầu tiên)
 * - In thông tin Node hiện tại
 * - Di chuyển đến Node tiếp theo bằng con trỏ next
 * - Dừng khi current = nullptr (đã qua Node cuối)
 */
void displayAllCourses(const DoublyLinkedList& list) {
    clearScreen();
    printHeader("DANH SACH TAT CA KHOA HOC");

    // Kiểm tra danh sách rỗng
    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    // In thông tin tổng số khóa học
    cout << "    >> Tong so khoa hoc: " << list.getSize() << "\n\n";

    // In tiêu đề bảng
    printTableHeader();

    // Duyệt và in từng khóa học
    // LOGIC CON TRỎ:
    // current bắt đầu từ head, sau mỗi lần in, current di chuyển sang next
    Node* current = list.getHead();  // Lấy Node đầu tiên
    
    while (current != nullptr) {
        // In thông tin khóa học trong Node hiện tại
        printTableRow(current->data);
        
        // Di chuyển đến Node tiếp theo thông qua con trỏ next
        // Nếu current->next là nullptr, nghĩa là đã đến Node cuối
        current = current->next;
    }

    // In đường kẻ cuối bảng
    printTableFooter();

    pauseScreen();
}

/*
 * Hàm: searchCourse(DoublyLinkedList& list)
 * Mục đích: Tìm kiếm khóa học theo mã
 * Tham số: list - Tham chiếu đến danh sách khóa học
 */
void searchCourse(const DoublyLinkedList& list) {
    clearScreen();
    printHeader("TIM KIEM KHOA HOC");

    // Kiểm tra danh sách rỗng
    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    string searchId;
    cout << "    Nhap ma khoa hoc can tim: ";
    getline(cin, searchId);

    // Tìm kiếm trong danh sách
    Node* result = list.findById(searchId);

    if (result != nullptr) {
        // Tìm thấy - Hiển thị kết quả
        cout << "\n";
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║              [✓] TIM THAY KHOA HOC!                          ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        cout << "\n";
        
        printTableHeader();
        printTableRow(result->data);
        printTableFooter();
    } else {
        // Không tìm thấy
        cout << "\n";
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║     [!] KHONG TIM THAY khoa hoc voi ma da nhap!              ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
    }

    pauseScreen();
}

/*
 * Hàm: showMaxStudentCourses(DoublyLinkedList& list)
 * Mục đích: Hiển thị (các) khóa học có số SV đăng ký NHIỀU NHẤT
 * Tham số: list - Tham chiếu đến danh sách khóa học
 * 
 * LOGIC:
 * 1. Tìm giá trị max của số SV đăng ký
 * 2. Duyệt lại danh sách, in ra tất cả khóa học có số SV = max
 *    (Có thể có nhiều khóa học cùng số SV max)
 */
void showMaxStudentCourses(const DoublyLinkedList& list) {
    clearScreen();
    printHeader("THONG KE: KHOA HOC CO NHIEU SV NHAT");

    // Kiểm tra danh sách rỗng
    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    // Lấy giá trị max
    int maxCount = list.getMaxStudentCount();
    
    cout << "    >> So luong sinh vien dang ky nhieu nhat: " << maxCount << "\n\n";
    cout << "    >> Cac khoa hoc co so SV dang ky nhieu nhat:\n\n";

    // In tiêu đề bảng
    printTableHeader();

    // Duyệt danh sách và in các khóa học có số SV = max
    Node* current = list.getHead();
    int count = 0;  // Đếm số khóa học thỏa mãn
    
    while (current != nullptr) {
        if (current->data.getStudentCount() == maxCount) {
            printTableRow(current->data);
            count++;
        }
        current = current->next;
    }

    printTableFooter();
    
    cout << "\n    >> Tong cong: " << count << " khoa hoc\n";

    pauseScreen();
}

/*
 * Hàm: showMinStudentCourses(DoublyLinkedList& list)
 * Mục đích: Hiển thị (các) khóa học có số SV đăng ký ÍT NHẤT
 * Tham số: list - Tham chiếu đến danh sách khóa học
 * 
 * LOGIC: Tương tự hàm showMaxStudentCourses nhưng tìm min
 */
void showMinStudentCourses(const DoublyLinkedList& list) {
    clearScreen();
    printHeader("THONG KE: KHOA HOC CO IT SV NHAT");

    // Kiểm tra danh sách rỗng
    if (list.isEmpty()) {
        cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
        cout << "    ║          [!] Danh sach khoa hoc hien dang trong!             ║\n";
        cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
        pauseScreen();
        return;
    }

    // Lấy giá trị min
    int minCount = list.getMinStudentCount();
    
    cout << "    >> So luong sinh vien dang ky it nhat: " << minCount << "\n\n";
    cout << "    >> Cac khoa hoc co so SV dang ky it nhat:\n\n";

    // In tiêu đề bảng
    printTableHeader();

    // Duyệt danh sách và in các khóa học có số SV = min
    Node* current = list.getHead();
    int count = 0;
    
    while (current != nullptr) {
        if (current->data.getStudentCount() == minCount) {
            printTableRow(current->data);
            count++;
        }
        current = current->next;
    }

    printTableFooter();
    
    cout << "\n    >> Tong cong: " << count << " khoa hoc\n";

    pauseScreen();
}

// ============================================================================
// PHẦN 2: HÀM MAIN - ĐIỂM BẮT ĐẦU CHƯƠNG TRÌNH
// ============================================================================

/*
 * Hàm main():
 * - Tạo danh sách liên kết đôi
 * - Hiển thị menu và xử lý lựa chọn của người dùng
 * - Lặp cho đến khi người dùng chọn thoát (0)
 */
int main() {
    // Tạo đối tượng danh sách liên kết đôi để lưu trữ các khóa học
    DoublyLinkedList courseList;
    
    int choice;  // Biến lưu lựa chọn của người dùng
    
    // ========================================================================
    // Thêm dữ liệu mẫu để test (có thể xóa phần này khi nộp bài)
    // ========================================================================
    courseList.addCourse(Course("CS101", "Nhap mon Lap trinh", 3, 120));
    courseList.addCourse(Course("CS102", "Cau truc Du lieu", 4, 95));
    courseList.addCourse(Course("CS201", "Lap trinh Huong doi tuong", 3, 85));
    courseList.addCourse(Course("CS202", "Co so Du lieu", 4, 120));
    courseList.addCourse(Course("CS301", "Toan roi rac", 3, 75));

    // ========================================================================
    // Vòng lặp menu chính
    // ========================================================================
    do {
        clearScreen();       // Xóa màn hình trước khi hiển thị menu
        printMainMenu();     // Hiển thị menu
        
        // Nhập và kiểm tra lựa chọn
        if (!(cin >> choice)) {
            // Xử lý trường hợp nhập không phải số
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;  // Gán giá trị không hợp lệ để hiển thị thông báo lỗi
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Xóa buffer
        }

        // Xử lý lựa chọn bằng switch-case
        switch (choice) {
            case 1:
                // Chức năng 1: Thêm khóa học mới
                addNewCourse(courseList);
                break;
                
            case 2:
                // Chức năng 2: Hiển thị tất cả khóa học
                displayAllCourses(courseList);
                break;
                
            case 3:
                // Chức năng 3: Tìm kiếm theo mã khóa học
                searchCourse(courseList);
                break;
                
            case 4:
                // Chức năng 4: Thống kê khóa học có nhiều SV nhất
                showMaxStudentCourses(courseList);
                break;
                
            case 5:
                // Chức năng 5: Thống kê khóa học có ít SV nhất
                showMinStudentCourses(courseList);
                break;
                
            case 0:
                // Chức năng 0: Thoát chương trình
                showExitMessage();
                break;
                
            default:
                // Xử lý lựa chọn không hợp lệ
                cout << "\n    [!] Lua chon khong hop le! Vui long nhap lai (0-5).\n";
                cout << "    Nhan Enter de tiep tuc...";
                cin.get();
                break;
        }
        
    } while (choice != 0);  // Lặp cho đến khi chọn thoát

    return 0;  // Kết thúc chương trình thành công
}

/*
 * ============================================================================
 * HƯỚNG DẪN BIÊN DỊCH VÀ CHẠY CHƯƠNG TRÌNH
 * ============================================================================
 * 
 * Cách 1: Biên dịch thủ công bằng g++
 *   g++ -o QuanLyKhoaHoc main.cpp Course.cpp DoublyLinkedList.cpp Utils.cpp -std=c++11
 *   ./QuanLyKhoaHoc
 * 
 * Cách 2: Sử dụng Makefile (nếu có)
 *   make
 *   ./QuanLyKhoaHoc
 * 
 * ============================================================================
 * TÓM TẮT CẤU TRÚC DỮ LIỆU DANH SÁCH LIÊN KẾT ĐÔI
 * ============================================================================
 * 
 * 1. Mỗi Node gồm 3 thành phần:
 *    - data: Dữ liệu (đối tượng Course)
 *    - prev: Con trỏ trỏ đến Node trước
 *    - next: Con trỏ trỏ đến Node sau
 * 
 * 2. Danh sách có 2 con trỏ đặc biệt:
 *    - head: Trỏ đến Node đầu tiên
 *    - tail: Trỏ đến Node cuối cùng
 * 
 * 3. Thao tác thêm Node vào cuối (addCourse):
 *    - newNode->prev = tail    (Node mới trỏ ngược về tail cũ)
 *    - tail->next = newNode    (tail cũ trỏ xuôi đến Node mới)
 *    - tail = newNode          (Cập nhật tail)
 * 
 * 4. Thao tác duyệt danh sách:
 *    - Xuôi: Bắt đầu từ head, di chuyển bằng next
 *    - Ngược: Bắt đầu từ tail, di chuyển bằng prev
 * 
 * ============================================================================
 */
