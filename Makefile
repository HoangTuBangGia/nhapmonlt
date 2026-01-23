CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = QuanLyKhoaHoc

SOURCES = main.cpp Course.cpp DoublyLinkedList.cpp Utils.cpp

OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = Course.h Node.h DoublyLinkedList.h Utils.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "====================================="
	@echo "  Bien dich thanh cong!"
	@echo "  Chay chuong trinh: ./$(TARGET)"
	@echo "====================================="

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@echo "Da xoa cac file object (.o)."

cleanall:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Da xoa tat ca file bien dich."

rebuild: cleanall all

run: $(TARGET)
	./$(TARGET)

exec:
	@if [ -f $(TARGET) ]; then \
		./$(TARGET); \
	else \
		echo "[!] Chua co file thuc thi. Hay chay 'make' truoc."; \
	fi

.PHONY: all clean cleanall rebuild run exec
