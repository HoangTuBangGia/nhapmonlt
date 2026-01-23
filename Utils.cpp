/*
 * ============================================================================
 * File: Utils.cpp
 * Mô tả: Implementation các hàm tiện ích (Utility Functions)
 * ============================================================================
 */

#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

/*
 * Hàm: clearScreen()
 * Mục đích: Xóa màn hình console để giao diện gọn gàng
 * Ghi chú: Sử dụng lệnh hệ thống phù hợp với hệ điều hành
 *          - Windows: cls
 *          - Linux/Mac: clear
 */
void clearScreen() {
    #ifdef _WIN32
        system("cls");      // Lệnh xóa màn hình trên Windows
    #else
        system("clear");    // Lệnh xóa màn hình trên Linux/Mac
    #endif
}

/*
 * Hàm: pauseScreen()
 * Mục đích: Dừng màn hình để người dùng đọc kết quả trước khi tiếp tục
 */
void pauseScreen() {
    cout << "\n";
    cout << "    +------------------------------------------+\n";
    cout << "    |     Nhan Enter de quay lai menu...       |\n";
    cout << "    +------------------------------------------+\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/*
 * Hàm: printHeader(string title)
 * Mục đích: In tiêu đề cho mỗi chức năng với định dạng đẹp
 * Tham số: title - Tiêu đề cần hiển thị
 */
void printHeader(string title) {
    cout << "\n";
    cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
    cout << "    ║" << setw(32 + title.length()/2) << title 
         << setw(33 - title.length()/2) << "║\n";
    cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
}

/*
 * Hàm: printTableHeader()
 * Mục đích: In tiêu đề bảng với định dạng cột đẹp
 */
void printTableHeader() {
    cout << "    ┌────────────────┬────────────────────────────────┬────────────┬──────────────┐\n";
    cout << "    │" << left << setw(16) << "   MA KHOA HOC" 
         << "│" << setw(32) << "         TEN KHOA HOC" 
         << "│" << setw(12) << " TIN CHI" 
         << "│" << setw(14) << "   SO SV DK" << "│\n";
    cout << "    ├────────────────┼────────────────────────────────┼────────────┼──────────────┤\n";
}

/*
 * Hàm: printTableRow(Course course)
 * Mục đích: In một dòng dữ liệu khóa học trong bảng
 * Tham số: course - Đối tượng khóa học cần hiển thị
 */
void printTableRow(Course course) {
    cout << "    │ " << left << setw(15) << course.getCourseId()
         << "│ " << setw(31) << course.getCourseName()
         << "│" << right << setw(8) << course.getCredits() << "    "
         << "│" << setw(10) << course.getStudentCount() << "    │\n";
}

/*
 * Hàm: printTableFooter()
 * Mục đích: In đường kẻ cuối bảng
 */
void printTableFooter() {
    cout << "    └────────────────┴────────────────────────────────┴────────────┴──────────────┘\n";
}

/*
 * Hàm: printMainMenu()
 * Mục đích: Hiển thị menu chính với giao diện đẹp
 */
void printMainMenu() {
    cout << "\n";
    cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
    cout << "    ║                                                              ║\n";
    cout << "    ║          ★★★ QUAN LY THONG TIN KHOA HOC ★★★                  ║\n";
    cout << "    ║                                                              ║\n";
    cout << "    ║                   Bai tap lon - NMLT                         ║\n";
    cout << "    ║                                                              ║\n";
    cout << "    ╠══════════════════════════════════════════════════════════════╣\n";
    cout << "    ║                                                              ║\n";
    cout << "    ║      [1] Them khoa hoc moi                                   ║\n";
    cout << "    ║      [2] Hien thi tat ca khoa hoc                            ║\n";
    cout << "    ║      [3] Tim kiem theo ma khoa hoc                           ║\n";
    cout << "    ║      [4] Thong ke: Khoa hoc co nhieu SV nhat                 ║\n";
    cout << "    ║      [5] Thong ke: Khoa hoc co it SV nhat                    ║\n";
    cout << "    ║      [0] Thoat chuong trinh                                  ║\n";
    cout << "    ║                                                              ║\n";
    cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    cout << "    >> Nhap lua chon cua ban: ";
}

/*
 * Hàm: showExitMessage()
 * Mục đích: Hiển thị thông báo thoát chương trình
 */
void showExitMessage() {
    clearScreen();
    cout << "\n\n";
    cout << "    ╔══════════════════════════════════════════════════════════════╗\n";
    cout << "    ║                                                              ║\n";
    cout << "    ║               CAM ON BAN DA SU DUNG CHUONG TRINH!            ║\n";
    cout << "    ║                                                              ║\n";
    cout << "    ║                      ★ Tam biet! ★                           ║\n";
    cout << "    ║                                                              ║\n";
    cout << "    ╚══════════════════════════════════════════════════════════════╝\n";
    cout << "\n\n";
}
