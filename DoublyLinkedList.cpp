/*
 * ============================================================================
 * File: DoublyLinkedList.cpp
 * Mô tả: Implementation của lớp DoublyLinkedList (Danh sách liên kết đôi)
 * ============================================================================
 */

#include "DoublyLinkedList.h"

// ============================================================================
// Constructor - Khởi tạo danh sách rỗng
// Ban đầu head và tail đều là nullptr (danh sách chưa có Node nào)
// ============================================================================
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// ============================================================================
// Destructor - Hủy danh sách và giải phóng bộ nhớ
// Duyệt qua từng Node và xóa để tránh rò rỉ bộ nhớ (memory leak)
// ============================================================================
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;  // Lưu lại Node tiếp theo
        delete current;                   // Xóa Node hiện tại
        current = nextNode;               // Di chuyển đến Node tiếp theo
    }
}

// ============================================================================
// Phương thức: isEmpty()
// Mục đích: Kiểm tra danh sách có rỗng không
// Trả về: true nếu rỗng, false nếu có ít nhất 1 Node
// ============================================================================
bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

// ============================================================================
// Phương thức: getSize()
// Mục đích: Lấy số lượng Node trong danh sách
// Trả về: Số nguyên là số lượng khóa học
// ============================================================================
int DoublyLinkedList::getSize() const {
    return size;
}

// ============================================================================
// Phương thức: isIdExist(string id)
// Mục đích: Kiểm tra mã khóa học đã tồn tại trong danh sách chưa
// Tham số: id - Mã khóa học cần kiểm tra
// Trả về: true nếu đã tồn tại, false nếu chưa
// 
// GIẢI THÍCH LOGIC CON TRỎ:
// - Bắt đầu từ head (Node đầu tiên)
// - Duyệt qua từng Node bằng cách di chuyển current = current->next
// - Dừng khi current = nullptr (đã duyệt hết danh sách)
// ============================================================================
bool DoublyLinkedList::isIdExist(string id) const {
    Node* current = head;  // Bắt đầu từ Node đầu tiên
    
    // Duyệt qua toàn bộ danh sách
    while (current != nullptr) {
        // So sánh mã khóa học của Node hiện tại với mã cần tìm
        if (current->data.getCourseId() == id) {
            return true;  // Tìm thấy - mã đã tồn tại
        }
        current = current->next;  // Di chuyển đến Node tiếp theo
    }
    return false;  // Duyệt hết mà không tìm thấy
}

// ============================================================================
// Phương thức: addCourse(Course course)
// Mục đích: Thêm một khóa học mới vào CUỐI danh sách
// Tham số: course - Đối tượng khóa học cần thêm
// 
// GIẢI THÍCH CHI TIẾT LOGIC CON TRỎ KHI THÊM NODE:
// 
// Trường hợp 1: Danh sách đang rỗng (head == nullptr)
//   - Tạo Node mới
//   - head và tail đều trỏ đến Node mới này
//   - Node mới có prev = nullptr và next = nullptr
// 
//   Trước:  head = nullptr, tail = nullptr
//   Sau:    head --> [NewNode] <-- tail
//                    prev=null, next=null
// 
// Trường hợp 2: Danh sách đã có Node
//   - Tạo Node mới
//   - Liên kết Node mới với Node cuối cùng hiện tại (tail)
//   - Cập nhật tail trỏ đến Node mới
// 
//   Trước:  head --> [...] <--> [OldTail] --> nullptr
//                                   ^
//                                  tail
// 
//   Sau:    head --> [...] <--> [OldTail] <--> [NewNode] --> nullptr
//                                                  ^
//                                                 tail
// 
//   Các bước thực hiện:
//   1. newNode->prev = tail  (Node mới trỏ ngược về tail cũ)
//   2. tail->next = newNode  (tail cũ trỏ xuôi đến Node mới)
//   3. tail = newNode        (Cập nhật tail là Node mới)
// ============================================================================
void DoublyLinkedList::addCourse(Course course) {
    // Tạo Node mới chứa dữ liệu khóa học
    Node* newNode = new Node(course);

    if (isEmpty()) {
        // Trường hợp 1: Danh sách rỗng
        // Node mới vừa là đầu vừa là cuối danh sách
        head = newNode;
        tail = newNode;
    } else {
        // Trường hợp 2: Danh sách đã có Node
        // Bước 1: Node mới trỏ ngược (prev) về Node cuối hiện tại
        newNode->prev = tail;
        
        // Bước 2: Node cuối hiện tại trỏ xuôi (next) đến Node mới
        tail->next = newNode;
        
        // Bước 3: Cập nhật tail trỏ đến Node mới (Node mới là cuối)
        tail = newNode;
    }
    
    size++;  // Tăng số lượng Node
}

// ============================================================================
// Phương thức: findById(string id)
// Mục đích: Tìm kiếm khóa học theo mã
// Tham số: id - Mã khóa học cần tìm
// Trả về: Con trỏ đến Node chứa khóa học, nullptr nếu không tìm thấy
// 
// LOGIC: Duyệt từ head đến cuối, so sánh từng mã khóa học
// ============================================================================
Node* DoublyLinkedList::findById(string id) const {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data.getCourseId() == id) {
            return current;  // Tìm thấy - trả về con trỏ đến Node
        }
        current = current->next;
    }
    
    return nullptr;  // Không tìm thấy
}

// ============================================================================
// Phương thức: getMaxStudentCount()
// Mục đích: Tìm số lượng sinh viên đăng ký nhiều nhất
// Trả về: Số lượng sinh viên lớn nhất, -1 nếu danh sách rỗng
// ============================================================================
int DoublyLinkedList::getMaxStudentCount() const {
    if (isEmpty()) return -1;

    int maxCount = head->data.getStudentCount();
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data.getStudentCount() > maxCount) {
            maxCount = current->data.getStudentCount();
        }
        current = current->next;
    }

    return maxCount;
}

// ============================================================================
// Phương thức: getMinStudentCount()
// Mục đích: Tìm số lượng sinh viên đăng ký ít nhất
// Trả về: Số lượng sinh viên nhỏ nhất, -1 nếu danh sách rỗng
// ============================================================================
int DoublyLinkedList::getMinStudentCount() const {
    if (isEmpty()) return -1;

    int minCount = head->data.getStudentCount();
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data.getStudentCount() < minCount) {
            minCount = current->data.getStudentCount();
        }
        current = current->next;
    }

    return minCount;
}

// ============================================================================
// Phương thức: getHead()
// Mục đích: Lấy con trỏ đến Node đầu tiên (để duyệt danh sách từ bên ngoài)
// Trả về: Con trỏ head
// ============================================================================
Node* DoublyLinkedList::getHead() const {
    return head;
}

// ============================================================================
// Phương thức: getTail()
// Mục đích: Lấy con trỏ đến Node cuối cùng (để duyệt ngược danh sách)
// Trả về: Con trỏ tail
// ============================================================================
Node* DoublyLinkedList::getTail() const {
    return tail;
}
