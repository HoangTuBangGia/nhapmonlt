/*
 * ============================================================================
 * File: DoublyLinkedList.h
 * Mô tả: Header file định nghĩa lớp DoublyLinkedList (Danh sách liên kết đôi)
 * ============================================================================
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <string>
using namespace std;

/*
 * Lớp DoublyLinkedList quản lý danh sách các khóa học.
 * Sử dụng cấu trúc danh sách liên kết đôi với 2 con trỏ đặc biệt:
 * - head: Trỏ đến Node đầu tiên của danh sách
 * - tail: Trỏ đến Node cuối cùng của danh sách
 * 
 * Ưu điểm của danh sách liên kết đôi so với liên kết đơn:
 * 1. Có thể duyệt cả 2 chiều (xuôi và ngược)
 * 2. Xóa Node dễ dàng hơn (có thể truy cập trực tiếp Node trước)
 * 3. Thêm Node vào cuối danh sách với độ phức tạp O(1) nhờ con trỏ tail
 */
class DoublyLinkedList {
private:
    Node* head;     // Con trỏ trỏ đến Node đầu tiên
    Node* tail;     // Con trỏ trỏ đến Node cuối cùng
    int size;       // Số lượng Node trong danh sách

public:
    // ========================================================================
    // Constructor - Khởi tạo danh sách rỗng
    // ========================================================================
    DoublyLinkedList();

    // ========================================================================
    // Destructor - Hủy danh sách và giải phóng bộ nhớ
    // ========================================================================
    ~DoublyLinkedList();

    // ========================================================================
    // Phương thức: isEmpty()
    // Mục đích: Kiểm tra danh sách có rỗng không
    // ========================================================================
    bool isEmpty() const;

    // ========================================================================
    // Phương thức: getSize()
    // Mục đích: Lấy số lượng Node trong danh sách
    // ========================================================================
    int getSize() const;

    // ========================================================================
    // Phương thức: isIdExist(string id)
    // Mục đích: Kiểm tra mã khóa học đã tồn tại trong danh sách chưa
    // ========================================================================
    bool isIdExist(string id) const;

    // ========================================================================
    // Phương thức: addCourse(Course course)
    // Mục đích: Thêm một khóa học mới vào CUỐI danh sách
    // ========================================================================
    void addCourse(Course course);

    // ========================================================================
    // Phương thức: findById(string id)
    // Mục đích: Tìm kiếm khóa học theo mã
    // ========================================================================
    Node* findById(string id) const;

    // ========================================================================
    // Phương thức: getMaxStudentCount()
    // Mục đích: Tìm số lượng sinh viên đăng ký nhiều nhất
    // ========================================================================
    int getMaxStudentCount() const;

    // ========================================================================
    // Phương thức: getMinStudentCount()
    // Mục đích: Tìm số lượng sinh viên đăng ký ít nhất
    // ========================================================================
    int getMinStudentCount() const;

    // ========================================================================
    // Phương thức: getHead() và getTail()
    // Mục đích: Lấy con trỏ đến Node đầu/cuối để duyệt danh sách từ bên ngoài
    // ========================================================================
    Node* getHead() const;
    Node* getTail() const;
};

#endif // DOUBLYLINKEDLIST_H
