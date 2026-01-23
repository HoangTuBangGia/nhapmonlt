/*
 * ============================================================================
 * File: Course.h
 * Mô tả: Header file định nghĩa lớp Course (Khóa học)
 * ============================================================================
 */

#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

/*
 * Lớp Course đại diện cho một khóa học với các thuộc tính:
 * - courseId: Mã khóa học (duy nhất, không trùng)
 * - courseName: Tên khóa học
 * - credits: Số tín chỉ (phải > 0)
 * - studentCount: Số lượng sinh viên đăng ký (phải >= 0)
 */
class Course {
private:
    string courseId;      // Mã khóa học
    string courseName;    // Tên khóa học
    int credits;          // Số tín chỉ
    int studentCount;     // Số lượng sinh viên đăng ký

public:
    // ========================================================================
    // Constructor mặc định - Khởi tạo khóa học rỗng
    // ========================================================================
    Course();

    // ========================================================================
    // Constructor có tham số - Khởi tạo khóa học với đầy đủ thông tin
    // Tham số:
    //   - id: Mã khóa học
    //   - name: Tên khóa học
    //   - cred: Số tín chỉ
    //   - students: Số sinh viên đăng ký
    // ========================================================================
    Course(string id, string name, int cred, int students);

    // ========================================================================
    // CÁC PHƯƠNG THỨC GETTER - Lấy giá trị thuộc tính
    // ========================================================================
    string getCourseId() const;
    string getCourseName() const;
    int getCredits() const;
    int getStudentCount() const;

    // ========================================================================
    // CÁC PHƯƠNG THỨC SETTER - Thiết lập giá trị thuộc tính
    // ========================================================================
    void setCourseId(string id);
    void setCourseName(string name);
    void setCredits(int cred);
    void setStudentCount(int students);
};

#endif // COURSE_H
