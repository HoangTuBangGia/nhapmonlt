/*
 * ============================================================================
 * File: Node.h
 * Mô tả: Header file định nghĩa cấu trúc Node cho Danh sách liên kết đôi
 * ============================================================================
 */

#ifndef NODE_H
#define NODE_H

#include "Course.h"

/*
 * Struct Node là một nút trong danh sách liên kết đôi.
 * 
 * GIẢI THÍCH CHI TIẾT VỀ CON TRỎ PREV VÀ NEXT:
 * 
 * Trong danh sách liên kết đôi, mỗi Node có 2 con trỏ:
 * 
 *   [prev] <-- [DATA] --> [next]
 * 
 * - prev (previous): Con trỏ trỏ đến Node TRƯỚC đó trong danh sách.
 *   + Nếu Node là Node đầu tiên (head), prev = nullptr (không có Node trước).
 *   + Dùng để duyệt ngược từ cuối về đầu danh sách.
 * 
 * - next: Con trỏ trỏ đến Node SAU đó trong danh sách.
 *   + Nếu Node là Node cuối cùng (tail), next = nullptr (không có Node sau).
 *   + Dùng để duyệt xuôi từ đầu đến cuối danh sách.
 * 
 * Ví dụ minh họa danh sách 3 Node:
 * 
 *   nullptr <-- [Node1] <--> [Node2] <--> [Node3] --> nullptr
 *                 ^                          ^
 *                head                       tail
 * 
 *   Node1.prev = nullptr    Node1.next = &Node2
 *   Node2.prev = &Node1     Node2.next = &Node3
 *   Node3.prev = &Node2     Node3.next = nullptr
 */
struct Node {
    Course data;    // Dữ liệu: Đối tượng khóa học
    Node* prev;     // Con trỏ trỏ đến Node trước (previous)
    Node* next;     // Con trỏ trỏ đến Node sau (next)

    // Constructor của Node - Khởi tạo Node mới với dữ liệu khóa học
    // Ban đầu prev và next đều là nullptr (chưa liên kết với Node nào)
    Node(Course course) : data(course), prev(nullptr), next(nullptr) {}
};

#endif // NODE_H
