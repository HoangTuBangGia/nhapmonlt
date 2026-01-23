/*
 * ============================================================================
 * File: Course.cpp
 * Mô tả: Implementation của lớp Course (Khóa học)
 * ============================================================================
 */

#include "Course.h"

// ============================================================================
// Constructor mặc định - Khởi tạo khóa học rỗng
// ============================================================================
Course::Course() : courseId(""), courseName(""), credits(0), studentCount(0) {}

// ============================================================================
// Constructor có tham số - Khởi tạo khóa học với đầy đủ thông tin
// ============================================================================
Course::Course(string id, string name, int cred, int students) 
    : courseId(id), courseName(name), credits(cred), studentCount(students) {}

// ============================================================================
// CÁC PHƯƠNG THỨC GETTER - Lấy giá trị thuộc tính
// ============================================================================
string Course::getCourseId() const { 
    return courseId; 
}

string Course::getCourseName() const { 
    return courseName; 
}

int Course::getCredits() const { 
    return credits; 
}

int Course::getStudentCount() const { 
    return studentCount; 
}

// ============================================================================
// CÁC PHƯƠNG THỨC SETTER - Thiết lập giá trị thuộc tính
// ============================================================================
void Course::setCourseId(string id) { 
    courseId = id; 
}

void Course::setCourseName(string name) { 
    courseName = name; 
}

void Course::setCredits(int cred) { 
    credits = cred; 
}

void Course::setStudentCount(int students) { 
    studentCount = students; 
}
