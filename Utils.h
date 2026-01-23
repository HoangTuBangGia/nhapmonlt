/*
 * ============================================================================
 * File: Utils.h
 * Mô tả: Header file cho các hàm tiện ích (Utility Functions)
 * ============================================================================
 */

#ifndef UTILS_H
#define UTILS_H

#include "Course.h"
#include <string>
using namespace std;

/*
 * Hàm: clearScreen()
 * Mục đích: Xóa màn hình console để giao diện gọn gàng
 */
void clearScreen();

/*
 * Hàm: pauseScreen()
 * Mục đích: Dừng màn hình để người dùng đọc kết quả trước khi tiếp tục
 */
void pauseScreen();

/*
 * Hàm: printHeader(string title)
 * Mục đích: In tiêu đề cho mỗi chức năng với định dạng đẹp
 */
void printHeader(string title);

/*
 * Hàm: printTableHeader()
 * Mục đích: In tiêu đề bảng với định dạng cột đẹp
 */
void printTableHeader();

/*
 * Hàm: printTableRow(Course course)
 * Mục đích: In một dòng dữ liệu khóa học trong bảng
 */
void printTableRow(Course course);

/*
 * Hàm: printTableFooter()
 * Mục đích: In đường kẻ cuối bảng
 */
void printTableFooter();

/*
 * Hàm: printMainMenu()
 * Mục đích: Hiển thị menu chính với giao diện đẹp
 */
void printMainMenu();

/*
 * Hàm: showExitMessage()
 * Mục đích: Hiển thị thông báo thoát chương trình
 */
void showExitMessage();

#endif // UTILS_H
